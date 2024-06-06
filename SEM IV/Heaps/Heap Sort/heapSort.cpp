#include "iostream"
using namespace std;
#define max 20
class node{
public:
    int data;
    node(int val):data(val){}
};

class Heap{
public:
    node* heapArr[max];
    int maxSize;
    int currSize;
    Heap(int size){
        maxSize = size;
        currSize = 0;
        for(int i=0;i<max;i++){
            heapArr[i] = NULL;
        }
    }

    void reHeapUp(int index){
        int parent = (index - 1)/2;
        node* bottom = heapArr[index];
        while(index > 0 && (heapArr[parent])->data < bottom->data){
            heapArr[index] = heapArr[parent];
            index = parent;
            parent = (parent-1)/2;
        }
        heapArr[index] = bottom;
    }

    void reHeapDown(int index){
        int larger;
        node* top = heapArr[index];
        while(index < currSize/2){
            int left = 2*index + 1;
            int right = left + 1;
            if(right < currSize && heapArr[left]->data < heapArr[right]->data){
                larger = right;
            }else{
                larger = left;
            }
            if(top->data >= heapArr[larger]->data){
                break;
            }
            heapArr[index] = heapArr[larger];
            index = larger;
        }
        heapArr[index] = top;
    }

    bool insert(int key){
        if(currSize==maxSize){
            return false;
        }
        node* new_node = new node(key);
        heapArr[currSize] = new_node;
        reHeapUp(currSize++);
        return true;
    }

    node* deleteNode(){
        node* root = heapArr[0];
        heapArr[0] = heapArr[--currSize];
        reHeapDown(0);
        return root;
    }    

    void display(){
        cout<<"Heap Array : ";
        for(int i=0;i<currSize;i++){
            if(heapArr[i]!=NULL){
                cout<<heapArr[i]->data<<" ";
            }
            else{
                cout<<"--";
            }
        }cout<<endl;
        int blanks = 32;
        int itemsPerRow = 1;
        int c = 0;
        int j = 0;
        string dots =  "...............................";
        cout<<(dots+dots)<<endl;
        while(currSize>0){
            if(c==0){
                for(int k=0;k<blanks;k++){
                    cout<<" ";
                }
            }
            cout<<heapArr[j]->data;
            if(++j==currSize)
                break;
            if(++c==itemsPerRow){
                blanks /= 2;
                itemsPerRow *= 2;
                c = 0;
                cout<<endl;
            }else{
                for(int k=0;k<blanks*2-2;k++)
                    cout<<" ";
            }
        }cout<<endl;
        cout<<dots+dots<<endl;
    }

    void displayArr(){
        for(int j=0; j<maxSize; j++)
            cout<<heapArr[j]->data<<" ";
        cout<<endl;
    }
};

void HeapSort(){
    int size,j,data;
    cout<<"Enter Number of Elements = ";
    cin>>size;
    Heap h(size);
    for(j=0;j<size;j++){
        cout<<"Enter Number "<<(j+1)<<" = ";
        cin>>data;
        node* new_node = new node(data);
        h.heapArr[j] = new_node;
        h.currSize++;
    }
    for(j=(size/2)-1;j>=0;j--)
        h.reHeapUp(j);
    cout<<"HEAP"<<endl;
    h.display();
    for(j=size-1;j>=0;j--){
        node* largest = h.deleteNode();
        h.heapArr[j] = largest;
    }
    cout<<"Sorted"<<endl;
    h.displayArr();
}

int main(){
    HeapSort();
    return 0;
}