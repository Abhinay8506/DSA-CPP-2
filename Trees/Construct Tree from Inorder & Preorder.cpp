class Solution{
    public:
    int find(int in[],int ele,int s,int e){
        for(int i=s;i<=e;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index,int s,int e,int n){
        if(index>=n||s>e){
            return NULL;
        }
        int ele=pre[index++];
        int pos=find(in,ele,s,e);
        Node* root=new Node(ele);
        
        root->left=solve(in,pre,index,s,pos-1,n);
        root->right=solve(in,pre,index,pos+1,e,n);
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int index=0;
        Node* temp=solve(in,pre,index,0,n-1,n);
        return temp;
    }
};
