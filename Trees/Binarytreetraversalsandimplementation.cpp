#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int val)
    {   this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};
node* buildtree(node* root){
    int item;
    cout<<"enter data:";
    cin>>item;
    root=new node(item);
    if(item==-1){
        return NULL;
    }
    cout<<"data in left of:"<<item;
    root->left=buildtree(root->left);
    cout<<"data in right of:"<<item;
    root->right=buildtree(root->right);
    return root;

}
void levelorder(node* root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* t=q.front();
        q.pop();
        if(t==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<t->data<<' ';
            if(t->left){
                q.push(t->left);
            }
            if(t->right){
                q.push(t->right);
            }
        }
    }
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){
   node* root=NULL;
   root=buildtree(root);

   levelorder(root);
   cout<<"INORDER: ";
   inorder(root);
   cout<<"Pre order: ";
   preorder(root);
   cout<<"post order: ";
   postorder(root);
   return 0;

}
