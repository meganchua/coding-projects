#############################################################
#Kosuke Takahashi & Megan Chua
#cssc0452 & cssc0453
#CS 530, Spring 2019
#Assignment #1, Hexadecimal File Dump Program
#Makefile
#############################################################

CC = gcc

CFLAGS = -I

HEADERS = hexDump.h

default: hexDump

hexDump.o: hexDump.c $(HEADERS)
    gcc -c hexDump.c -o hexDump.o

hexDump: hexDump.o
    gcc hexDump.o -o hexDump

xbd: hexDump.o
    $(CC) -o hexDump hexDump.o

hex: hexDump.c
    xbd <filename>

binary: hexDump.c
    xbd -b <filename>

clean:
    -rm -f hexDump.o
    -rm -f program
