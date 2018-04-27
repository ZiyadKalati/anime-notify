//
//  main.c
//  anime_notifier
//
//  Created by Ziyad Kalati on 2018-04-23.
//  Copyright © 2018 Ziyad Kalati. All rights reserved.
//

#define ANIME_NAME 50
#define TIME_STRING 25
#define YEAR_LENGTH 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "readFile.h"
#include "fileParser.h"

int main(int argc, const char * argv[])
{
    char *url = (char *)argv[1];
    FILE *html = OpenFile(argv[2], "r");

    char animeName[ANIME_NAME];
    strcpy(animeName, argv[3]);

    char relPath[] = "/assets/tempData.txt";
    char *absPath = (char *)malloc(sizeof(char) * (strlen(argv[4]) + strlen(relPath) + 1) );
    strcpy(absPath, argv[4]);
    strcat(absPath, relPath);
    FILE *newAnime = OpenFile(absPath, "a");

    int year = 0;
    char processedName[ANIME_NAME];
    strcpy( processedName, animeName );
    cleanString( processedName );
    int found = searchName( html, processedName );
    if ( found )
        year = checkDate( html );

    time_t seconds;
    seconds = time(NULL);
    char *date = asctime( localtime( &seconds ) );
    char currentYear[YEAR_LENGTH];
    long endOfString = strlen( date );
    char *cp = date + endOfString;
    while ( !isdigit( *cp ))
        cp--;
    for ( int ctr = 0; ctr < YEAR_LENGTH; ctr++, cp-- )
        currentYear[YEAR_LENGTH - ctr - 1] = *cp;

    if ( atoi( currentYear ) == year )
        AppendFile( newAnime, animeName, url );

    fclose(html);
    fclose(newAnime);

    return 0;
}
