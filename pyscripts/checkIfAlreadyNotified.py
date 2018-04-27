"""
    This script checks if the new animes that have been found were not already reported to the
    otaku. If so, then they are removed from the list in the text file "assets/tempData.txt".
    The previously reported animes are stored in "assets/outputData.txt" and this is the file
    used to check that the list in "assets/tempData.txt" contains different titles.
"""

import os
pathToHere = os.path.dirname(os.path.dirname(os.path.realpath(__file__))) + "/assets/"

fo = open(pathToHere+"outputData.txt", "r")
fn = open(pathToHere+"tempData.txt", "r")

oldData = fo.readlines()
newData = fn.readlines()

oldLinks = []
newLinks = []
retainedLines = []

for line in oldData:
    temp = line.split()
    oldLinks.append(temp[-1])

for line in newData:
    temp = line.split()
    newLinks.append(temp[-1])

trulyNew = [x for x in newLinks if x not in oldLinks]

for line in newData:
    for link in trulyNew:
        if link in line:
            retainedLines.append(line)

fn = open(pathToHere+"tempData.txt", "w")
fn.writelines(retainedLines)

fo.close()
fn.close()
