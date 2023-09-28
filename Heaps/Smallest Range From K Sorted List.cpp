#include<bits/stdc++.h>
using namespace std;
class node{
   public:
   int data;
   int i;
   int j;
   node(int val,int r,int c){
       this->data=val;
       this->i=r;
       this->j=c;
   }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};
int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here
    priority_queue<node*,vector<node*>,compare>pq;
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<k;i++){
        pq.push(new node(a[i][0],i,0));
        mini=min(mini,a[i][0]);
        maxi=max(maxi,a[i][0]);
    }
    int ansstart=mini;
    int ansend=maxi;
    while(pq.size()>0){
        node* top=pq.top();
        mini=top->data;
        pq.pop();
        if((maxi-mini)<(ansend-ansstart)){
            ansstart=mini;
            ansend=maxi;
        }
        if(top->j +1<n)
        {
            maxi=max(maxi,a[top->i][top->j +1]);
            pq.push(new node(a[top->i][top->j +1],top->i,top->j +1));
        }
        else{
            break;
        }

    }
    return (ansend-ansstart+1);

}
