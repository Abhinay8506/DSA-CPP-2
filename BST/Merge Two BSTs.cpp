void inorder(TreeNode* root,vector<int>&arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}
void merge(vector<int>&ans,vector<int>arr1,vector<int>arr2){
    int i=0;
    int j=0;
    int len1=arr1.size();
    int len2=arr2.size();
    while(i<len1 && j<len2){
        if(arr1[i]<arr2[j]){
            ans.push_back(arr1[i++]);
        }
        else{
            ans.push_back(arr2[j++]);
        }
    }
    while(i<len1){
       ans.push_back(arr1[i++]);
    }
    while(j<len2){
        ans.push_back(arr2[j++]);
    }
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int>arr1;
    vector<int>arr2;
    inorder(root1,arr1);
    inorder(root2,arr2);
    vector<int>ans;
    merge(ans,arr1,arr2);
    return ans;
}
