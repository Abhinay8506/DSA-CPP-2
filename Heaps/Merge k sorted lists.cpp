#include<bits/stdc++.h>
using namespace std;
/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;
    }
};
Node* mergeKLists(vector<Node*> &arr){
    // Write your code here.
    priority_queue<Node*,vector<Node*>,compare>pq;
    int k=arr.size();
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    Node* head=NULL;
    Node* tail=NULL;
    while(pq.size()>0){
        Node* top=pq.top();
        pq.pop();
        if(top->next!=NULL){
            pq.push(top->next);
        }
        if(head==NULL){
            head=top;
            tail=top;
        }
        else{
           tail->next=top;
           tail=top;
        }
    }
    return head;
}
