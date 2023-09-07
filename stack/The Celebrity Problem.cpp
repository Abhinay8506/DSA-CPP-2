class Solution 
{
    public:
   
    
       
    bool knows(vector<vector<int> >& M, int a, int b, int n) {
        if(M[a][b] == 1)
            return true;
        else
            return false;
    }
   
    int celebrity(vector<vector<int> >& M, int n) 
    {
         // code here 
        /*int i=0;
        for(int i=0;i<n;i++){
            bool b=true;
            for(int j=0;j<n;j++)
            {
                if(M[i][j]!=0){
                    b=false;
                    break;
                }
            }
            if(b==true){
                i++;
            }
        }
        return i;*/
        stack<int> s;
        //step1: push all element in stack
        for(int i=0; i<n; i++) {
            s.push(i);
        }   
        
        
        while(s.size() > 1) {
            
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b,n)){
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }
        int ans = s.top();
        int zeroCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
        
        //all zeroes
        if(zeroCount != n)
            return -1;
        
        //column check
        int oneCount = 0;
        
        for(int i=0; i<n; i++) {
            if(M[i][ans] == 1)
                oneCount++;
        }
        
        if(oneCount != n-1)
            return -1;
        
        return ans;
        
    }
    
};
