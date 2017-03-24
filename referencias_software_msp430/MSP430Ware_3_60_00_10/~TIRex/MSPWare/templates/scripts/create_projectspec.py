#!/usr/bin/env python
#
# Script to generate a projectspec given the path to an example and the device

import sys
import os
from shutil import copyfile
import xml.etree.ElementTree as ET


def main():

    name = sys.argv[1]
    device = sys.argv[2]
    root = sys.argv[3]

    # Find location to save projectspec, delete if already exists
    if hasattr(sys, 'frozen'):
        cur_dir = sys.executable
    else:
        cur_dir = __file__
    cur_dir = os.path.dirname(cur_dir)
    os.chdir(cur_dir)

    if os.name == 'nt':
        projectspec = os.path.join(cur_dir, "projects", name + "_" + device + ".projectspec")
    else:
        # Non-windows OS can write to /tmp directory without root access
        projectspec = os.path.join('/tmp', "projects", name + "_" + device + ".projectspec")
        try:
            os.mkdir(os.path.dirname(projectspec))
        except OSError:
            pass

    if os.path.isfile(projectspec):
        os.remove(projectspec)

    if 'MSP432' in device.upper():
        msp432_dir = os.path.join(os.path.dirname(projectspec), name + '_' + device)
        try:
            os.mkdir(msp432_dir)
        except OSError:
            pass

    example_root = os.path.join("..", "..", "..", "..", "examples", "devices", root, name)

    if os.path.isfile(example_root):
        files = [os.path.abspath(os.path.join(os.path.curdir, example_root))]
    else:
        files = []
        for filename in os.listdir(example_root):
            files.append(os.path.abspath(os.path.join(example_root, filename)))

    root = ET.Element("projectSpec")
    project = ET.SubElement(root, "project")
    project.set("device", device)
    project.set("name", name)

    for filename in files:
        # Don't add the file if it's for a different compiler
        if "ewarm" in filename or "keil" in filename or "gcc" in filename:
            continue
        if filename.endswith(".cmd"):
            name, ext = os.path.splitext(filename)
            project.set("linkerCommandFile", name)
        project_file = ET.SubElement(project, "file")
        project_file.set("action", "copy")
        if 'MSP432' in device.upper():
            if "system_" in filename:
                new_system = os.path.join(msp432_dir, 'system_{}.c'.format(device.lower()))
                copyfile(filename, new_system)
                new_system = './{}_{}/system_{}.c'.format(name, device, device.lower())
                project_file.set('path', new_system)
                project_file.set("overwriteExisting", "true")
            elif 'startup_' in filename:
                new_startup = os.path.join(msp432_dir, 'startup_{}_ccs.c'.format(device.lower()))
                copyfile(filename, new_startup)
                new_startup = './{}_{}/startup_{}_ccs.c'.format(name, device, device.lower())
                project_file.set('path', new_startup)
                project_file.set("overwriteExisting", "true")
            else:
                project_file.set("path", filename)
        else:
            project_file.set("path", filename)

    tree = ET.ElementTree(root)
    tree.write(projectspec)


if __name__ == '__main__':
    main()
