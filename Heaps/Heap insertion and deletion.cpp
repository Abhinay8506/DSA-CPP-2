#include<bits/stdc++.h>
using namespace std;
class heap{
  public:
   int arr[100];
   int size;
   heap(){
    arr[0]=-1;
    size=0;
   }
   void insert(int val){
     size=size+1;
     int index=size;
     arr[index]=val;
     while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[index],arr[parent]);
            index=parent;
        }
        else{
            
            return;
        }
     }
   }
  void print(){
    for(int i=1;i<=size;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
  }
  void deletionfromlast(){
    if(size==0){
        cout<<"Underflow"<<endl;
        return;
    }
    arr[1]=arr[size];
    size--;
    int i=1;
    while(i<size){
        int left=2*i;
        int right=2*i+1;
        if(left<size && arr[i]<arr[left]){
            swap(arr[left],arr[i]);
            i=left;
        }
        else if(right<size && arr[i]<arr[right])
        {  swap(arr[right],arr[i]);
           i=right;
        }
        else{
            return;
        }
    }
  }
 

   
};
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }

}
int main(){
    heap h;
    int n1;
    cin>>n1;
    int value;
    for(int i=0;i<n1;i++){
        cin>>value;
        h.insert(value);
    }
    h.print();
    h.deletionfromlast();
    h.print();
    h.deletionfromlast();
    h.print();
    int n=7;
    int arr[n]={-1,2,3,4,6,10,8};
   
    for(int i=n-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    

    
}
