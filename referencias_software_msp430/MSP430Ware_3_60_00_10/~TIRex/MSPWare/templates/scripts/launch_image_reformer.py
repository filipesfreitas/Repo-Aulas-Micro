#!/usr/bin/env python
#
# Launch Image Reformer GUI by running CCS eclipse JRE

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
    folder_name = 'windows'
elif sys.platform == 'darwin':
    folder_name = 'mac_os'
else:
    folder_name = 'linux'

os.chdir(os.path.join('..', '..', '..', '..', 'grlib', 'utils', 'image-reformer'))
subprocess.call(['java', '-jar', 'image_Reformer.jar'])
