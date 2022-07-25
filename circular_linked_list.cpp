#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head;
void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    head=new node;
    head->data=a[0];
    head->next=head;
    last=head;
    for(int i=1; i<n; i++){
        t=new node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(struct node *h)
{
    do{
        cout<<head->data<<" ";
        head=head->next;
    }while(h!=head);
    cout<<endl;
}
void Ddisplay(struct node *h)
{
    static int flag=0;
    if(h!=head || flag==0){
        flag=1;
        cout<<h->data<<" ";
        h=h->next;
        Ddisplay(h);
    }
    flag=0;
}
int len(struct node *p)
{
    int l=0;
    do{
        l++;
        p=p->next;

    }while(p!=head);
    return l;
}
void Insert(struct node *p,int index,int x)
{
    struct node *t;
    int i;
    if(index<0 || index>len(head)){

    }
    if(index==0){
        t=new node;
        t->data=x;
        if(head==NULL){
            head->next=head;

        }
        else{
            while(p->next!=head)p=p->next;
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        for(int i=0; i<index-1; i++){
            p=p->next;
        }
        t=new node;
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}
int main()
{
    int ar[]={2,5,4,6,8,4};
    create(ar,6);
    Insert(head,4,100);
    Ddisplay(head);
}
