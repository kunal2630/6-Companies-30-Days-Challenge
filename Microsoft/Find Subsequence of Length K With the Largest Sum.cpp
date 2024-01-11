class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        //Since nums.size() is  <=1000 we cant use direct  pick,not pick method to find subsequence 
        //so just sort the array storing index and took the k lsargest number and using index constructed the subsequence 

        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        for(int i=0;i<nums.size();i++){

            pq.push({nums[i],i});

            //to use this we have taken min heap
            if(pq.size()>k) pq.pop();
        }

        int a[1001];
        for(int i=0;i<1001;i++){

            a[i]=1e9;
        }
    
        while(!pq.empty()){

            int val=pq.top().first;
            cout<<val<<endl;
            int idx=pq.top().second;
            pq.pop();
            a[idx]=val;
        }

        for(int i=0;i<1001;i++){

            if(a[i]!=1e9){

                ans.push_back(a[i]);
            }
        }

        return ans;
    }
};
