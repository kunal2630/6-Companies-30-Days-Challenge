 vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
       /*

       For each query in queries we have to trim every string of nums then compare all those string integer value to find kith smallest trimmed , trimming means simply finding substring , but only problem was to sorting those trim string based on their integer values , as each trim string length can be greater than 100 so we cant use stoi to convert string to number 

       So to sort strings based on their integer values we can either use RADIX sort or we can use priority_queue and since we need to kth minimum we can use max heap to store value , when heap size beomes greater than k just pop top element as max heap top will always contain maximum element and we need minimum element


       */
       
       
        vector<int> ans;

        for(auto& it:queries){

            int rank=it[0];
            int trimDigits=it[1];

             priority_queue<pair<string,int>> pq;

            for(int i=0;i<nums.size();i++){

                int wSize=nums[i].size();

                //substring from  size-trimDigits of length trimDigits
                string temp=nums[i].substr(wSize-trimDigits,trimDigits);

                pq.push({temp,i});

                if(pq.size()>rank){
                    pq.pop();
                }
            }

            //top will contain rank as we are poping element from priority queue when its size exceed than rank
            ans.push_back(pq.top().second);
        }



        return ans;
    }
