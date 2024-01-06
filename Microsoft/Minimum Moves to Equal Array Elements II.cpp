class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        //since we have to make all array elements equal in minimun moves best optimal way would be to make them all equal to a middle value(after sorting the array ) like suppose there are x people at place 1 and y people at place 2 we want to fix a common meet point where theese people will meet such that they dont have to travel more , so jus fix a mid points between them 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=n/2;
        int ans=0;
        for(auto it:nums){

            ans +=(abs(it-nums[mid]));
        }

        return ans;
        

    }
};
