#include <bits/stdc++.h> 
void sorwayinsert(stack<int> &stack,int val){
	if(stack.empty()||stack.top()<=val)
	{
      stack.push(val);
	  return;
	}
	int top=stack.top();
	stack.pop();
	sorwayinsert(stack,val);
	stack.push(top);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return;
	}
	int top=stack.top();
	stack.pop();
	sortStack(stack);
	sorwayinsert(stack,top);
}
