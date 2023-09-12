class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    string ans;
		    queue<int>q;
		    map<char,int>mpp;
		    for(int i=0;i<A.size();i++){
		        mpp[A[i]]++;
		        q.push(A[i]);
		        while(!(q.empty())){
		            if(mpp[q.front()]>1){
		                q.pop();
		            }
		            else{
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};
