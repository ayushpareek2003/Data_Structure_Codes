#include <bits/stdc++.h>
using namespace std;
    struct node{
        int data;
        node* next;
    };
struct listp{
        node* head;

    };
    struct graph{
        int v;
        listp* mat;

    };
    graph* newGraph(int v){
        graph *G=new graph;
        G->v=v;
        G->mat=new listp[v];
        for(int g=0;g<v;g++){
            G->mat[g].head=NULL;
        } 
        return G;     
    }
    node* newNode(int q){
        node* np=new node;
        np->data=q;
        np->next=NULL;
        return np;

    }
    void add(graph* G,int s,int d){
        node* temp=newNode(d);
        temp->next=G->mat[s].head;
        G->mat[s].head=temp;
        temp=newNode(s);
        temp->next=G->mat[d].head;
        G->mat[d].head=temp;

    }
    void print(graph* g){
        for(int x=0;x<g->v;x++){
            node* te=g->mat[x].head;
            while(te!=NULL){
                cout<<te->data<<"->";
                te=te->next;

            }
            cout<<endl;
        }
    }



