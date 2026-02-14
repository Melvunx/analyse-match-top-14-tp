all: Equipe.o Match.o main_top14_etu.o
	gcc -o main_top14_etu main_top14_etu.o Equipe.o Match.o

main_top14_etu.o: main_top14_etu.c Equipe.h Match.h
	gcc -Wall -g -c main_top14_etu.c

Equipe.o: Equipe.c Equipe.h Match.h
	gcc -Wall -g -c Equipe.c

Match.o: Match.c Match.h Equipe.h
	gcc -Wall -g -c Match.c

clean:
	del *.o main_top14_etu