#!/bin/sh
# this script prints Cullen's 5 prev. commit hashes
git log -n 5 --format="%H" --author=Cullen

