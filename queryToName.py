"""
    Reverse of nameToQuery.py
    This script removes any characters that used in a search query string in a url
    and replaces it with the appropriate sequence of characters to convert back to an
    ordinary anime title.
    This script converts only one query string, not the whole list.
"""

import sys
import os

if len(sys.argv) < 1:
    quit()

anime = sys.argv[1]

anime = anime.replace("%20", " ")
anime = anime.replace("%3A", ":")
anime = anime.replace("%3B", ";")
anime = anime.replace("%3D", "=")
anime = anime.replace("%3F", "?")
anime = anime.replace("?q=", "")


pathToHere = os.path.dirname(os.path.realpath(__file__)) + "/assets/"
fo = open(pathToHere+"animeName.txt", "w")
fo.writelines(anime)

fo.close()
