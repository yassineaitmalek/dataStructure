#include <stdio.h>
#include <stdlib.h>

typedef struct node_s *pnode ;
typedef struct node_s {
	int data ;
	pnode next ;
} node ;
typedef pnode list ;



void print(list l){

if (l==NULL){printf("---\n");}
else{
    printf("%d \n",l->data);
    print(l->next);
}

}

int len(list l){
if (l==NULL){return 0;}
else{
    return(1+len(l->next));
}
}


int nbroc(list l,int e){
if (l==NULL){return 0;}
else{return (1+nbroc(l->next,e));}

}


list addend(list l, int e){
    if (l == NULL) {
        l = (pnode)malloc(sizeof(list));
        l->data = e;
        l->next = NULL;
        }
    else{l->next = addend(l->next, e);}

    return l;
}


list rvlast(list l){
    pnode p=l;
    if (l==NULL){return NULL;}
    if(p->next==NULL){free(p);}
    else{ rvlast(l->next);}
    return l;

}


list rv(list l, int index) {
    if(index>len(l) || index<0){return l;}

    if (index == 0) {return l->next;}
    if (l == NULL){return NULL; }
    l->next = rv(l->next, index-1);
    return l;
}

list concat(list l,list m){
    if (l==NULL){return m;}
    else if(l->next==NULL){l->next=m;}
    else{concat(l->next,m);}
    return l;

}




int main()
{
    list l = NULL;
    list m = NULL;
    l=addend(l,5);
    l=addend(l,12);
    l=addend(l,55);
    l=addend(l,544);

    // j'ai un probleme concernant la fonction rvlast et j'ai pas pu construire la fonction recursive inverse


    print(l);




    return 0;
}
