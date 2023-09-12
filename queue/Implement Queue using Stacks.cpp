class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    
    
    void push(int x) {
       while(s1.size()>0){
           s2.push(s1.top());
           s1.pop();
       }
       s1.push(x);
       while(s2.size()>0){
           s1.push(s2.top());
           s2.pop();
       }
    }
    
    int pop() {
        int val=s1.top();
        s1.pop();
        return val; 
        
    }
    
    int peek() {
        return s1.top();
        
    }
    
    bool empty() {
        if(s1.empty())
        {
            return true;
        }
        return false;
    }
};
