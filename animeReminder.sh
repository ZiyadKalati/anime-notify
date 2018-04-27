#!/bin/sh
PATH=/usr/local/bin:/usr/local/sbin:~/bin:/usr/bin:/bin:/usr/sbin:/sbin:/anaconda3/bin
pathToHere=$(dirname "$0")

python3 $pathToHere/nameToQuery.py
while read -r query
do
    siteUrl="https://myanimelist.net/search/all"
    fullUrl=$siteUrl$query
    curl --location $fullUrl > $pathToHere/assets/queryPage.html
    lynx -dump $pathToHere/assets/queryPage.html > $pathToHere/assets/queryPage.txt
    grep "https://myanimelist.net/anime/[0-9]\+/.*" $pathToHere/assets/queryPage.txt | grep -v "https://myanimelist.net/anime/[0-9]\+/.*/" | cut -c7- | sort -u >  $pathToHere/assets/cleanLinks.txt
    python3 $pathToHere/queryToName.py $query
    animeName=$(<$pathToHere/assets/animeName.txt)

    while read url
    do
        curl --location $url > $pathToHere/assets/queryPage.html
        lynx -dump $pathToHere/assets/queryPage.html > $pathToHere/assets/animePage.txt
        $pathToHere/bin/parser "$url" $pathToHere/assets/animePage.txt "$animeName" "$pathToHere"
        sleep 3
    done < $pathToHere/assets/cleanLinks.txt
done < $pathToHere/assets/queries.txt

cat $pathToHere/assets/tempData.txt | sort -u > $pathToHere/assets/temptemp.txt
cp $pathToHere/assets/temptemp.txt $pathToHere/assets/tempData.txt
rm $pathToHere/assets/temptemp.txt

python3 $pathToHere/checkIfAlreadyNotified.py
python3 $pathToHere/sendNotification.py

cat $pathToHere/assets/tempData.txt >> $pathToHere/assets/outputData.txt
rm $pathToHere/assets/tempData.txt
rm $pathToHere/assets/queryPage.html $pathToHere/assets/queries.txt $pathToHere/assets/cleanLinks.txt $pathToHere/assets/queryPage.txt $pathToHere/assets/animeName.txt $pathToHere/assets/animePage.txt
