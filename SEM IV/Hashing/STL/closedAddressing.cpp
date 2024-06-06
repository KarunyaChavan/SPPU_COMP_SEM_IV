#include "iostream"
#include "list"
#include "algorithm"
#include "vector"
using namespace std;

class Hashing{
    vector< list<int> > hashtable;
    int buckets;
public:
    Hashing(int size){
        buckets = size;
        hashtable.resize(size);
    }

    int hashval(int key){
        return (key%buckets);
    }

    void add(int key){
        int idx = hashval(key);
        hashtable[idx].push_back(key);
    }

    list<int>::iterator searchKey(int key){
        int idx = hashval(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(),key);
    }

    void deleteKey(int key){
        int idx = hashval(key);
        if(searchKey(key)!=hashtable[idx].end()){
            hashtable[idx].erase(searchKey(key));
            cout<<key<<" has been Erased"<<endl;
        }else{
            cout<<"Key Not Found"<<endl;
        }
    }
};

int main(){
    Hashing h(10);
    h.add(2);
    h.add(1);
    h.add(0);
    h.add(5);

    h.deleteKey(5);
    h.deleteKey(9);
}