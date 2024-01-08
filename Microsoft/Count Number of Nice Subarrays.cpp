class Solution {
public:

    int f(vector<int>& nums, int k){

        //KHANDANI VARIABLE SLIDING WINDOW TECHNIQUE

        int i=0,j=0;
        int cnt=0;
        int ans=0;

        while(j<nums.size()){

            if(nums[j] %2 ==1){

                cnt ++;
            }

            while(cnt>k){

                if(nums[i] %2 ==1){
                    
                    cnt--;
                
                }

                i++;
            }

            ans  +=j-i+1;
            j++;

        }

        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       
       /*

       //WE CAN CHANGE THIS PROBLEM INTO NO OF SUBARRAY HAVING SUM EQUAL K - SINCE WE NEED TO FIND NUMBER OF SUBAARRAY HAVING K ODD INTEGERS SO IF WE REPLACE EACH ODD INTEGERS BY 1 THEN K SUBARRAY OR TOTAL SUBARRAY WHOSE SUM IS K MEANS SAME AS EACH ODD INTEGERS IS REPLACED BY 1 AND EVEN BY 0 
        int n=nums.size();

        for(int i=0;i<n;i++){

            if(nums[i]%2==0){

                nums[i]=0;
            }
            else{
                nums[i]=1;
            }

        }

        int sum=0;
        map<int,int> mp;
        mp[0]=1;
        int cnt=0;

        for(int i=0;i<n;i++){

            sum +=nums[i];
            if(mp.find(sum-k)!=mp.end()){

                cnt +=mp[sum-k];
            }
            mp[sum]++;

        }


        return cnt;

        */


        //SLIDING WINDOW TECNIQUE 
 
        // WE CANT EXACTLY FIND NO OF SUBRRAY HAVING K ODD INTEGERS BUT WE CAN FIND NO OF SUBARRAY HAVING AT MOST K ODD INTEGER

        // NO OF SUBARRAY HAVING AT MOST K ODD INTEGERS - NO OF SUBAARAY HAVING AT MOST K-1 ODD INTEGER = NO OF SUBARRAY  HAVING EXACTLY K ODD INTEGERS



    return f(nums,k)-f(nums,k-1);
        
    }
};
