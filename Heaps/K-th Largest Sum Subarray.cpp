#include<bits/stdc++.h>
using namespace std;
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
	/*vector<int>ans;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			ans.push_back(sum);
		}

	}
	
	sort(ans.begin(),ans.end() );
	int m=ans.size();
	return ans[m-k];*/

	priority_queue<int,vector<int>,greater<int>>mini;
	int n=arr.size();
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(mini.size()<k){
				mini.push(sum);
			}
			else{
				if(mini.top()<sum){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}
