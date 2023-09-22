pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode *temp=root;
    int pre=-1;
    int suc=-1;
    while(temp!=NULL && temp->data!=key){
        if(temp->data>key){
            suc=temp->data;
            temp=temp->left;
        }
        else{
            pre=temp->data;
            temp=temp->right;
        }
    }
    if(temp!=NULL){
       TreeNode *tleft=temp->left;
    while(tleft!=NULL){
        pre=tleft->data;
        tleft=tleft->right;
    }
    TreeNode *tright=temp->right;
    while(tright!=NULL){
        suc=tright->data;
        tright=tright->left;
    }
    
    }
    pair<int,int>ans=make_pair(pre,suc);
    return ans; 
    

}
