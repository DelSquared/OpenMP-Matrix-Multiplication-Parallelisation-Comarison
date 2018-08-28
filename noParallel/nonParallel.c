#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <time.h>

//This is the code NOT using OpenMP to parallelise the code on all (4) cores of the CPU then appending the time it took to the txt file
//uncomment the comments below to also have it print the result to the console

int main(){

    int n = 416;
    

    int a[n][n];
    int b[n][n];
    int c[n][n];
    int i,j,k;

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            a[i][j]=rand()%50;
            b[i][j]=rand()%50;
            c[i][j]=0;
        }
    }

    clock_t begin = clock();
    //#pragma omp parallel for
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            for (k=0;k<n;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("Time spent: %lf\n",time_spent);

    FILE * fp;
    fp = fopen ("nopar.txt","a");
    fprintf (fp, "%lf,",time_spent);
    fclose (fp);
    //system("pause");

}
