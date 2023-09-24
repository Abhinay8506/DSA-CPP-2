#include <bits/stdc++.h>
void heapify(vector<int>&arr,int i){
   int small=i;
   int left=2*i+1;
   int right=2*i+2;
   if(left<arr.size()&& arr[left]<arr[i]){
       small=left;
   }
   if(right<arr.size()&& arr[right]<arr[small]){
       small=right;
   }
   if(small!=i){
       swap(arr[i],arr[small]);
       heapify(arr,small);
   }
}
void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
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
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    for(int i=arr.size()-1;i>=0;i--){
        heapify(arr,i);
    }
    
    return arr;



}
