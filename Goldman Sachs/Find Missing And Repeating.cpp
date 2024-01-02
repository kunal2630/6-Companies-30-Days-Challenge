vector<int> findTwoElement(vector<int> arr, int n) {
        
        /*
        
        Store frequency of each number in the fr array and check for frequency if fr[i]>1 it means tha
        i is repeating and if f[i]==0 it means that number is missing
        
        */
        
        vector<int> ans;
        vector<int> fr(n+1,0);
        for(auto it:arr){
            
            fr[it]++;
        }
        
        int rep=0,missing=0;
        
        for(int i=1;i<=n;i++){
            
            if(fr[i]==0){
                
                missing=i;
            }
            else if(fr[i]>1){
                
                rep=i;
            }
            
        }
        
        ans.push_back(rep);
        ans.push_back(missing);
        
        return ans;
        
        
        
        
    }
