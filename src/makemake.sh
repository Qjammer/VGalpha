HEADER='CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -pthread -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) -pthread
FFLAGS = -o $@
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = game

'

ODIR="../obj/"

OUTPUTFILE="./makefile2"

printf "$HEADER"
for f in $(find | grep ".cpp")
do
	FILENAME="$(printf "$f" | grep -o -E '[a-zA-Z0-9]+.cpp')"
	printf "$ODIR${FILENAME%".cpp"}.o: $f"
	if [ "$FILENAME" = "main.cpp" ]
		then
			printf ""
		else
			printf " ${f%".cpp"}.hpp"
	fi
	printf "\n\t"
	printf '$(CC) $(CFLAGS) '
	printf "$f"
	printf ' $(FFLAGS)

'
done

printf "clean:\n\trm $ODIR*.o\n\n"

printf "$ODIR:
	mkdir $ODIR

OBJDIR:|$ODIR

"


printf '$(EXEC): '
for f in $(find | grep -o -E '[a-zA-Z0-9]+.cpp')
do
printf "$ODIR"
printf "${f%".cpp"}.o "
done

printf "\n\t"
printf '$(CC) $(LFLAGS) -o $(EXEC) '
printf "$ODIR*.o "
printf '$(LIBS)
'

printf '
.DEFAULT_GOAL:=$(EXEC)

.PHONY:clean compile link all OBJDIR
'




#find | grep -o -E '[a-zA-Z0-9]+.cpp'
