#!/usr/bin/env node

var fs = require("fs");
var args = fs.readFileSync(process.argv[2], "utf8");
var changed = false;

var jsonPath = null;
var json = null;
var keyValReplacementString = args.split(" ");
keyValReplacementString.forEach(function(i) {
  var keyVal = i.split("=");
  if (!keyVal[1]) {
    return;
  } else if (keyVal[0].indexOf("path") == 0) {
    jsonPath = stripQuotes(keyVal[1]);
  }
});

if (jsonPath) {
  json = JSON.parse(fs.readFileSync(jsonPath, "utf8"));

  keyValReplacementString.forEach(function(i) {
    var keyVal = i.split("=");
    if (keyVal[0].indexOf("path") == -1 && json[keyVal[0]]) {
      json[keyVal[0]] = stripQuotes(keyVal[1]);
    }
  });

  fs.writeFileSync(jsonPath, JSON.stringify(json, null, 2));
  changed = true;
}

function stripQuotes(text) {
  return text.replace(/["']*([^'"]+)['"]*"/g, "$1");
}

console.log(JSON.stringify({ changed: changed }));