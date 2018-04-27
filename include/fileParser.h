//
//  main.c
//  anime_notifier
//
//  Created by Ziyad Kalati on 2018-04-23.
//  Copyright © 2018 Ziyad Kalati. All rights reserved.
//

#ifndef fileParser_h
#define fileParser_h

int searchName(FILE *htmlPage, char *showName);

int checkDate(FILE *htmlPage);

FILE *filePointerScroll(FILE *fp, char *input, char *scrollString);

int compare(char *lineInput, char *showName);

void cleanString(char *input);

#endif /* fileParser_h */
