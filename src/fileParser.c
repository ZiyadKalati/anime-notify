//
//  main.c
//  anime_notifier
//
//  Created by Ziyad Kalati on 2018-04-23.
//  Copyright © 2018 Ziyad Kalati. All rights reserved.
//

#define INPUT_SIZE 100
#define YEAR_LENGTH 4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "fileParser.h"

/** Searches for the name of the show that was passed in.
 *@pre File should be opened and char pointer should not be NULL
 *@param htmlPage is a file pointer to an open file
 *@param showName is the name of the anime to be searched for
 *@return 1 if search was successful
 *        0 if search was unsuccessful
 **/
int searchName(FILE *htmlPage, char *showName)
{
    char *lineInput = (char *)malloc( sizeof(char) * INPUT_SIZE );
    int found = 0;

    while ( fgets( lineInput, INPUT_SIZE, htmlPage ) )
    {
        if ( !isalpha( lineInput[0] ) )
            continue;

        cleanString( lineInput );
        break;
    }

    if ( compare( lineInput, showName ) )
        return found = 1;

    htmlPage = filePointerScroll(htmlPage, lineInput, "English:");
    cleanString( lineInput );
    if ( compare( lineInput, showName ) )
        return found = 1;

    htmlPage = filePointerScroll( htmlPage, lineInput, "Synonyms:" );
    cleanString( lineInput );
    if ( compare( lineInput, showName ) )
        return found = 1;

    return found;
}

/** Finds and compares the year the anime was first aired with the current calendar year.
 *@pre File should be opened
 *@param htmlPage is a file pointer to an open file
 *@return The year the anime was aired
 **/
int checkDate(FILE *htmlPage)
{
    char *lineInput = (char *)malloc( sizeof(char) * INPUT_SIZE );
    char year[YEAR_LENGTH];

    htmlPage = filePointerScroll(htmlPage, lineInput, "Aired:");
    long endOfString = strlen( lineInput );
    char *cp = lineInput + endOfString;
    while ( !isdigit( *cp ))
        cp--;

    for ( int ctr = 0; ctr < YEAR_LENGTH; ctr++, cp-- )
        year[YEAR_LENGTH - ctr - 1] = *cp;

    return atoi( year );
}

/** This function moves the file pointer further down the file to where a substring has been found.
 *@pre Both string pointers should not be NULL and file should be opened
 *@param fp is a file pointer to an open file
 *@param input is a string potentially containing the desired substring
 *@param scrollString is a substring to be matched
 *@return A file pointer that has been scrolled to appropriate position
 **/
FILE *filePointerScroll(FILE *fp, char *input, char *scrollString)
{
    if ( input == NULL || scrollString == NULL )
        return 0;

    while ( fgets( input, INPUT_SIZE, fp ) )
    {
        if ( !compare( input, scrollString ) )
            continue;

        break;
    }

    return fp;
}

/** This function determines if the string read from the file contains a substring that is identical to the name of the anime begin searched for.
 *@pre Both pointers should not be NULL
 *@param lineInput is a string potentially containing the desired substring
 *@param animeName is a substring to be matched
 *@return 1 if substring was found
         0 if substring was not found
 **/
int compare(char *lineInput, char *animeName)
{
    if ( lineInput == NULL || animeName == NULL )
        return 0;

    if ( strstr(lineInput, animeName) )
        return 1;
    else
        return 0;
}

/** This function removes any non-alphabetic character from the string and lower cases the string to make comparisons of strings much easier.
 *@pre Char pointer should not be NULL
 *@post The string pointed to will be lower case and have only alphabetic characters
 *@param input is a pointer to string to be cleaned
 **/
void cleanString(char *input)
{
    if ( input == NULL )
        return;

    int ctr = 0;

    for ( ctr = 0; (size_t)ctr < strlen( input ); ctr++ )
        input[ctr] = tolower( input[ctr] );

    size_t inputLength = strlen( input );
    char noWhite[inputLength];
    char *nwp = noWhite;
    for ( ctr = 0; (size_t)ctr < inputLength; ctr++ )
        if ( isalpha( input[ctr] ) )
        {
            *nwp = input[ctr];
            nwp++;
        }

    *nwp= '\0';
    strcpy( input, noWhite );
}
