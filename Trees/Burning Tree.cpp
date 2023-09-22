class Solution {
  public:
  
    Node* createmap(Node* root,int target,map<Node*,Node*>&mpp){
        queue<Node*>q;
        mpp[root]=NULL;
        q.push(root); 
        Node* ans=NULL;
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            if(temp->data==target){
                ans=temp;
            }
            if(temp->left){
                q.push(temp->left);
                mpp[temp->left]=temp;
            }
            if(temp->right){
                q.push(temp->right);
                mpp[temp->right]=temp;
            }
        }
        return ans;
    }
    int burntree(Node* root,map<Node*,Node*>mpp){
        map<Node*,bool>visit;
        queue<Node*>q;
        q.push(root);
        visit[root]=1;
        int ans=0;
        while(!q.empty()){
            bool flag=0;
            int size=q.size();
            for(int i=0;i<size;i++){
                Node* front=q.front();
                q.pop();
                if(front->left && !visit[front->left]){
                    flag=1;
                    q.push(front->left);
                    visit[front->left]=1;
                }
                if(front->right && !visit[front->right]){
                    flag=1;
                    q.push(front->right);
                    visit[front->right]=1;
                }
                if(mpp[front] && !visit[mpp[front]]){
                    flag=1;
                    q.push(mpp[front]);
                    visit[mpp[front]]=1;
                }
            }
            if(flag==1){
                ans++;
            }
            
        }
        return ans;
    }
    int minTime(Node* root, int target) 
    {   int ans=0;
        map<Node*,Node*>mpp;
        Node* temp=createmap(root,target,mpp);
        ans=burntree(temp,mpp);
        return ans;
    }
};
