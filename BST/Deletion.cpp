node* minvalue(node* root){
    node* temp=root;
    while(temp->left){
        temp=temp->left;
    }
    return temp;

}
node* maxvalue(node* root){
    node* temp=root;
    while(temp->right){
        temp=temp->right;
    }
    return temp;

}
node* deletion(node* root,int x){
    if(root==NULL){
        return NULL;
    }
    if(root->data==x){
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        if(root->left!=NULL && root->right==NULL){
            node* temp=root->left;
            delete root;
            
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }
        if(root->left!=NULL && root->right!=NULL){
            node* temp=minvalue(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
            return root;

        }
    }
    if(root->data>x){
        root->left=deletion(root->left,x);
        return root;
    }
    else{
        root->right=deletion(root->right,x);
        return root;
    }
}
