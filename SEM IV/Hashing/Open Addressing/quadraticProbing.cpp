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
		return (2*key + 3%MAX);
	}

	int insert(int key){
		int index = hash(key);
		for(int i=0; i%MAX!=index; i++){
			index = (index + i*i)%MAX;
			if(table[index]==0){
				table[index] = key;
				return index;
			 }
		}
		cout<<"TABLE OVERFLOW"<<endl;
		return -1;
	}

	void search(int x){
		int index = hash(x);
		for(int i=0; i<(MAX-1)/2; i++){
			index = (index + i*i)%MAX;
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
	int d;
	for(int i=0; i<10; i++){
		cout<<"Enter Data : ";
		cin>>d;
		h.insert(d);
	}
	h.display();
	return 0;
}