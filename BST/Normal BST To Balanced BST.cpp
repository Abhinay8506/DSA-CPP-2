void inorder(TreeNode<int>* root,vector<int>&ans){
    if(root==NULL)
    {  return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
TreeNode<int>* inbst(int s,int e,vector<int>ans){
    if(s>e)
    {
        return NULL;
    }
    int mid=s+(e-s)/2;
    TreeNode<int>* curr=new TreeNode<int>(ans[mid]);
    curr->left=inbst(s,mid-1,ans);
    curr->right=inbst(mid+1,e,ans);
    return curr;

}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.
    vector<int>ans;
    inorder(root,ans);
    return inbst(0,ans.size()-1,ans);

}
