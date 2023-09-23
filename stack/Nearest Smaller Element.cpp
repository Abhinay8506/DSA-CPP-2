vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int>st;
    st.push(-1);
    vector<int>v;
    for(int i=0;i<A.size();i++){
        if(st.top()<A[i]){
            v.push_back(st.top());
            st.push(A[i]);
        }
        else{
            while(!(st.top()<A[i])){
                st.pop();
            }
            v.push_back(st.top());
            st.push(A[i]);
        }
    }
    return v;
}
