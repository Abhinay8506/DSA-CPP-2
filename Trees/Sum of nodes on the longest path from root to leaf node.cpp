class Solution
{
public:
    void solve(Node* root,int sum,int len,int &maxlen,int &maxsum ){
        if(root==NULL){
            if(len>maxlen){
                maxlen=len;
                maxsum=sum;
            }
            else if(len==maxlen){
                maxsum=max(sum,maxsum);
            }
            return;
        }
        sum+=root->data;
        solve(root->left,sum,len+1,maxlen,maxsum);
        solve(root->right,sum,len+1,maxlen,maxsum);
    } 
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int sum=0;
        int len=0;
        int maxlen=0;
        int maxsum=INT_MIN;
        solve(root,sum,len,maxlen,maxsum);
        return maxsum;
    }
};
