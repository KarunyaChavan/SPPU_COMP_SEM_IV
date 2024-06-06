#include "bits/stdc++.h"
using namespace std;
#define max 20

class Graph{
    int visited[max];
    int adj[max][max];
    int n;
public:
    Graph(){
        cout<<"Enter Number of Vertices : ";
        cin>>n;
        for(int i=0;i<n;i++){
            visited[i] = 0;
            for(int j=0;j<n;j++)
                adj[i][j] = 0;
        }
    }

    void refresh(){
        for(int i=0;i<n;i++){
            visited[i] = 0;
        }
    }

    void create(){
        int dir,ngbs,data;
        cout<<"Press 1 for Undirected Graph.\nPress 2 for Directed Graph.\n = ";
        cin>>dir;
        for(int i=0;i<n;i++){
            if(dir==1)
                cout<<"Enter Number of Neighbours of Vertex "<<(i+1)<<" = ";
            else
                cout<<"Enter Number of Outgoing Edges from Vertex "<<(i+1)<<" = ";
            cin>>ngbs;
            for(int j=0;j<ngbs;j++){
                cout<<"Enter Neighbour Vertex "<<(j+1)<<" = ";
                cin>>data;
                adj[i][data-1] = 1;
            }  
        }
    }

    void displayMat(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<adj[i][j]<<" ";
            cout<<endl;
        }
    }

    void DFS(int v){
        refresh();
        stack<int > s;
        s.push(v);
        int j;
        while(!s.empty()){
            j = s.top();
            s.pop();
            if(!visited[j]){
                cout<<j+1<<" ";
                visited[j] = 1;
            }
            for(int k=0;k<n;k++){
                if(adj[j][k]==1 && !(visited[k]))
                    s.push(k);
            }
        }
    }

    void BFS(int v){
        refresh();
        queue<int > q;
        q.push(v);
        visited[v] = 1;
        int j;
        while(!q.empty()){
            j = q.front();
            cout<<j+1<<" ";
            q.pop();
            for(int k=0;k<n;k++){
                if(adj[j][k]==1 && !(visited[k])){
                    q.push(k);
                    visited[k] = 1;
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.create();
    g.displayMat();
    cout<<"DFS"<<endl;
    g.DFS(0);
    cout<<"\nBFS"<<endl;
    g.BFS(0);
    return 0;
}