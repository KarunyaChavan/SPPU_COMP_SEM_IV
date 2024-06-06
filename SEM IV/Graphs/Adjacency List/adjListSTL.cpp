#include "bits/stdc++.h"
using namespace std;

class Graph{
public:
    unordered_map<int,list<int> > adj;

    void addEdge(int u,int v, bool d){
        /*d implies whether its directed or not
        if d = 0 -> undirected
        if d = 1 -> directed
        */
        adj[u].push_back(v);
        if(d==0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" -> ";
            }cout<<endl;
        }
    } 
};

int main(){
    int m,n;
    cout<<"Enter number of Vertices = ";
    cin>>m;
    cout<<"Enter number of Edges = ";
    cin>>n;
    Graph g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,1);
    }
    g.printAdjList();
    return 0;
}