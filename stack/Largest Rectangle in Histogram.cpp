class Solution {
public:
    vector<int>nextsmalle(vector<int>&arr,int n){
        vector<int>ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=n-1;i>=0;i--){
          int curr=arr[i];
           while(st.top()!=-1 && arr[st.top()]>=curr)
           { st.pop();
           }
           ans[i]=st.top();
           st.push(i);
        }
        return ans;
    }

    vector<int>prevsmalle(vector<int>&arr,int n){
        vector<int>ans(n);
        stack<int> st;
        st.push(-1);
        for(int i=0;i<n;i++){
           int curr=arr[i];
           while(st.top()!=-1 && arr[st.top()]>=curr)
           { st.pop();
           }
           ans[i]=st.top();
           st.push(i);
        }
        return ans;
    }
    
      
    int largestRectangleArea(vector<int>& heights) {
        /*int area=INT_MIN;
        int n=heights.size();
        for(int i=0;i<n;i++){
            int curr=heights[i];
            int l=i;
            int r=i;
            while(l>0 && heights[l-1]>=curr)
            { l--;
            }
            while(r<n-1 && heights[r+1]>=curr){
                r++;
            }
            int cal=curr*(r-l+1);
            area=max(area,cal);
        }
        return area;*/
        int n=heights.size();
        vector<int>next;
        next=nextsmalle(heights,n);
        vector<int>prev;
        prev=prevsmalle(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            int l=heights[i];
            if(next[i]==-1)
            {  next[i]=n;
            }
            int b=next[i]-prev[i]-1;
            area=max(area,l*b);
        }
        return area;
    }
};
