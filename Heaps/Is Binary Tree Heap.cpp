class Solution {
  public:
    int countnode(struct Node* tree){
        
        if(tree==NULL)
        {
            return 0;
        }
        int ans=1+countnode(tree->left)+countnode(tree->right);
        return ans;
    }
    bool iscbt(struct Node* tree,int i,int total){
        if(tree==NULL){
            return true;
        }
        if(i>=total){
            return false;
        }
        
        bool left=iscbt(tree->left,2*i+1,total);
        bool right=iscbt(tree->right,2*i+2,total);
        return (left&&right);
    }
    bool checkmh(struct Node* root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        if(root->right==NULL){
            return (root->data>root->left->data);
        }
        else{
            bool bh=((root->data>root->left->data)&&(root->data>root->right->data));
            bool left=checkmh(root->left);
            bool right=checkmh(root->right);
            return (bh&&left&&right);
        }
    }
    bool isHeap(struct Node* tree) {
        // code here
        int index=0;
        int nodecount=countnode(tree);
        if(iscbt(tree,index,nodecount)&&(checkmh(tree))){
            return true;
        }
        return false;
    }
};
