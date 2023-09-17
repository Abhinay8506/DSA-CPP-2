class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here
       if(root==NULL){
           return NULL;
       }
       if(root->data==n1 || root->data==n2){
           return root;
       }
       Node* aleft=lca(root->left,n1,n2);
       Node* aright=lca(root->right,n1,n2);
       if(aleft!=NULL && aright!=NULL){
           return root;
       }
       else if(aleft!=NULL && aright==NULL){
           return aleft;
       }
       else if(aleft==NULL && aright!=NULL){
           return aright;
       }
       else{
           return NULL;
       }
    }
};
