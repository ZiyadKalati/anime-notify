"""
    The reverse of queryToName.py
    This script removes any characters that cannot be used in a search query string in a
    url and replaces it with the appropriate sequence of characters.
    The query strings created in this script will be catenated to the url of the website
    being scraped from to get the full url.
"""

import os
pathToHere = os.path.dirname(os.path.dirname(os.path.realpath(__file__))) + "/assets/"

f = open(pathToHere+"anime_list.txt", 'r')
names = f.readlines()

queries = []
for name in names:
    name = name.replace(" ", "%20")
    name = name.replace(":", "%3A")
    name = name.replace(";", "%3B")
    name = name.replace("=", "%3D")
    name = name.replace("?", "%3F")

    queries.append("?q="+name)

fo = open(pathToHere+"queries.txt", "w")
fo.writelines(queries)

f.close()
fo.close()
