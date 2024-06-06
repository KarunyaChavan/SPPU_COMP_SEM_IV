#include "iostream"
using namespace std;
#define max 10

class node{
public:
    int ver;
    node* next;
    int links[max];
    node():ver(0),next(NULL){}
    node(int data):ver(data),next(NULL){}
};

class Graph{
    node* vertices[max];
public:
    int n;
    node* adj[max][max];
    
    Graph(){
        for(int i=0;i<max;i++){
            for(int j=0;j<max;j++){
                adj[i][j] = NULL;
            }
        }
    }

    void create(){
        int cn,d,flag;
        cout<<"Press 1 for Undirected Graph.\nPress 2 for Directed Graph.\n = ";
        cin>>flag;
        cout<<"Enter Number of vertices = ";
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j] = new node();
                for(int k=0;k<n;k++){
                    adj[i][j]->links[k] = 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(flag==1)
                cout<<"Enter Number of Neighbours of Vertex "<<(i+1)<<" = ";
            else
                cout<<"Enter Number of OutDegree of Vertex "<<(i+1)<<" = ";
            cin>>cn;
            int k = 0;
            for(int j=0;j<cn;j++){
                cout<<"Enter neighbour "<<(j+1)<<" = ";
                cin>>d;
                adj[i][d-1]->ver = 1;
                adj[i][0]->links[k] = d;
                ++k;
            }
        }
    }

    void displayAdjacentsOf(int k){
        for(int i=0;i<n;i++){
            if((adj[k][0]->links[i])!=0)
                cout<<(adj[k][0]->links[i])<<" --> ";
            else break;
        }cout<<endl;
    }

    void displayMat(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<adj[i][j]->ver<<" ";
            }
            cout<<endl;
        }
    }

};

int main(){
    Graph g;
    g.create();
    g.displayMat();
    g.displayAdjacentsOf(0);
    return 0;
}