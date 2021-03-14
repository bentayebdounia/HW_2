all: hw2
hw2: remplirMtrix.o sequentielle.o  printMatrix.o  mpiFonction.o main1.o
	mpicc remplirMtrix.o sequentielle.o  printMatrix.o  mpiFonction.o main1.o -o hw2


remplirMtrix.o: remplirMtrix.c remplirMtrix.h
	gcc -c remplirMtrix.h remplirMtrix.c
sequentielle.o: sequentielle.c sequentielle.h
	gcc -c sequentielle.h sequentielle.c
printMatrix.o: printMatrix.c printMatrix.h
	gcc -c printMatrix.h printMatrix.c
mpiFonction.o: mpiFonction.c mpiFonction.h
	gcc -c mpiFonction.h mpiFonction.c
main1.o:   remplirMtrix.h  sequentielle.h  functions.h  printMatrix.h mpiFonction.h  main1.c
	gcc -c remplirMtrix.h remplirMtrix.c mpiFonction.h mpiFonction.c sequentielle.h sequentielle.c printMatrix.h printMatrix.c main1.c

clean:
	rm -fr hw2 *.o
