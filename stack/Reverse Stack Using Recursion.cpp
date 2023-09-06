
void solveinsertatbottom(stack<int>& mystack,int x)
{
    if(mystack.empty())
    {
        mystack.push(x);
        return;
    }
    int top=mystack.top();
    mystack.pop();
    solveinsertatbottom(mystack,x);
    mystack.push(top);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return;
    }
    int top=stack.top();
    stack.pop();
    reverseStack(stack);
    solveinsertatbottom(stack,top);
}
