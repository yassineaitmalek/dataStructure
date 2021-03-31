#include <stdio.h>
#include <stdlib.h>


typedef struct node_s *pnode ;
typedef struct node_s {
	int i ;
	pnode next ;
} node ;
typedef pnode list ;


list listevide(){
    return (NULL);
}


list adddeb(list l,int e){

    pnode p;
    p=(pnode)malloc(sizeof(node));
    p->i=e;
    p->next=l;
    l=p;
    return l;

}

list inv(list l){

    pnode p=l;
    list m=listevide();
    while (p){
        m=adddeb(m,p->i);
        p=p->next;
    }
    return m;

}


list addend (list l,int e){
    if (l==NULL){return adddeb(l,e);}
    else{
            pnode p=l;
            p=inv(p);
            p=adddeb(p,e);
            p=inv(p);
            l=p;
            return l;

    }

		}



int isempty(list l){
    return l==NULL;
}

void print(list l){

    pnode p=l;
    while(p!=NULL){
        printf("%d \n",p->i);
        p=p->next;
    }

}



list conct(list l,list m){
    pnode p=l;
    if (isempty(l)){return m;}
    else{
        while (p!=NULL){p=p->next;}
        p->next=m;
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
        if (m==s){printf("%d \n",p->i);break;}
        else{ m++;
            p=p->next;}

    }}


}


int search(list l, int e){
    pnode p=l;
    int s=0;
    while (p){
        if (p->i==e){printf("exists place: %d \n",s);break;}
        else{s++;p=p->next;}
    }
    if(s==len(l)){return -1;}
    else{return(s);}


}


list rv(list l,int index) {
    if (index >= len(l)){
         printf("Error");
            exit(0);
    }
    else if(index==0){
            printf("succes item  deleted :      %d   index :     %d \n",l->i,index);
        l=l->next;

        return (l);
    }

        else {
            int cur_index=0;
            pnode p=l;
            pnode q;
            int a=1;
            while (a){
                cur_index+=1;
                q=p;
                p=p->next;
                if (cur_index==index ){q->next=p->next;printf("succes item  deleted :      %d   index :     %d \n",p->i,index);a=0;}


            }


     return (l);
        }};








int main()
{
    list l = listevide();


   l=adddeb(l, 4);
   l=adddeb(l, 5);
   l=adddeb(l, 2);
   l=adddeb(l, 10);


l=rv(l,2);




print(l);






    return 0;
}
