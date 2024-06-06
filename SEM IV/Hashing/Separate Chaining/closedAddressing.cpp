#include "iostream"
using namespace std;
#define MAX 10

class node{
    public:
        int key;
        node* next;
        node(int k): key(k), next(NULL){}
};

class Hashing{
    node* table[MAX];
public:
    Hashing(){
        for(int i=0; i<MAX; i++)
            table[i] = NULL;
    }

    int hash(int key){
        return (key%MAX);
    }

    void insert(int key){
        node* temp = new node(key);
        int index = hash(key);
        if(table[index]==NULL) 
            table[index] = temp;
        else{
            node* ptr = table[index];
            while(ptr->next){
                ptr = ptr->next;
            }
            ptr->next = temp; 
        }
    }

    void display(){
        node* curr;
        cout<<"INDEX\t DATA"<<endl;
        for(int i=0; i<MAX; i++){
            curr = table[i];
            cout<<" "<<i<<"   --   ";
            while(curr){
                if(curr->next==NULL)
                    cout<<curr->key;
                else
                    cout<<curr->key<<" -> ";
                curr = curr->next;
            }cout<<endl;
        }
    }

    void search(int x){
        node* curr;
        int index = hash(x);
        curr = table[index];
        while(curr && curr->key != x){
            curr = curr->next;
        }
        if(curr==NULL)
            cout<<"NOT FOUND"<<endl;
        else cout<<"FOUND"<<endl;
    }
};

int main(){
    Hashing h;
    for(int i=1; i<=5; i++)
        h.insert(i);
    for(int i=1; i<=5; i+=2)
        h.insert(i);
    h.insert(13);
    h.insert(15);
    h.display();
    return 0;
}