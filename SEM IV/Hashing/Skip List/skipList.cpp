#include "bits/stdc++.h"
using namespace std;

class Node{
public:
    int key;
    Node **forward;
    Node(int val, int level){
        key = val;
        forward = new Node*[level+1];
        memset(forward,0,sizeof(Node*)*(level+1));
    }
};

class SkipList{
    int MAXLVL;
    float P;
    int level;
    Node *header;
public:
    SkipList(int max, float p){
        MAXLVL = max;
        P = p;
        level = 0;
        header = new Node(-1, MAXLVL);
    }

    int randomLevel(){
        float r = (float)rand()/RAND_MAX;
        int lvl = 0;
        while(r<P && lvl<MAXLVL){
            lvl++;
            r = (float)rand()/RAND_MAX;
        }
        return lvl;
    }

    Node* createNode(int key, int level){
        Node* n = new Node(key, level);
        return n;
    }

    void insert(int key){
        Node *curr = header;
        Node *update[MAXLVL+1];
        memset(update,0,sizeof(Node*)*(MAXLVL+1));
        for(int i=level; i>=0; i--){
            while(curr->forward[i]!=NULL && curr->forward[i]->key<key)
                curr = curr->forward[i];
            update[i] = curr;
        }
        curr = curr->forward[0];
        if(curr==NULL || curr->key!=key){
            int rlvl = randomLevel();
            if(rlvl > level){
                for(int i=level+1; i<rlvl+1;i++){
                    update[i] = header;
                }
                level = rlvl;
            }
            Node *n = createNode(key,rlvl);
            for(int i=0;i<=rlvl;i++){
                n->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = n;
            }
            cout<<"Successfully Inserted "<<key<<endl;
        }
    }

    void display(){
        for(int i=0; i<=level; i++){
            Node* node = header->forward[i];
            cout<<"LEVEL "<<i<<" : ";
            while(node){
                cout<<node->key<<"  ";
                node = node->forward[i];
            }cout<<endl;
        }
    }
};

int main(){
    SkipList lst(3,0.5);
    for(int i=1;i<=15;i++){
        lst.insert(i);
    }
    lst.display();
    return 0;
}