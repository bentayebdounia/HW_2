#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sequentielle.h"
     
     double debut , fin ;
     
     /*  Méthode de calcule de multutiplication en séquentielle */

 	void seqMult ( int** matrix , int** A , int** B , int n  ) {
       
	   	int i , j , k ;
           
  		 for ( i= 0  ; i<n ; i++) { 

			for ( j = 0 ; j<n ; j++ ) {
				matrix [i][j] = 0 ;

				for ( k = 0 ; k < n ; k++ ) 
					matrix[i][j] = matrix[i][j] + A[i][k] * B[k][j] ;
					

				}		

			}
        
       

}

	