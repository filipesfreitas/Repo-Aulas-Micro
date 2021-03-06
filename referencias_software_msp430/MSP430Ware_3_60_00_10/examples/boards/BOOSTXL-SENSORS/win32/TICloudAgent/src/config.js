/*jslint node: true */
"use strict";

// Object for storing global configuration

var fs, path, configFile, loadersRoot;

fs = require("fs");
path = require("path");

var configFilePath = path.join(__dirname, "..", "config.json"); // it should be one level above us
configFile = JSON.parse(fs.readFileSync(configFilePath, "utf8"));

if (path.resolve(configFile.userDataRoot) !== configFile.userDataRoot) {
	// if it is not an absolute path; we are doing an relocatable offline install so we turn it into a absolute path
	configFile.userDataRoot = path.resolve(path.join(__dirname, configFile.userDataRoot));
}

loadersRoot = path.join(configFile.userDataRoot, "loaders");
configFile.loadersRoot = loadersRoot;

module.exports = configFile;