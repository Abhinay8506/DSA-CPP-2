int find(int in[],int ele,int s,int e){
        for(int i=s;i<=e;i++){
            if(in[i]==ele){
                return i;
            }
        }
        return -1;
}
Node* solve(int in[],int post[],int &index,int s,int e,int n){
        if(index<0||s>e){
            return NULL;
        }
        int ele=post[index--];
        int pos=find(in,ele,s,e);
        Node* root=new Node(ele);
        root->right=solve(in,post,index,pos+1,e,n);
        root->left=solve(in,post,index,s,pos-1,n);
        return root;
        
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int i=n-1;
    Node* temp=solve(in,post,i,0,n-1,n);
    return temp;
}
