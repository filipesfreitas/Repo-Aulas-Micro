#!/usr/bin/env python
#
# Launch MSP-EXP432P401R OOB Experience GUI

import os
import sys
import subprocess
import platform

if hasattr(sys, 'frozen'):
    cur_dir = os.path.abspath(sys.executable)
else:
    cur_dir = os.path.abspath(__file__)
cur_dir = os.path.dirname(cur_dir)
os.chdir(cur_dir)

if sys.platform == 'win32':
    folder_name = 'windows'
elif sys.platform == 'darwin':
    folder_name = 'mac_os'
else:
    folder_name = 'linux'

arch = platform.architecture()[0]
if arch == '64bit':
    arch = '64-bit'
else:
    arch = '32-bit'

if folder_name == 'linux':
    os.chdir(os.path.join('..', '..', '..', '..', 'examples', 'boards', 'MSP-EXP432P401R',
                          'MSP-EXP432P401R_Software_Examples', 'GUI', 'Binary', arch,
                          'OutOfBox_MSP432P401R_GUI'))
else:
    os.chdir(os.path.join('..', '..', '..', '..', 'examples', 'boards', 'MSP-EXP432P401R',
                          'MSP-EXP432P401R_Software_Examples', 'GUI', 'Binary',
                          'OutOfBox_MSP432P401R_GUI'))
subprocess.call(['./OutOfBox_MSP432P401R_GUI'])
