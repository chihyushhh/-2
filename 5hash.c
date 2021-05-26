#include "basic.h"

struct data{
    int number;
    struct data *next;
};

unsigned int hash(int number){
    return number%1000000;
}

struct data *l_insert(struct data *L, int key){
    struct data *p=(struct data *)malloc(sizeof(struct data));
    p->number=key;
    p->next=L;
    return p;
}

struct data *l_find(struct data *L, int key){
    struct data *p;
    if(L==NULL) return NULL;
    p=L;
    while (p){
        if(p->number==key) return p;
        p=p->next;
    }
    return NULL;
}

void hash_insert(struct data **hTable, int key){
    unsigned int hashvalue;
    struct data *L;
    hashvalue=hash(key);
    L=hTable[hashvalue];
    hTable[hashvalue]=l_insert(L, key);
}

struct data *hash_find(struct data **hTable, int key){
    unsigned int hv;
    struct data *dptr;
    hv=hash(key);
    dptr=hTable[hv];
    return l_find(dptr, key);
}

void dohash(int whichdata, int whichsearched){
    printf("hash:\n");

    FILE *fp;
    struct timeval start;
    struct timeval end;
    unsigned long diff;

    if(whichdata==10000) fp=fopen("dataset1e4.txt", "r");
    else if(whichdata==100000) fp=fopen("dataset1e5.txt", "r");
    else if(whichdata==1000000) fp=fopen("dataset1e6.txt", "r");

    struct data **hashTable;
    int maxHash=1000000;
    struct data *dptr;
    char buffer[128];
    int buf;
    hashTable=(struct data**)malloc(sizeof(struct data*)*maxHash);
    for(int i=0; i<maxHash; i++){
        hashTable[i]=NULL;
    }

    gettimeofday(&start, NULL);
    while(fgets(buffer, 128, fp)){
        buf=atoi(buffer);
        hash_insert(hashTable, buf);
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
        if(hash_find(hashTable, buf)==NULL) notfound++;
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
    dohash(a, b);
    return 0;
}*/