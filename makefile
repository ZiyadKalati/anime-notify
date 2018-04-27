# Flags
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic -g

#Directories where the header files reside
INCLUDES = -Iinclude

#Other directories
ABSPATH = /Users/ziyadmoustafa/Documents/anime_notify/anime_notify
BINDIR = $(ABSPATH)/bin/
SRCDIR = $(ABSPATH)/src/
OBJDIR = $(ABSPATH)/obj/

SOURCE = $(wildcard *.c)
OBJS = $(OBJDIR)fileParser.o $(OBJDIR)readFile.o

#The names of the binary programs that will be produced
PROGNAME = $(BINDIR)parser
PROGTEST = $(BINDIR)parserTest

all: test program

program: $(OBJS) $(OBJDIR)main.o
	$(CC) $(OBJS) $(OBJDIR)main.o -o $(PROGNAME)

test: $(OBJS) $(OBJDIR)testMain.o
	$(CC) $(OBJS) $(OBJDIR)testMain.o -o $(PROGTEST)

#Below here are targets for *.o
$(OBJDIR)fileParser.o: $(SRCDIR)fileParser.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)fileParser.c -o $@

$(OBJDIR)readFile.o: $(SRCDIR)readFile.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)readFile.c -o $@

$(OBJDIR)main.o: $(SRCDIR)main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)main.c -o $@

$(OBJDIR)testMain.o: $(SRCDIR)testMain.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRCDIR)testMain.c -o $@

clean:
	@rm $(OBJDIR)*.o $(PROGNAME) $(PROGTEST)

project:
	mkdir src obj bin assets docs lib include
	touch README ./src/main.c
