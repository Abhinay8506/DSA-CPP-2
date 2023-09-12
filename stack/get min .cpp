class MinStack {
public:
    stack<int>st;
    unsigned int mini;
    
    void push(int val) {
        if(st.size()==0){
          st.push(val);
          mini=val;
        }
        else{
            if(val<mini){
               unsigned int data=2*val-mini;
               st.push(data);
               mini=val;
            }
            else{
               st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top()>mini){
            st.pop();
        }
        else
        {
            unsigned int prev=mini;
            mini=2*mini-st.top();
            
            st.pop();
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;

        }
        unsigned int curr=st.top();
        if(curr<mini){
            return mini;
        }
        else
        {
            return curr;
        }
    }
    
    int getMin() {
        return mini;
    }
};
