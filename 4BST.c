#include "basic.h"

struct bst{
    int number;
    struct bst *right;
    struct bst *left;
};

struct bst *bst_insert(struct bst *root, int number){
    if(root==NULL) {
        struct bst *p;
        p=(struct bst *)malloc(sizeof(struct bst));
        p->number=number;
        p->left=NULL;
        p->right=NULL;
        return p;
    }
    if(number<=root->number){  //strcmp(root->word, word)>=0
        root->left=bst_insert(root->left, number);
        return root;
    }
    else if (number>root->number){
        root->right=bst_insert(root->right, number);
        return root;
    }
}

int bst_find(struct bst *L, int num){
    if(L==NULL) return 0;
    else if (L->number==num) return 1;
    else if (num<L->number) return bst_find(L->left, num);
    else if (num>L->number) return bst_find(L->right, num);
}

void dobst(int whichdata, int whichsearched){
    printf("bst:\n");

    FILE *fp;
    struct timeval start;
    struct timeval end;
    unsigned long diff;

    if(whichdata==10000) fp=fopen("dataset1e4.txt", "r");
    else if(whichdata==100000) fp=fopen("dataset1e5.txt", "r");
    else if(whichdata==1000000) fp=fopen("dataset1e6.txt", "r");
    
    char buffer[128];
    int buf;
    struct bst *T=NULL;

    gettimeofday(&start, NULL);

    while(fgets(buffer, 128, fp)){
        buf=atoi(buffer);
        T=bst_insert(T, buf);
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
        if(bst_find(T, buf)==0) notfound++;
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
    dobst(a, b);
    return 0;
}*/