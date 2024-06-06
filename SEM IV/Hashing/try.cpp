#include "iostream"
using namespace std;

int main(){
    int c = 0;
    for(int i=2;i<=20;i++){
        int flag = 0;
        for(int j=2;j<i;j++){
            if(i%j==0){
                flag = 1;
                break;
            }
        }
        if(flag==0){
            c++;
        }
    }
    cout<<c<<endl;
}