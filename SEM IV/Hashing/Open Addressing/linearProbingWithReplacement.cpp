#include "iostream"
using namespace std;
#define MAX 10

class Hashing{
    int table[MAX];
public:
    Hashing(){
        for(int i=0;i<MAX;i++)
            table[i] = 0;
    }

    int hash(int key){
        return (key%MAX);
    }

    int insert(int key){
        int index = hash(key);
        if(table[index]==0){
            table[index] = key;
            return index;
        }
        else if(hash(table[index])!=index){
                    int data = table[index];
                    table[index] = key;
                    int i = index+1;
                    while(i%MAX!=index){
                        if(table[i]==0){
                            table[i] = data;
                            break;
                        }
                        i = (i+1)%MAX;
                    }
                    return i;  
                }
        else{
            for(int i=index+1; i%MAX!=index; i++){
                if(table[i]==0){
                    table[i] = key;
                    return i;
                }
            }
        }
        cout<<"TABLE OVERFLOW"<<endl;
        return -1;
    }

    void search(int key){
        int index = hash(key);
        if(table[index]==key){
            cout<<"FOUND"<<endl;
            return;
        }else{
            for(int i=index+1; i%MAX!=index; i++){
                if(table[i]==key){
                    cout<<"FOUND"<<endl;
                    return;
                }
            }
        }
        cout<<"NOT FOUND"<<endl;
    }

    void display(){
        cout<<"\nINDEX \t DATA"<<endl;
        for(int i=0; i<MAX; i++){
            cout<<" "<<i<<"    ->  "<<table[i]<<endl;
        }
    }

};

int main(){
    Hashing h;
    int data;
    for(int i=0;i<10;i++){
        cout<<"Enter Data "<<i+1<<" = ";
        cin>>data;
        h.insert(data);
    } 
    h.display();
    //12 1 4 3 7 8 10 2 5 14 6 28
    return 0;
}