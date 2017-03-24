#!/usr/bin/env python
#
# Launch USB HID Demo by running CCS eclipse JRE

import os
import sys
import subprocess

if hasattr(sys, 'frozen'):
    cur_dir = os.path.abspath(sys.executable)
else:
    cur_dir = os.path.abspath(__file__)
cur_dir = os.path.dirname(cur_dir)
os.chdir(cur_dir)

if sys.platform == 'win32':
    folder_name = 'Windows'
elif sys.platform == 'darwin':
    folder_name = 'Mac'
else:
    folder_name = 'Linux'

os.chdir(os.path.join('..', '..', '..', '..', 'usblib430', 'Host_USB_Software', 'Java_HID_Demo', folder_name))
subprocess.call(['java', '-Djava.library.path=.', '-jar', 'HidDemo.jar'])
