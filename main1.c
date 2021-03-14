//  BENTAYEB Dounia & BOUZAR Louiza

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "remplirMtrix.h"
#include "remplirMtrix.c"

#include "sequentielle.h"
#include "sequentielle.c"
#include "printMatrix.h"
#include "printMatrix.c"
#include "mpiFonction.h"
#include "mpiFonction.c"

int   **A	, **B 	, 	**C 	, **D  ,  n  , p  , i , j , k   ;
char choix [1];

 int main (int argc,char *argv[]) {

     A = (int **)malloc(n * sizeof(int *));

	for (i = 0; i < n; i++)
		A[i] = (int *)malloc(n * sizeof(int));

	B = (int **)malloc(n * sizeof(int *));

	for (i = 0; i < n; i++)
		B[i] = (int *)malloc(n * sizeof(int));

	C = (int **)malloc(n * sizeof(int *));

	for (i = 0; i < n; i++)
		C[i] = (int *)malloc(n * sizeof(int));

	D = (int **)malloc(n * sizeof(int *));

	for (i = 0; i < n; i++)
		D[i] = (int *)malloc(n * sizeof(int));

    printf(" ..... matrix A \n");
	
	generateRandomMatrix(A, n, 0, 99);  	//méthode pour remplir A aléatoirement
	//printMatrix(A);

	printf(" ..... matrix B \n ");

	generateRandomMatrix(B, n, 0, 99);			//méthode pour remplir B aléatoirement
	//printMatrix(B);
    printf ( " entrer la taille de matrice  " );
    scanf( "%d" , n );

    printf ( " choisi la méthode de calcule s or p " );
    scanf( "%s" , choix );

    if ( (!strcmp (choix , "P")) || (!strcmp (choix , "p")) ) { 
   

	  printf ( " lancer le programme parallele mpi\n") ;
       MPI_Init ( &argc,&argv);
       mpi ( C , A , B , n ) ;
	   printMatrix(C , n ) ;

	 }    

     else if (  (!strcmp (choix , "S")) || (!strcmp (choix , "s")) ){

	seqMult ( D ,  A ,  B , n  );
	printMatrix( D , n ) ;		

}
else printf( " erreur ");




     return 0 ;
 }


