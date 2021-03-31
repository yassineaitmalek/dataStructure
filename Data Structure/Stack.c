#include <stdio.h>
#include <stdlib.h>


typedef struct{

    int top;
    int t[50];

}pile;


pile newpile(){
    pile p;
    p.top=-1;
    return(p);
}

pile push(pile p,int n){

    p.top++;
    p.t[p.top]=n;
    return (p);
}


int isempty(pile p){

    return(p.top == -1) ;
}


pile pop(pile p){
    if (isempty(p)){
        printf("the pile is empty");
        return(p);
    }
    else{
        p.top--;
        return(p);
    };

}

int summit(pile p){
    if (!isempty(p)){
        return(p.t[p.top]);
    }
}


int pile_full(pile p){

    return(p.top==49);
}

int bienecrit(char *s){

    int i=0,bpar=1;
    pile p;
    p=newpile();
    while(s[i]!='\0')
    {
        if(s[i]=='(')
            p=push(p,'(');
        if(s[i]==')')
        {
            if(isempty(p))
            {
                bpar=0;
                break;
            }else{
            p=pop(p);

            }
        }
        i++;
    }
    if(isempty(p)&&bpar==1)
    {
        printf("\n bien ecrit \n");return 1;
    }else{
        printf("\n erreur d'ecriture \n");
        return 0;
    }

}






void main(){

pile p = newpile();

     p =push(p, 4);
     p =push(p, 8);
     p =push(p, 15);
     p =push(p, 16);
     p =push(p, 23);
     p =push(p, 42);

    
    for(int i=0;i<6;i++){
    	printf("%d\n", summit(p));
    	p=pop(p);
	}

bienecrit("((a+b");



}
