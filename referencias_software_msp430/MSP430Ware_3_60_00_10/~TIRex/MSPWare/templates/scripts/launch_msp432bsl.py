#!/usr/bin/env python
#
# Launch MSP432 BSL Updater

import os
import sys
import subprocess

if hasattr(sys, 'frozen'):
    cur_dir = os.path.abspath(sys.executable)
else:
    cur_dir = os.path.abspath(__file__)
cur_dir = os.path.dirname(cur_dir)
os.chdir(cur_dir)

os.chdir(os.path.join('..', '..', '..', '..', 'boot_loader'))

if sys.platform == 'win32':
    subprocess.call(['start', 'cmd', '/K', 'Program_MSP432_BSL.bat'], shell=True)
elif sys.platform == 'darwin':
    subprocess.call(['open', '-a', 'Terminal.app', './Program_MSP432_BSL.command'])
else:
    subprocess.call(['xterm', '-e', os.path.join(os.getcwd(), 'Program_MSP432_BSL.sh')], shell=False)
