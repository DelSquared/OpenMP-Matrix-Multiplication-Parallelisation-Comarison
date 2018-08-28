#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <time.h>

//This is the code NOT using OpenMP to parallelise the code on all (4) cores of the CPU then appending the time it took to the txt file
//uncomment the comments below to also have it print the result to the console

int main(){

    int n = 416; //matrices are 416x416 in order to stress test the code and is a multiple of 4
    

    int a[n][n];
    int b[n][n];
    int c[n][n]; //declairing arrays
    int i,j,k; //ideclairing indices

    for (i=0;i<n;i++){ //initialising arrays
        for (j=0;j<n;j++){
            a[i][j]=rand()%50;
            b[i][j]=rand()%50;
            c[i][j]=0;
        }
    }

    clock_t begin = clock(); //begin clock
    for (i=0;i<n;i++){ //normal serial matrix multiplication
        for (j=0;j<n;j++){
            for (k=0;k<n;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    clock_t end = clock(); //end clock and work out time
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    
    //printf("Time spent: %lf\n",time_spent);

    FILE * fp; //Writing to the file. The extra comma after the last entry will give us a NaN element in the python array that will be ignored
    fp = fopen ("nopar.txt","a");
    fprintf (fp, "%lf,",time_spent);
    fclose (fp);
    
    //system("pause");

}
