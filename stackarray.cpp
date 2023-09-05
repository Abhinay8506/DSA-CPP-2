#include<bits/stdc++.h>
using namespace std;
class stacks{
 public:
    int top;
    int size;
    int*arr;

    stacks(int s){
        arr=new int[s];
        size=s;
        top=-1;
    }
    void push(int num){
        if(size-top>1)
        {  
            arr[++top]=num;
        }
        else{
            cout<<"Stack overflow\n";
        }
    }
    void pop(){
        if(top>=0){
            cout<<"Popped element:"<<arr[top]<<endl;
            top--;

        }
        else{
           cout<<"underflow\n";
        }
    }
    void peak()
    { 
        cout<<"Peak element:"<<arr[top]<<endl;
    }
    bool isempty(){
        if(top<0)
        {
            return true;
        }
        return false;
    }
    bool isfull(){
        if(size-top==1){
            return true;
        }
        return false;
    }

};
int main(){
    int n;cin>>n;
    stacks s(n);
    char ch='Y';
    do{
        int m;
        cout<<"1.To push"<<endl<<"2.To pop"<<endl<<"3.For peak element"<<endl<<"4.For checking empty or not"<<endl<<"5.For checking full"<<endl;
        cout<<"Enter your choice:";
        cin>>m;
        switch(m){
            case 1:
              int item;
              cout<<"enter item to push:";
              cin>>item;
              s.push(item);break;
              
            case 2:
               s.pop();
               break;
            case 3:
               s.peak();
               break;
            case 4:
               cout<<s.isempty()<<endl;
               break;
            case 5:
               cout<<s.isfull()<<endl;
               break;
        }
        cout<<"do you want to continue(Y/N):";
        cin>>ch;
    }while(ch=='Y');
    return 0;

}
