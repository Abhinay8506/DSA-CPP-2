class Solution
{
    public:
    pair<bool,int> ischeck(Node*root)
    {      if(root==NULL)
           {
            return make_pair(true,0);
           }
           if(root->left==NULL && root->right==NULL){
               return make_pair(true,root->data);
           }
           pair<bool,int> left=ischeck(root->left);
           pair<bool,int> right=ischeck(root->right);
           bool op1=left.first;
           bool op2=right.first;
           bool op=(root->data==(left.second+right.second));
           pair<bool,int>ans;
           if(op1&& op2&& op){
               ans.first=true;
               ans.second=2*root->data;
               return ans;
           }
           ans.first=false;
           return ans;
           
           
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         return ischeck(root).first;
    }
};
