#include <stdio.h>
#include <stdlib.h>



typedef struct{

    int t[50];
    int head;
    int nbe;
    int q;


}file;

file newfile(){

    file f;
    f.head=0;
    f.q=0;
    f.nbe=0;
    return(f);
}

int isempty(file f){
    return(f.nbe==0);
}

int filefull(file f){
    return(f.nbe==49);
}

file add(file f,int e){
    if(filefull(f)){printf("the file is filled");exit(0);}
    else{
                f.q++;
                f.t[f.q]=e;
                f.nbe++;
    };
    return(f);

}

file pop(file f){
        if (isempty(f)){printf("this file is empty ");exit(0);}
        else{
        f.head++;
        f.nbe--;
        };
        return(f);
}


int head(file f){
    return(f.t[f.head+1]);
}


int main()
{


        file f = newfile();

    f=add(f,10);
    f=add(f, 20);
    f=add(f, 30);
    f=add(f, 40);
    f=add(f, 50);
    printf("index of head and queue are : head :%d queue :%d \n",f.head,f.q);


    
    for(int i=0;i<5;i++){
  printf("%d\t", head(f));
  f=pop(f);

}


    return 0;
}
