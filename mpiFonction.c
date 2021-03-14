
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <mpi.h>
#include "mpiFonction.h"
  
  

void mpi ( int** C , int** A , int** B , int n ){

     int p;
     
     MPI_Status status;

     int Nb_Process  ;
     MPI_Comm_size(MPI_COMM_WORLD , &Nb_Process);
     
     int rang;
     MPI_Comm_rank(MPI_COMM_WORLD , &rang);
     
     int s  =  n / Nb_Process ;
     int idebut = rang * s ;
     int ifin = idebut + s - 1 ;
     int jdebut = rang * s ;
     int jfin = idebut + s - 1;

     for ( int e = 0 ; e < Nb_Process ; e++){	
     
       for ( int i = idebut ; i < (idebut + s - 1) ; i++  ) {


     	   for ( int j = jdebut ; j < jfin ; j++ ){

     		 C[i][j] = 0 ;
     		 		
     			for ( int k = 0 ; k < n ; k++ ) {

     				C[i][j]= C[i][j] + A[i][k] * B[k][j] ;


     		}




     	}

     	

     }

     if ( e == rang ) {

     			if ( rang == Nb_Process-1 ){
     			 idebut = e*s ;
     			 MPI_Send( &idebut  , 1 , MPI_INT , 0 , 102 , MPI_COMM_WORLD );
     			}

     			else {
     			 idebut = e*s ;
     			 MPI_Send( &idebut , 1 , MPI_INT , e+1 , 102 , MPI_COMM_WORLD );
     			}
     		}
     		else if ( e+1 == rang ) {
     		   idebut = e*s ;
     		   MPI_Recv( &p , 1 , MPI_INT , e , 102 , MPI_COMM_WORLD , &status );
     		}
     			 else if ( e+1 >= Nb_Process && rang ==0 ) {
     			 	idebut = e*s ;
     			 	MPI_Recv( &p , 1 , MPI_INT , Nb_Process-1 , 102 , MPI_COMM_WORLD , &status );

     		}
     		



 }
 MPI_Finalize();

}