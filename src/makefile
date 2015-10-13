CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
FFLAGS = -o $@
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = ??
ODIR = ../obj/


include System/EntityExtensions/make_EntityExtensions
include Engine/make_Engine





clean:
	rm $(ODIR)*.o

.PHONY:clean
