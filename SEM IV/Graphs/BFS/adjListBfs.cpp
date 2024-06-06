#include"bits/stdc++.h"
using namespace std;
#define max 10

class node{
public:
    int ver;
    node* next;
    node(int d):ver(d),next(NULL){}
    node():next(NULL),ver(0){}
};

class Graph{
    node* heads[max];
    int n;
    int visited[max];
public:
    Graph(){
        for(int i=0;i<max;i++){
            heads[i] = NULL;
        }
        for(int i=0;i<max;i++){
            visited[i] = 0;
        }
    }

    void create(){
        node *curr, *prev;
        int cn,i,j,v;
        bool done = false;
        cout<<"Enter Number of Vertices : ";
        cin>>n;
        for(i=0;i<n;i++){
            if(!(heads[i] = new node())){
                cout<<"Insufficient Memory"<<endl;
                return;
            }
            heads[i]->ver = i+1;
            cout<<"Enter Number of edges connected to vertex "<<(i+1)<<" = ";
            cin>>cn;
            prev = heads[i];
            for(j=0;j<cn;j++){
                if(!(curr = new node())){
                    cout<<"Insufficient Memory"<<endl;
                    return;
                }
                done = false;
                do{
                    cout<<"Enter Vertex Number of Connected Vertex = ";
                    cin>>v;
                    if(v>n || v<1){
                        cout<<"Invalid Vertex"<<endl;
                    }else{
                        curr->ver = v;
                        prev->next = curr;
                        prev = curr;
                        prev->next = NULL;
                        done = true;
                    }
                }while(!done);
            }
            if(cn==0)
                prev->next = NULL;
        }
        return;
    }

    void dispList(){
        for(int i=0;i<n;i++){
            node* temp = heads[i];
            while(temp){
                cout<<temp->ver<<" -> ";
                temp = temp->next;
            }cout<<"NULL"<<endl;
        }
    }

    void BFS(int v);
};

void Graph::BFS(int v){
    queue<node* > q;
    node* curr;
    visited[v] = true;
    cout<<heads[v]->ver<<" ";
    q.push(heads[v]);
    while(!q.empty()){
        curr = q.front();
        q.pop();
        curr = curr->next;
        while(curr){
            if(!visited[curr->ver - 1]){
                q.push(heads[curr->ver - 1]);
                cout<<curr->ver<<" ";
                visited[curr->ver - 1] = true;
            }
            curr = curr->next;
        }
    }
}

int main(){
    Graph g;
    g.create();
    g.dispList();
    g.dispList();
    cout<<"BFS"<<endl;
    g.BFS(0);
    return 0;
}