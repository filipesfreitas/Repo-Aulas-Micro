"""
 Copyright (c) 2012, Texas Instruments Incorporated
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 *  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 *  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 *  Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
"""

"""
BatchFirmwareUpgrader provides a batch front end to python-msp430-tools.  This does not modify anything
in python-msp430-tools.  Because of this, we still create command line parser classes
used by the command line even though they are not used by the script.  They are just
required to exist by python-msp430-tools.

Reason for not modifying python-msp430-tools is to allow independent updates of the command
line version without requiring any changes.   

USAGE: python BatchFirmwareUpgrader.py <path_to_file.txt>

This is not part of the production release, but to build the exe do the following:
    rm -rf build dist *.spec
    rm *.pyc python-msp430-tools/*/*.pyc python-msp430-tools/*/*/*.pyc 

    C:/Python27/python.exe c:/pyinstaller-2.0/pyinstaller.py --paths=./python-msp430-tools --onefile BatchFirmwareUpgrader.py 
"""
import sys
import os
import struct
import logging
import time
import pkgutil
import traceback
import logging
import msp430.target
from cStringIO import StringIO
from msp430 import memory
from logging import Handler
from msp430.bsl5 import bsl5
from msp430.bsl5 import hid_1
#from msp430.bsl5 import hid
if sys.platform == 'win32':
    from pywinusb import hid as HID


class BatchFirmwareUpgrader(object):

    def __init__(self):
        # Our access to the command line msp430 flasher utility
        self.bsl5Target = msp430.bsl5.hid_1.HIDBSL5Target();
        self.logger = logging.getLogger('BSL')
        self.logger.setLevel(logging.INFO)
        # Create a console file handler
        ch = logging.StreamHandler()
        ch.setLevel(logging.INFO)
        ch_formatter = logging.Formatter('%(levelname)s - %(message)s')
        ch.setFormatter(ch_formatter)
        self.logger.addHandler(ch)

    def doLoad(self,filename):
        self.logger.info("In doLoad...")
        """
        Load the file from disk and flash the device.
        """
        self.bsl5Target.create_option_parser()
        self.bsl5Target.add_extra_options()
        self.bsl5Target.parse_args()
 
        data = msp430.memory.load(filename, format=self.bsl5Target.options.input_format)
        self.open_connection()
        self.bsl5Target.program_file(data)
 
        #Trigger a software reset
        self.bsl5Target.reset()
 
        # output uploaded data
        if self.bsl5Target.upload_data is not None:
            memory.save(self.upload_data, self.output, self.options.output_format)
 
 
        if self.bsl5Target.options.do_wait:
            raw_input()
 
        # Wait for the just programmed device to reset
        time.sleep(1)
 
        self.lookForDevice()

    def open_connection(self):
        """
        Opens the device and download the RAM BSL
        """
 
        self.bsl5Target.logger = logging.getLogger('BSL')
        self.bsl5Target.open(self.bsl5Target.options.device)
        # only fast mode supported by USB boot loader
        self.bsl5Target.use_fast_mode = True
        self.bsl5Target.buffer_size = 48
 
        self.bsl5Target.logger.info("Mass erase...")
        try:
            #Mass erase initiated due to incorrect password
           self.bsl5Target.BSL_RX_PASSWORD('\xff'*30 + '\0'*2)
        except bsl5.BSL5Error:
            pass # it will fail - that is our intention to trigger the erase
 
        time.sleep(1)
 
        # after erase, unlock device
        self.bsl5Target.BSL_RX_PASSWORD('\xff'*32)
 
        # download full BSL
        self.logger.info('Download full BSL...\n')
        bsl_version_expected = (0x00, 0x07, 0x08, 0x38)
 
        basedir = os.path.dirname(sys.argv[0])
        absbasedir = os.path.realpath(basedir)

        if sys.platform == 'win32' or sys.platform == 'cygwin':
            full_bsl_txt = open(os.path.join(absbasedir, 'python-msp430-tools\\msp430\\bsl5\\RAM_BSL.00.07.88.38.txt'), 'rb').read()        
        else:
            full_bsl_txt = open(os.path.join(absbasedir, 'python-msp430-tools/msp430/bsl5/RAM_BSL.00.07.88.38.txt'), 'rb').read()
 
        full_bsl = msp430.memory.load('BSL', StringIO(full_bsl_txt), format='titext')
 
        self.bsl5Target.program_file(full_bsl, quiet=False)
        #loading the start of BSL code so that BSL version and connection check can pass in
        #the if statement below.
        self.bsl5Target.BSL_LOAD_PC(0x2504)  
 
        # must re-initialize communication, BSL or USB system needs some time
        # to be ready
        self.logger.info("Waiting for BSL...")
        time.sleep(3)
 
        self.bsl5Target.close()
        self.logger.info('BSL Closed...')
 
        self.bsl5Target.open(self.bsl5Target.options.device)
 
        # checking version, this is also a connection check
        # This does not work in Linux. os.read(self.hid_device, 64) will hang forever
        # waiting for a response...
        if sys.platform == 'win32' or sys.platform == 'cygwin':
            bsl_version = self.bsl5Target.BSL_VERSION()
            if bsl_version_expected != bsl_version_expected:
                self.logger.error("BSL version mismatch (continuing anyway)")
            else:
                self.logger.info("BSL version OK")


    def lookForDevice(self, showMessage='No'):
        """
        Looks for a device in BSL mode, program exits if none found
        """
        global file
  
        all_devices = []
        if sys.platform == 'win32' or sys.platform == 'cygwin':
            filter = HID.HidDeviceFilter(vendor_id = 0x2047, product_id = 0x0200)
            all_devices = filter.get_devices()
  
        if all_devices.__len__() > 0:
            if showMessage == 'Yes':
                self.logger.info("Device found")
        else:
            if showMessage == 'Yes':
                self.logger.error("USB VID:PID 2047:0200 not found (maybe device not in BSL mode?)")
                self.logger.error("Please set device in BSL mode")
                sys.exit(1)


   # - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    def main(self, file):
        self.lookForDevice('Yes')
        self.doLoad(file)

#  Startup...

if __name__ == '__main__':
    #file = "hid_bridge__1_00_00_00__MSP_EXP430PGMR.txt"
    # Must provide the txt file to load as the only argument to the script
    if len(sys.argv) == 2:
        file = sys.argv[1]
    else:
        print("Usage ERROR: Must provide txt file to load on the command line")
        sys.exit(1)

    t = BatchFirmwareUpgrader()
    t.main(file)
    sys.exit(0)

