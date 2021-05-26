#include <stdio.h>
#include <stdlib.h>

int sch1e3[1000];
int sch1e4[10000];
int sch1e5[100000];

void searched_data(){
    FILE *fp=fopen("searched1e3.txt", "w");
    srand(1);
    for(int i=0; i<1000; i++){
        sch1e3[i]=rand();
        fprintf(fp, "%d\n", sch1e3[i]);
    }
    fclose(fp);

    fp=fopen("searched1e4.txt", "w");
    for(int i=0; i<10000; i++){
        sch1e4[i]=rand();
        fprintf(fp, "%d\n", sch1e4[i]);
    }
    fclose(fp);

    fp=fopen("searched1e5.txt", "w");
    for(int i=0; i<100000; i++){
        sch1e5[i]=rand();
        fprintf(fp, "%d\n", sch1e5[i]);
    }
    fclose(fp);
}