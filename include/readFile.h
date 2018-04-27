//
//  main.c
//  anime_notifier
//
//  Created by Ziyad Kalati on 2018-04-23.
//  Copyright © 2018 Ziyad Kalati. All rights reserved.
//

#ifndef readFile_h
#define readFile_h

#include <stdio.h>

FILE *OpenFile(const char *fileName, char *mode);

void AppendFile(FILE *fileName, char *showName, char *url);

#endif /* readFile_h */
