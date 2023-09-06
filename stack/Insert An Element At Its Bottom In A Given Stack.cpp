#include <bits/stdc++.h> 
void solve(stack<int>& mystack,int x)
{
    if(mystack.empty())
    {
        mystack.push(x);
        return;
    }
    int top=mystack.top();
    mystack.pop();
    solve(mystack,x);
    mystack.push(top);
}


stack<int> pushAtBottom(stack<int>& mystack, int x) 
{
    // Write your code here.
    
    solve(mystack,x);
    return mystack;
}
