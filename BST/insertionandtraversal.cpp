#include<bits/stdc++.h>
using namespace std;
class node{
    public:
     int data;
     node* left;
     node* right;
     node(int val){
      this->data=val;
      this->left=NULL;
      this->right=NULL;
     }
};
node* insertbst(node* root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
    if(root->data<val){
        root->right=insertbst(root->right,val);
    }
    else{
        root->left=insertbst(root->left,val);
    }
    return root;
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
void creationbst(node* &root){
    int val;
    cin>>val;
    while(val!=-1){
      root=insertbst(root,val);
      cin>>val; 
    }
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

int main(){
    node* root=NULL;
    creationbst(root);
    cout<<"\n";
    levelorder(root);
    cout<<endl<<"preorde:";
    preorder(root);
    cout<<endl<<"inorder:";
    inorder(root);
    cout<<endl<<"postorder:";
    postorder(root);
    return 1;
}
