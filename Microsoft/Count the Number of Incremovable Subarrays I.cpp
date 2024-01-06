class Solution {
public:
    
    bool checkforStrictlyIncreasing(int s,int e,int n,vector<int>& nums){

        bool check1=true;
        bool check2=true;

        // checking strictly increasing between 0 to s 
        if(s>=0 && s<n){

            for(int i=0;i<s;i++){

                if(nums[i]>=nums[i+1]){

                    check1=false;
                    break;
                } 
            }
        }
        
        // checking strictly increasing between e to n-1  

        if(e<n && e>=0){

            for(int i=e;i<n-1;i++){
                
                if(nums[i]>=nums[i+1]){

                    check2=false;
                    break;
                } 


            }
        }

        bool check3=true;
        //cheking nums[s] and nums[e] for strictly increasing
        if(s>=0 && s<n && e>=0 &&e<n){

            check3=(nums[s]<nums[e]);
        }


        return check1&&check2&&check3;
    }
    int incremovableSubarrayCount(vector<int>& nums) {

        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){

            for(int j=i;j<n;j++){

                //incremovable array will be from i to j so we have to remove subarray from i to j and then in the remaining array we have to check whether it is strictly increasing or not   

                if(checkforStrictlyIncreasing(i-1,j+1,n,nums)){

                    cout<<i<<" "<<j<<endl;
                    cnt++;
                }

            }
        }

        return cnt;
        
    }
};
