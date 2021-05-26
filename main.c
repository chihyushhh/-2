#include "basic.h"
#include "myc.h"

int main(int argc, char **argv){
    create_data();
    searched_data();
    int whichdata=0;
    int whichsearched=0;
    
    for(int i=0; i<argc; i++){
        char *j=argv[i];
        if(strcmp(j, "-d")==0){
            j=argv[++i];
            //printf("%s\n", j);
            if(strcmp(j, "1e4")==0) whichdata=10000;
            else if(strcmp(j, "1e5")==0) whichdata=100000;
            else if(strcmp(j, "1e6")==0) whichdata=1000000;
            //printf("%d\n", whichdata);
        }
        else if(strcmp(j, "-q")==0){
            j=argv[++i];
            if(strcmp(j, "1e3")==0) whichsearched=1000;
            else if(strcmp(j, "1e4")==0) whichsearched=10000;
            else if(strcmp(j, "1e5")==0) whichsearched=100000;
            //printf("%d\n", whichsearched);
        }
        else if(strcmp(j, "-bst")==0){
            dobst(whichdata, whichsearched);
        }
        else if(strcmp(j, "-bs")==0){
            dobs(whichdata, whichsearched);
        }
        else if(strcmp(j, "-arr")==0){
            doarr(whichdata, whichsearched);
        }
        else if(strcmp(j, "-ll")==0){
            doll(whichdata, whichsearched);
        }
        else if(strcmp(j, "-hash")==0){
            dohash(whichdata, whichsearched);
        }
    }
    return 0;
}