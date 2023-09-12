queue<int> modifyQueue(queue<int> q, int k) {
    // add code here.
    stack<int>st;
    for(int i=0;i<k;i++){
        int ele=q.front();
        st.push(ele);
        q.pop();
    }
    while(!(st.empty()))
    {
        int ele=st.top();
        q.push(ele);
        st.pop();
    }
    int n=q.size();
    for(int i=0;i<n-k;i++){
        int ele=q.front();
        q.pop();
        q.push(ele);
    }
    return q;
    
    
    
}
