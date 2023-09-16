class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> dfast(Node*root){
        if(root==NULL){
            return make_pair(0,0);
        }
        pair<int,int>left=dfast(root->left);
        pair<int,int>right=dfast(root->right);
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second+1;
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    int diameter(Node* root) {
        // Your code here
        
        return dfast(root).first;
    }
};
