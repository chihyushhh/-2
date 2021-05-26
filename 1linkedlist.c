#include "basic.h"

struct node{
    int number;
    struct node *next;
};

struct node *ll_insert(struct node *start, int buffer){
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->number=buffer;
    p->next=start;
    return p;
}

struct node *ll_find(struct node *L, int buffer){
    struct node *p=L;
    while(p){
        if(p->number==buffer) return p;
        p=p->next;
    }
    return NULL;
}

void doll(int whichdata, int whichsearched){
    printf("ll:\n");

    FILE *fp;
    struct timeval start;
    struct timeval end;
    unsigned long diff;

    if(whichdata==10000) fp=fopen("dataset1e4.txt", "r");
    else if(whichdata==100000) fp=fopen("dataset1e5.txt", "r");
    else if(whichdata==1000000) fp=fopen("dataset1e6.txt", "r");
    
    char buffer[128];
    int buf;
    struct node *L=NULL;

    gettimeofday(&start, NULL);

    while(fgets(buffer, 128, fp)){
        buf=atoi(buffer);
        L=ll_insert(L, buf);
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

    while(fgets(buffer, 128, fp)){
        buf=atoi(buffer);
        if(ll_find(L, buf)==NULL) notfound++;
        else found++;
    }
    fclose(fp);

    gettimeofday(&end, NULL);
    diff = 1000000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    printf("query time: %f sec\n", diff / 1000000.0);
}
/*
int main(){
    int a=1000000, b=1000;
    doll(a, b);
    return 0;
}
*/