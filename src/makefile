CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -std=c++14 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
FFLAGS = -o $@
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = ??
ODIR = ../obj/


include Systems/make_Systems
include Engine/make_Engine


clean:
	rm $(ODIR)*.o

compile: EnginePH SystemsPH

link:compile
	$(CC) $(LFLAGS) -o $(EXEC) $(ODIR)*.o

.PHONY:clean all link
