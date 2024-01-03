class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
        /*

        Generated all subarrays , and  checked  condition to have at most k elements that are divisible by p and  for every subarray if condition gets satisfied we pushed into set , set will remove any duplicate subarray if present 


        */
        
        set<vector<int>> st;
        int n=nums.size();
        for(int i=0;i<n;i++){

            int divisible=0;
            vector<int> temp;
            for(int j=i;j<n;j++){

                if(nums[j]%p==0) divisible++;

                if(divisible<=k){

                    temp.push_back(nums[j]);
                    st.insert(temp);

                }
            }
        }

        return st.size();
    }
};
