class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    pair<bool,int> ischeck(Node *root){
        if(root==NULL){
            return make_pair(true,0);
        }
        pair<bool,int>left=ischeck(root->left);
        pair<bool,int>right=ischeck(root->right);
        bool op1=left.first;
        bool op2=right.first;
        int h1=left.second;
        int h2=right.second;
        bool h=abs(h1-h2)<=1;
        pair<bool,int>ans;
        ans.second=max(h1,h2)+1;
        if(op1 && op2 && h){
            ans.first=true;
            return ans;
        }
        else{
            ans.first=false;
            return ans;
        }
        
        
        
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return ischeck(root).first;
    }
};
