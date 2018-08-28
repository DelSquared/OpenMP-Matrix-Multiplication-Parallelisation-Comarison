#include <stdio.h>
#include <omp.h>
#include <unistd.h>
#include <time.h>

//This is to check that both algorithms are giving the same exact answer. The commented out section can be uncommented to enable the
//executable to print the arrays as well for double checking

int main(){
    srand((int)time(NULL));

    int n = 10;
    int mismatch = 0;

    int a[n][n];
    int b[n][n];
    int c1[n][n];
    int c2[n][n];
    int i,j,k;

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            a[i][j]=rand()%50;
            b[i][j]=rand()%50;
            c1[i][j]=0;
            c2[i][j]=0;
        }
    }

    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            for (k=0;k<n;k++){
                c1[i][j] += a[i][k]*b[k][j];
            }
        }
    }

    #pragma omp parallel for private(k)
    for (i=0;i<n;i++){
        #pragma omp parallel for private(k)
        for (j=0;j<n;j++){
            for (k=0;k<n;k++){
                c2[i][j] += a[i][k]*b[k][j];
            }
        }
    }

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
