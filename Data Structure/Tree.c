#include <stdio.h>
#include <stdlib.h>

typedef struct tree_s *ptree ;
typedef struct tree_s {
	int data ;
	ptree leftchild ;
	ptree rightchild;
} tree ;
typedef ptree Tree;

Tree emptytree(){
    return NULL;
}

int isempty(Tree t){

    return t==NULL;
}

Tree add(Tree t,int e){ 

    ptree p=(ptree)malloc(sizeof(tree));
    p->data=e;
    p->leftchild=NULL;
    p->rightchild=NULL;
    if (isempty(t)){
        t=p;
        printf("created and added sucssefuly\n");
    }
    else{
        ptree cur=t;
        ptree par=NULL;
        int a=1;
        while(a){
            par=cur;
            if(e<par->data){
                    cur=cur->leftchild;
                    if (cur==NULL){par->leftchild=p;a=0;printf("added sucssefuly\n");}
            }
            else{
                cur=cur->rightchild;
                if (cur==NULL){par->rightchild=p;a=0;printf("added sucssefuly\n");}
            }
        }

    }

    return t;
}

void in_order(Tree t){
        if (t!=NULL){
           in_order(t->leftchild);
           printf("\t %d \t \n",t->data);
           in_order(t->rightchild);


        };
}

void pre_order(Tree t){
        if (t!=NULL){
           printf("\t %d \t \n",t->data);
           pre_order(t->leftchild);
           pre_order(t->rightchild);


        };
}

void post_order(Tree t){
        if (t!=NULL){
           post_order(t->leftchild);
           post_order(t->rightchild);
           printf("\t %d \t \n",t->data);


        };
}

void Traversal(Tree t){
    int a;
    do {
            printf("In-order = 1 ;; Pre-order = 2 ;; Post-order = 3 \n");
            printf("Enter your Traversal method : ");
            scanf("%d",&a);

    }while(a<0 || a>4);
    switch(a){
        case 1: in_order(t);break;
        case 2: pre_order(t);break;
        case 3: post_order(t);break;
    }

}

int search(Tree t,int e){

    if(isempty(t)){return 0;}
    else{
            if(e==t->data){return 1;}
            else{
                if(e<t->data){return search(t->leftchild,e);}
                else{return search(t->rightchild,e);}
            }
    }



}

int max(Tree t){  // element max de l arbre
    if (isempty(t)){return  NULL;}
    int maxt=t->data;
    int maxleft = max(t->leftchild);
    int maxright = max(t->rightchild);
    if (maxleft > maxt){maxt = maxleft;}
    if (maxright > maxt){maxt = maxright;}

    return maxt;
}

int min(Tree t){ //element min de l arbre

    if (isempty(t)){return  NULL;}
    int mint=t->data;
    int minleft = min(t->leftchild);
    int minright = min(t->rightchild);
    if (minleft < mint){mint = minleft;}
    if (minright < mint){mint = minright;}

    return mint;
}

Tree mintree(Tree t){ //cherchemin
	if(t==NULL){
		return NULL;}
	if (t->leftchild){
		return mintree(t->leftchild);}
	else {return t;}
}

Tree maxtree(Tree t){ //cherchemax
	if(t==NULL){
		return NULL;}
	if (t->rightchild){
		return maxtree(t->rightchild);}
	else {return t;}
}


Tree rv(Tree t, int e){ //suprimerarb

    if (t == NULL) {return t;}
    if (e < t->data){t->leftchild = rv(t->leftchild, e);}
    else if (e > t->data){t->rightchild = rv(t->rightchild, e);}
    else{

        if (t->leftchild == NULL){
            Tree temp = t->rightchild;
            free(t);
            return temp;
        }
        else if (t->rightchild == NULL){
            Tree temp = t->leftchild;
            free(t);
            return temp;
        }

        Tree temp = mintree(t->rightchild);
        t->data = temp->data;
        t->rightchild = rv(t->rightchild, temp->data);
    }
    return t;
}



void in_order_2(Tree t,int space){  
        if (t!=NULL){
           space+=10;
           in_order_2(t->leftchild,space);
           printf("\n");
           for (int i =0; i < space; i++){
                printf(" ");
           }

           printf("\t %d \t \n",t->data);
           in_order_2(t->rightchild,space);


        };
}

int main()
{

Tree t=emptytree();
    t=add(t,8);
    t=add(t,7);
    t=add(t,10);
    t=add(t,6);
    t=add(t,85);
in_order(t);
printf("\n");
rv(t,7);
in_order(t);

printf("\n");

in_order_2(t,0);


    return 0;
}
