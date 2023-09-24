class Solution{
    public:
    void merging(vector<int>&ans,vector<int> &arr1, vector<int> &arr2, int n, int m){
     int i=0;
     int j=0;
     int len1=n;
     int len2=m;
     while(i<len1){
       ans.push_back(arr1[i++]);
     }
     while(j<len2){
        ans.push_back(arr2[j++]);
     }
    }
    void heapify(vector<int>&arr,int n,int i){
     int largest=i;
     int left=2*i+1;
     int right=2*i+2;
     if(left<n && arr[left]>arr[largest]){
         largest=left;
     }
     if(right<n && arr[right]>arr[largest]){
        largest=right;
     }
     if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
     }

    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int>ans;
        merging(ans,a,b,n,m);
        for(int i=ans.size()-1;i>=0;i--){
            heapify(ans,ans.size(),i);
        }
        
        return ans;
    }
};
