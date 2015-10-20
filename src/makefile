CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
FFLAGS = -o $@
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = game
ODIR = ../obj/


include Systems/make_Systems
include Engine/make_Engine

Main_DIR=./


$(ODIR)Main.o: $(Main_DIR)main.cpp
	$(CC) $(CFLAGS) $(Main_DIR)main.cpp $(FFLAGS)


MainPH: $(ODIR)Main.o

$(ODIR):
	mkdir $(ODIR)

OBJDIR:|$(ODIR)

clean:
	rm $(ODIR)*.o

compile: OBJDIR EnginePH SystemsPH MainPH

link: compile
	$(CC) $(LFLAGS) -o $(EXEC) $(ODIR)*.o

all:link

.PHONY:clean compile link all OBJDIR

.DEFAULT_GOAL:=all
