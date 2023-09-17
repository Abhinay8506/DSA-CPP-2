vector<int> diagonal(Node *root)
{
   // your code here
   vector<int>v;
   if(root==NULL){
       return v;
   }
   map<int,vector<int>,greater<int>>nodes;
   queue<pair<Node*,int>>q;
   q.push(make_pair(root,0));
   while(!q.empty()){
       pair<Node*,int>temp=q.front();
       q.pop();
       Node* node=temp.first;
       int hd=temp.second;
       while(node){
           nodes[hd].push_back(node->data);
           if(node->left){
             q.push(make_pair(node->left,hd-1));
           }
           node=node->right;
       }
       
       
   }
   for(auto j:nodes){
       for(auto i:j.second){
           v.push_back(i);
       }
   }
   return v;
   
}
