#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <time.h>

//This is to check that both algorithms are giving the same exact answer. The commented out section can be uncommented to enable the
//executable to print the arrays as well for double checking

int main(){
    srand((int)time(NULL)); //randomising the seed a bit using the current time

    int n = 10; //array dimensions
    int mismatch = 0; //a "boolean" value

    int a[n][n]; //first matrix
    int b[n][n]; //second matrix
    int c1[n][n]; //matrix to hold the serial algorithm's output
    int c2[n][n]; //matrix to hold the parallel algorithm's output
    int i,j,k; //indices

    for (i=0;i<n;i++){ //initialising the arrays
        for (j=0;j<n;j++){
            a[i][j]=rand()%50; //a is randomly initialised
            b[i][j]=rand()%50; //b is randomly initialised
            c1[i][j]=0; //c1 is a null matrix
            c2[i][j]=0; //c2 is a null matrix
        }
    }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            for (k=0;k<n;k++){
                c1[i][j] += a[i][k]*b[k][j]; //standard serial matrix multiplication
            }
        }
    }

    #pragma omp parallel for private(k)
    for (i=0;i<n;i++){
        #pragma omp parallel for private(k)
        for (j=0;j<n;j++){
            for (k=0;k<n;k++){
                c2[i][j] += a[i][k]*b[k][j]; //parallelised matrix multiplication
            }
        }
    }

//The code below is comparring c1 to c2 and by uncommenting can also be made to print both arrays
    
//    for (i=0;i<n;i++){
//        for (j=0;j<n;j++){
//            printf("%d\t",c1[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
//            printf("%d\t",c2[i][j]);
            if (c1[i][j]!=c2[i][j]){
                 mismatch = 1;
            }
        }
//        printf("\n");
    }

//    printf("\n");
    if (mismatch==1){
        printf("There was a mismatch\n");
    }else{
        printf("They match\n");
    }

//    system("pause");

}
