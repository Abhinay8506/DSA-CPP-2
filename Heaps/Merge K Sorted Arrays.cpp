#include <bits/stdc++.h> 
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
vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here.
    vector<int>ans;
    priority_queue<node*,vector<node*>,compare>pq;
    for(int i=0;i<k;i++){
         node* top=new node(arr[i][0],i,0);
         pq.push(top);
    }
    while(pq.size()>0){
        node* top=pq.top();
        ans.push_back(top->data);
        pq.pop();
        int r=top->i;
        int c=top->j;
        if (c + 1 < arr[r].size()) {
          node *news = new node(arr[r][c + 1], r, c + 1);
          pq.push(news);
        }
    }
    return ans;
}

