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

	int hash1(int key){
		return (key%MAX);
	}

    int hash2(int key){
        return (7 - (key%7));
    }

	int insert(int key){
		int index = hash1(key);
		for(int i=0; i%MAX!=index; i++){
			index = (hash1(key) + i*hash2(key))%MAX;
			if(table[index]==0){
				table[index] = key;
				return index;
			 }
		}
		cout<<"TABLE OVERFLOW"<<endl;
		return -1;
	}

	void search(int x){
		int index = hash1(x);
		for(int i=0; i<(MAX-1)/2; i++){
			index = (hash1(x) + i*hash2(x))%MAX;
			if(table[index]==x){
				cout<<"INDEX : "<<index<<" -- "<<x<<endl;
				cout<<"FOUND"<<endl;
				return;
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
	for(int i=1; i<=4; i++)
		h.insert(i);
	h.insert(13);
	h.insert(33);
	h.insert(25);
	h.insert(15);
	h.display();
	h.search(12);
	return 0;
}