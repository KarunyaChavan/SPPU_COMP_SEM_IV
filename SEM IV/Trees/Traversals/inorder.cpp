#include "iostream"
#include "queue"
#include "stack"
using namespace std;

class node{
public:
    int key;
    node *Lchild, *Rchild;
    node(int val):key(val),Lchild(NULL),Rchild(NULL){}
};

class BST{
public:
    node* root;
    BST():root(NULL){}
    
    void insertNode(int key){
        node* new_node = new node(key);
        if(root==NULL){
            root = new_node;
            return;
        }
        node* temp = root;
        while(temp){
            if(temp->key>key){
                if(temp->Lchild==NULL){
                    temp->Lchild = new_node;
                    return;
                }
                temp = temp->Lchild;
            }
            else{
                if(temp->Rchild==NULL){
                    temp->Rchild = new_node;
                    return;
                }
                temp = temp->Rchild;
            }
        }
    }

    void breadthFirstTraversal(){
        cout<<"\n"<<endl;
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            if(temp==NULL){
                cout<<endl;
                if(!q.empty()) q.push(NULL);
            }else{
                cout<<temp->key<<" ";
                if(temp->Lchild)
                    q.push(temp->Lchild);
                if(temp->Rchild)
                    q.push(temp->Rchild);
            }
        }
    }

    void display(){
        stack<node*> s;
        s.push(root);
        int nb = 32;
        cout<<"-----------------------------------------------------------"<<endl;
        bool isRowEmpty = false;
        while(isRowEmpty==false){
            stack<node*> s1;
            isRowEmpty = true;
            for(int j=0;j<nb;j++){
                cout<<" ";
            }
            while(s.empty()==false){
                node* temp = s.top();
                s.pop();
                if(temp!=NULL){
                    cout<<temp->key;
                    s1.push(temp->Lchild);
                    s1.push(temp->Rchild);
                    if(temp->Lchild != NULL || temp->Rchild != NULL)
                        isRowEmpty = false;
                }
                else{
                    cout<<"--";
                    s1.push(NULL);
                    s1.push(NULL);
                }
                for(int j=0;j<nb*2-2;j++){
                    cout<<" ";
                } 
                }
                cout<<endl;
                nb /= 2;
                while(s1.empty()==false){
                    s.push(s1.top());
                    s1.pop();
                }
            }
            cout<<"-----------------------------------------------------------"<<endl;
        }
                                                                        
    void inorderIter1(){
        stack<node* > s;
        node* temp = root;
        while(true){
            while(temp){
                s.push(temp);
                temp = temp->Lchild;
            }
            if(s.empty()) return;
            temp = s.top();
            s.pop();
            cout<<temp->key<<"  ";
            temp =temp->Rchild;
        }
    }

    //Descending Order
    void inorderIter2(){
        stack<node* > s;
        node* temp = root;
        while(true){
            while(temp){
                s.push(temp);
                temp = temp->Rchild;
            }
            if(s.empty()) return;
            temp = s.top();
            s.pop();
            cout<<temp->key<<"  ";
            temp =temp->Lchild;
        }
    }

    void inorderRec(node* root){
        if(root==NULL) return;
        inorderRec(root->Lchild);
        cout<<root->key<<"  ";
        inorderRec(root->Rchild);
    }
};

int main(){
    BST b;
    int d;
    for(int i=0;i<7;i++){
        cout<<"Key - ";
        cin>>d;
        b.insertNode(d);
    }
    b.display();
    b.inorderIter2();
    cout<<endl;
    b.inorderRec(b.root);
    return 0;
}