//BRUTE FORCE
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int len1=nums1.size();
       int len2=nums2.size();
       vector<int>v; 
       for(int i=0;i<len1;i++){
           int ans=-1;
           for(int j=0;j<len2;j++){
               if(nums1[i]==nums2[j]){
                   ans=j;
                   break;
               }
           }
           int flag=0;
           for(int j=ans+1;j<len2;j++){
               if(nums1[i]<nums2[j]){
                   v.push_back(nums2[j]);
                   flag=1;
                   break;
               }
           }
           if(flag==0){
               v.push_back(-1);
           }
       }
       return v;
    }
};
