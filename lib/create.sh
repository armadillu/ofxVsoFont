#!/bin/bash

# create the object files

gcc -ansi -pedantic -g -O2 -Wall -I. -I/usr/X11R6/include -I/usr/local/include -c vsofont.c

