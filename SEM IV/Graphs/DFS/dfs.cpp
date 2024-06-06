#include"iostream"
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
    int visited[max];
public:
    int n;
    Graph(){
        for(int i=0;i<max;i++){
            heads[i] = NULL;
            visited[i] = false;
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

    void DFS(int v);
};

void Graph::DFS(int v){
    node* curr = heads[v];
    int w;
    if(!visited[curr->ver - 1])
        cout<<curr->ver<<" -> ";
    visited[v] = true;
    curr = curr->next;
    while(curr!=NULL){
        if(!(visited[w=(curr->ver - 1)]))
            DFS(w);
        curr = curr->next;
    }
    return;
}

int main(){
    Graph g;
    g.create();
    g.dispList();
    cout<<"DFS"<<endl;
    for(int i=0;i<g.n;i++){
        g.DFS(i);
    }
    return 0;
}