class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*
        So at each odd places we need a number which is greater than its previous even place, 
        so fill the odd indices (starting from 1) with values in descending order.
        After that, start filling the even indices (starting from 0) with the next set of remaining values.
        */

        int n = nums.size();
        vector<int> fre(5001, 0);
        
        for (auto it : nums) {
            fre[it]++;
        }
        
        int i = 1, j = 5000;
        
        //start to  fill largest value from 1 index
        while (i < n && j >= 0) {
            if (fre[j] == 0) {
                j--;
            } else {
                nums[i] = j;
                fre[j] -= 1;
                i += 2;
            }
        }
        
        i = 0;
         // start to fill next set of values from index 0
         
        while (i < n && j >= 0) {
            if (fre[j] == 0) {
                j--;
            } else {
                nums[i] = j;
                fre[j] -= 1;
                i += 2;
            }
        }
    }
};
