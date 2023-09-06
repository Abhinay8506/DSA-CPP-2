#include<bits/stdc++.h>
using namespace std;
class stacks{
 public:
    int top;
    int size;
    char*arr;

    stacks(int s){
        arr=new char[s];
        size=s;
        top=-1;
    }
    void push(char num){
        if(size-top>1)
        {  
            arr[++top]=num;
        }
        else{
            cout<<"Stack overflow\n";
        }
    }
    char pop(){
        if(top>=0){
            return arr[top--];

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
    string st;
    getline(cin,st);
    int n=st.length();
    stacks s(n);
    for(int i=0;i<n;i++){
        s.push(st[i]);
    }
    string sp;
    for(int i=0;i<n;i++)
    {   char ch=s.pop();
        sp.push_back(ch);
    }
    cout<<sp;


}
