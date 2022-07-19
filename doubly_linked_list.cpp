#include<bits/stdc++.h>
using namespace std;
struct node
{
    struct node *prev;
    int data;
    struct node *next;
}*first=NULL;
void create(int ar[],int n)
{
    struct node *t,*last;
    int i;
    first=new node;
    first->data=ar[0];
    first->prev=first->next=NULL;
    last=first;
    for(int i=1; i<n; i++){
        t=new node;
        t->data=ar[i];
        t->prev=last;
        t->next=NULL;
        last->next=t;
        last=t;
    }

}
void display(struct node *p)
{
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int len(struct node *p)
{
    int l=0;
    while(p){
        l++;
        p=p->next;
    }
    return l;
}
void Insert(struct node *p,int index,int x)
{
    struct node *t;
    int i;
    if(index<0 || index>len(p)){
        return;
    }
    if(index==0)
    {
        t=new node;
        t->data=x;
        t->next=first;
        t->prev=NULL;
        first->prev=t;
        first=t;
    }
    else{
        for(int i=0; i<index-1; i++){
             p=p->next;
        }
        t=new node;
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next){
           t->next->prev=t;
        }
        p->next=t;

    }
}
void revers(struct node *p)
{
    struct node *tmp;
    while(p!=NULL){
        tmp=p->next;
        p->next=p->prev;
        p->prev=tmp;
        p=p->prev;
        if(p!=NULL && p->next==NULL) first=p;
    }

}
int main()
{
    int ar[]={3,4,6,4,6,5,4};
    create(ar,7);
    //Insert(first,4,10);
    display(first);
    revers(first);
    display(first);
    //int l=len(first);
   // cout<<l<<endl;
}
