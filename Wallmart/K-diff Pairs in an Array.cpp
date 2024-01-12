//Approach -1 - Bruteforce 

int findPairs(vector<int>& nums, int k) {
        
        set<pair<int,int>> st;
        for(int i=0;i<nums.size();i++){

            for(int j=i+1;j<nums.size();j++){

            if(abs(nums[i]-nums[j])==k){

                if(nums[i]<nums[j]){
                st.insert({nums[i],nums[j]});

                }
                else{

                st.insert({nums[j],nums[i]});

                }
            }
            }
        }
        return st.size();
}


//Approach 2 - Optimal

    int search(int start,int target,vector<int>& nums){

            int end=nums.size()-1;
            while(start<=end){

                int mid=start+(end-start)/2;
                if(nums[mid]==target) return mid;

                if(nums[mid]>target){

                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }

            return -1;
    }

    int findPairs(vector<int>& nums, int k) {

             set<pair<int,int>> settt;

         sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){

            //we try to find the target number which is current number +k and since target number is current number + k it means that target will always be greater than current number so we can start from our search currIndex+1 ,which will also make sure that we didint take current element twice

            int idx=search(i+1,nums[i]+k,nums);

            if(idx !=-1){

                settt.insert({nums[i],nums[i]+k});

            }
        }

        return settt.size();
        
    }
