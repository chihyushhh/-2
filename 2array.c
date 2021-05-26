#include "basic.h"
int array[1000000];

int linearsearch(int data[], int search, int maxcnt){
    for(int i=0; i<maxcnt; i++){
        if (data[i]==search) return 1;
    }
    return -1;
}

void doarr(int whichdata, int whichsearched){
    printf("arr:\n");

    FILE *fp;
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    char buf[128];
    int idx=0;

    if(whichdata==10000) fp=fopen("dataset1e4.txt", "r");
    else if(whichdata==100000) fp=fopen("dataset1e5.txt", "r");
    else if(whichdata==1000000) fp=fopen("dataset1e6.txt", "r");

    gettimeofday(&start, NULL);

    while(fgets(buf, 128, fp)){
        array[idx]=atoi(buf);
        idx++;
    }
    fclose(fp);

    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("building time: %f sec\n", diff / 1000000.0);

    if(whichsearched==1000) fp=fopen("searched1e3.txt", "r");
    else if(whichsearched==10000) fp=fopen("searched1e4.txt", "r");
    else if(whichsearched==100000) fp=fopen("searched1e5.txt", "r");
    int found=0;
    int notfound=0;
    gettimeofday(&start, NULL);

    while(fgets(buf, 128, fp)){
        int num=atoi(buf);
        if(linearsearch(array, num, whichdata)==-1) notfound++;
        else found++;
    }
    fclose(fp);

    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n", diff / 1000000.0);
}
/*
int main(){
    int a=1000000, b=100000;
    doarr(a, b);
    return 0;
}*/