#include <stdio.h>
#include <stdlib.h>


typedef struct node_s *pnode;
typedef struct node_s{
    int data;
    pnode next;
    pnode prev;

}node;
typedef pnode list;


list emptylist(){
  return NULL;
}

int isempty(list l){
    return l==NULL;
}



list prv(list l,pnode p){
    l->prev=p;
    return l;
}



list adddeb(list l,int e){

    pnode p,q=l;
    p=(pnode)malloc(sizeof(node));

    p->data=e;
    p->next=l;
    if (isempty(q)){
        return p;
    }
    else{
       q->prev=p;

       return p;
    }
}

list inv(list l){

    pnode p=l;
    list m=emptylist();
    while (p){
        m=adddeb(m,p->data);
        p=p->next;
    }
    return m;

}

list addend(list l,int e){
    pnode p=l,q;

    q=(pnode)malloc(sizeof(node));
    q->data=e;

    if (isempty(p)){
            p=q;
            return l;

    }
    else{
        while(p->next!=NULL){

        p=p->next;
    }
     p->next=q;
    q->prev=p;

        return l;
    }



}


int len(list l){
    int m=0;
    pnode p=l;
    while(p){
        m++;
        p=p->next;
    }
    return m;
}

void acces(list l,int s){
    int m=0;
    pnode p=l;
    if(s>len(l) && s<0){printf("none");}
    else{
        while (p!=NULL){
        if (m==s){printf("%d \n",p->data);break;}
        else{ m++;
            p=p->next;}

    }}


}


int search(list l, int e){
    pnode p=l;
    int s=0;
    while (p){
        if (p->data==e){printf("exists place: %d \n",s);break;}
        else{s++;p=p->next;}
    }
    if(s==len(l)){return -1;}
    else{return(s);}


}


list rv (list l,int index){
       if (index >= len(l)){
         printf("Error");
            exit(0);
        }
        else if(index==0){
            printf("succes item  deleted :      %d   index :     %d \n",l->data,index);
        l=l->next;

        return (l);
        }

        else {
            int cur_index=0;
            pnode p=l;

            int a=1;
            while (a){
                cur_index+=1;
                p->prev=p;
                p=p->next;
                if (cur_index==index ){p->prev->next=p->next;printf("succes item  deleted :      %d   index :     %d \n",p->data,index);a=0;}


            }


     return (l);
        }
}


void print(list l){

    pnode p=l;
    printf("\n");
    while(p!=NULL){
        printf("%d    \n",p->data);
        p=p->next;
    }
    printf("\n");
}


void print2(list l){

    pnode p=l;
    while(p->next!=NULL){
        p=p->next;

    }
    printf("\n");
    while(p!=NULL){
        printf("%d \n",p->data);
        p=p->prev;
    }
    printf("\n");
    return;
}




int main()
{
    list l = emptylist();


   l=adddeb(l, 4);
   l=adddeb(l, 5);
   l=adddeb(l, 2);
   l=adddeb(l, 10);

print(l);

// toutes les fonctions marche tres bien sauf la fonction addend
    return 0;
}
