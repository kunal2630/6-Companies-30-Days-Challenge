class Solution {
public:
    
    typedef pair<int,string> pi;

    //storing frequency of each word in a map and then sorting them based on their frequency using comparator function to deal with case where frequency are equal

    static bool comp(pair<int,string>& a,pair<int,string>& b){

        if(a.first==b.first) return a.second<b.second;
        else return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        

        unordered_map<string,int> mp;
        for(auto& it:words){

            mp[it]++;
        }

        vector<pi> v;
        for(auto& it:mp){

            v.push_back({it.second,it.first});

        }
        sort(v.begin(),v.end(),comp);
        vector<string> ans;

        for(int i=0;i<k && i<v.size();i++){

            ans.push_back(v[i].second);
        }


        return ans;

    }
};
