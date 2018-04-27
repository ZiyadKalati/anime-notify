//
//  main.c
//  myanimelist_text_parser
//
//  Created by Ziyad Moustafa on 2018-04-22.
//  Copyright © 2018 Ziyad Moustafa. All rights reserved.
//
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
    // insert code here...

    char testing[] = "This is a test.";

    cleanString(testing);
    printf("%s\n", testing);

    FILE *html = OpenFile(argv[1], "r");
    int found = searchName(html, "steinsgatespecial");
    printf("%d\n", found);

    int year = checkDate(html);
    printf("%d\n", year);

    FILE *output = OpenFile("assets/ouputData.txt", "a+");
    AppendFile(output, "Steins;Gate ", "https://\n");
    AppendFile(output, "Steins;Gate ", "https://\n");

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
    printf("%s", date);
    printf("%d\n", atoi( currentYear ) );


    return 0;
}
