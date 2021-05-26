#include "basic.h"
int array[1000000];

int compare(const void *a, const void *b){
    int c=*(int *)a;
      int d=*(int *)b;
      if (c<d) return -1;
      else if (c==d) return 0;
      else return 1;
}

int binarysearch(int data[], int search, int n){
    int low=0, high=n-1;

    while (low<=high){
        int mid=(low+high)/2;

        if(data[mid]==search) return mid;
        else if(data[mid]>search) high=mid-1;
        else if(data[mid]<search) low = mid + 1;
    }
    return -1;
}

void dobs(int whichdata, int whichsearched){
    printf("bs:\n");

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
    qsort(array, whichdata, sizeof(int), compare);

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
        if(binarysearch(array, num, whichdata)==-1) notfound++;
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
    dobs(a, b);
    return 0;
}*/