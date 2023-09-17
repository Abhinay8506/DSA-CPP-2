class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void solve(Node* root,vector<int>&ans,int l){
    if(root==NULL){
        return;
    }
    if(l==ans.size()){
        ans.push_back(root->data);
    }
    solve(root->right,ans,l+1);
    solve(root->left,ans,l+1);
    
}

    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       solve(root,ans,0);
       return ans;
    }
};
