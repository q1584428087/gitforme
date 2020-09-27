#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
typedef struct LNode{
    int data;
    struct LNode* pnext;
}LNode;

int main(){
    LNode* p;
    LNode* q;
    LNode* g;

    p=(LNode*)malloc(sizeof(LNode));
    p->pnext=NULL;
    q=(LNode*)malloc(sizeof(LNode));
    q->pnext=NULL;
    g=(LNode*)malloc(sizeof(LNode));
    g->pnext=NULL;

    int e=0;
    LNode* temp,*p1,*q1;
    p1=p;   
    q1=q;
    scanf("%d",&e);
    while(e>0){
        temp=(LNode*)malloc(sizeof(LNode));
        temp->data=e;
        temp->pnext=NULL;
        p1->pnext=temp;
        p1=temp;
        scanf("%d",&e);

    }


    scanf("%d",&e);
    while(e>0){
        temp=(LNode*)malloc(sizeof(LNode));
        temp->data=e;
        temp->pnext=NULL;
        q1->pnext=temp;
        q1=temp;
        scanf("%d",&e);
    }



    LNode* pa,*pb,*pc;
    pa=p->pnext;
    pb=q->pnext;
    pc=g;
    while(pa&&pb)
    {
        if(pa->data<=pb->data){
            pc->pnext=pa;
            pc=pa;
            pa=pa->pnext;
        }
        else{
            pc->pnext=pb;
            pc=pb;
            pb=pb->pnext;
        }
        
    }
    if(!pa)
    {
        while(pb){
            pc->pnext=pb;
            pc=pb;
            pb=pb->pnext;
        }
        
    }
    else if(!pb){
        while (pa)
        {
            pc->pnext=pa;
            pc=pa;
            pa=pa->pnext;
        }
        
    }

    free(q);
    free(p);


    if(g->pnext==NULL){
        printf("NULL");
    }
    else{
        g=g->pnext;
        while (g)
        {
            if(g->pnext!=NULL)
                printf("%d ",g->data);
            else{
                printf("%d",g->data);
            }
            g=g->pnext;
        }
    }

    return 0;
}
