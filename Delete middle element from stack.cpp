#include <bits/stdc++.h> 
void solve(stack<int>&inputstack, int count,int N){
   if(count==N/2)
   {  inputstack.pop();
      return;
   }
   int ele=inputstack.top();
   inputstack.pop();
   solve(inputstack,count+1,N);
   inputstack.push(ele);
}
void deleteMiddle(stack<int>&inputstack, int N){
	
   // Write your code here
   /*vector<int>v;
   for(int i=1;i<=(N/2);i++){
      v.push_back(inputstack.top());//APPROACH-1
      inputstack.pop();
   }
   inputstack.pop();
   for(int i=v.size()-1;i>=0;i--){
      inputstack.push(v[i]);
   }
   v.clear();*/
  int count=0;
  solve(inputstack,count,N);
   
}
