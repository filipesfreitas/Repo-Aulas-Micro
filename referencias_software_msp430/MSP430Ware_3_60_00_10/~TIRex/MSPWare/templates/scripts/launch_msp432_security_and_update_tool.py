#!/usr/bin/env python
#
# Launch MSP432 Security and Update Tool by running CCS eclipse JRE

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

os.chdir(os.path.join('..', '..', '..', '..', 'msp432_security_and_update_tool', 'MSP432SecurityAndUpdateTool_1.00.00.00', 'MSP432SecurityAndUpdateTool'))
subprocess.call(['java', '-Djava.library.path=.', '-jar', 'MSP432SecurityAndUpdateTool.jar'])
