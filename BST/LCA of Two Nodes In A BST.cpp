TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    while(root!=NULL){
        if(root->data>P->data && root->data>Q->data){
            root=root->left;
        }
        if(root->data<P->data && root->data<Q->data){
            root=root->right;
        }
        else{
            return root;
        }
    }
}
