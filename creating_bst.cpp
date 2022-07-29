#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *rchild,*lchild;
}*root=NULL;
void Insert(int key)
{
    struct node *t=root;
    struct node *r,*p;
    if(root==NULL){
        p=new node;
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL){
        r=t;
        if(key<t->data){
            t=t->lchild;
        }
        else if(key>t->data){
            t=t->rchild;
        }
        else return;
    }
    p=new node;
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data) r->lchild=p;
    else r->rchild=p;
}
void Inorder(struct node *p)
{
    if(p){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }
}
struct node *search(int key)
{
    struct node *t=root;
    while(t!=NULL){
        if(key==t->data) return t;
        else if(key<t->data) t=t->lchild;
        else t=t->rchild;
    }
    return NULL;
};
struct node *Rinsert(struct node *p,int key)
{
    struct node *t=NULL;
    if(p==NULL){
        t=new node;
        t->data=key;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(key<p->data){
        p->lchild=Rinsert(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=Rinsert(p->rchild,key);
    }
    return p;
};
int Height(struct node *p){
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
struct node *Inpre(struct node *p)
{
    while(p && p->rchild !=NULL)
        p=p->rchild;
    return p;
}
struct node *Insuc(struct node *p)
{
    while(p && p->lchild !=NULL)
        p=p->lchild;
    return p;
}
struct node *Delete(struct node *p,int key)
{
    struct node *q;
    if(p==NULL) return NULL;
    if(p->lchild==NULL && p->rchild==NULL){
        if(p==root) root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data){
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data){
        p->rchild=Delete(p->rchild,key);
    }
    else{
         if(Height(p->lchild)>Height(p->rchild)){
               q=Inpre(p->lchild);
               p->data=q->data;
               p->lchild=Delete(p->lchild,q->data);
         }
         else{
            q=Insuc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
         }
    }
    return p;
}
int main()
{
    root=Rinsert(root,10);
    Rinsert(root,5);
    Rinsert(root,6);
    Rinsert(root,8);
    Rinsert(root,9);
    Inorder(root);
    cout<<endl;
    struct node *tmp;
    tmp=search(6);
    if(tmp!=NULL){
        cout<<"found\n";
    }
    else{
        cout<<"not found\n";
    }
    Delete(root,8);
    Inorder(root);

}
