class Solution {
public:
    string frequencySort(string s) {
       
        string ans="";
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            mp[ch]++;
        }
        priority_queue <pair<int,char>> pq;
        for(auto i=mp.begin();i!=mp.end();i++){
            pq.push({i->second,i->first});
        }
        while(!pq.empty()){
            int fre=pq.top().first;
            char chh=pq.top().second;
            for(int i=1;i<=fre;i++){
            ans.push_back(chh);
            }
            pq.pop();
        }
        return ans;
    }
};
