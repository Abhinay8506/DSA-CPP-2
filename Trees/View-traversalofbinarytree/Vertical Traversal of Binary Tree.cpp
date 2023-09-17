class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map< int, map<int,vector<int> > >nodes;
        queue< pair< Node*, pair<int,int> > >q;
        vector<int>ans;
        if(root==NULL){
            return ans;
        }
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*,pair<int,int> >temp=q.front();
            q.pop();
            Node* fnode=temp.first;
            int hd=temp.second.first;
            int lv=temp.second.second;
            nodes[hd][lv].push_back(fnode->data);
            if(fnode->left){
                q.push(make_pair(fnode->left,make_pair(hd-1,lv+1)));
            }
            if(fnode->right){
                q.push(make_pair(fnode->right,make_pair(hd+1,lv+1)));
            }
        }
        for(auto i: nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
