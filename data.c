#include <stdio.h>
#include <stdlib.h>

int num1e4[10000];
int num1e5[100000];
int num1e6[1000000];

void create_data(){
    FILE *fp=fopen("dataset1e4.txt", "w");
    srand(5);
    for(int i=0; i<10000; i++){
        num1e4[i]=rand();
        fprintf(fp, "%d\n", num1e4[i]);
    }
    fclose(fp);

    fp=fopen("dataset1e5.txt", "w");
    for(int i=0; i<100000; i++){
        num1e5[i]=rand();
        fprintf(fp, "%d\n", num1e5[i]);
    }
    fclose(fp);

    fp=fopen("dataset1e6.txt", "w");
    for(int i=0; i<1000000; i++){
        num1e6[i]=rand();
        fprintf(fp, "%d\n", num1e6[i]);
    }
    fclose(fp);
}