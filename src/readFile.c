//
//  main.c
//  anime_notifier
//
//  Created by Ziyad Kalati on 2018-04-23.
//  Copyright © 2018 Ziyad Kalati. All rights reserved.
//

#include "readFile.h"

/** Attempts to open a file in the path specified in one of the arguments.
 *@pre String pointers should not be NULL
 *@param fileName is the path to the file to open
 *@param mode to open file in
 *@return A file pointer to the opened file
 **/
FILE *OpenFile(const char *fileName, char *mode)
{
    FILE *fp = fopen(fileName, mode);

    /* Check if file opened successfully */
    if (fp == NULL)
        fprintf(stdout, "%s has not been passed in.\n", fileName);

    return fp;
}

/** Appends the name of the anime and the url where it was found to temporary text file.
 *@pre File should be opened and char pointers should not be NULL
 *@param fileName file pointer to opened file in append mode
 *@param showName is the name of the anime to notify the otaku about
 *@param url is the link to the page where the anime was found
 **/
void AppendFile(FILE *fileName, char *showName, char *url)
{
    fprintf( fileName, "%s|", showName );
    fprintf( fileName, "%s\n", url );
}
