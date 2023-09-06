//Using recursion
class Solution {
public:
    bool valid(string s,int i,string &stack){
        if(i==s.length()&&stack.length()==0){
            return true;
        }
        if((s[i]=='}'||s[i]==']'||s[i]==')')&&(stack.length()==0)){
           return false; 
        }
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            stack.push_back(s[i]);
        }
        else if((s[i]==')' && stack[stack.length()-1]=='(')||(s[i]=='}'&&stack[stack.length()-1]=='{')||(s[i]==']'&&stack[stack.length()-1]=='['))
        {
             stack.pop_back();

        }
        else{
            return false;
        }
        return valid(s,++i,stack);

    }
    bool isValid(string s) {
        if(s.length()==1){
            return false;
        }
        if(s.length()==0){
            return true;
        }
        int i=0;
        string stack="";
        return valid(s,i,stack);
    }
};


//using stack
bool isValidParenthesis(string s)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='('||s[i]=='{'||s[i]=='[')
        {
            st.push(s[i]);
        }
        else{
            if(!st.empty())
            {
                char ch=st.top();
                if((ch=='(' && s[i]==')')||(ch=='[' && s[i]==']')||(ch=='{' && s[i]=='}'))
                {
                    st.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}
