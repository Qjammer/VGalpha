CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
FFLAGS = -o $@
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = ??
ODIR = ../obj/


include engine/framework/uEntities/make_uEntities

clean:
	rm $(ODIR)*.o

