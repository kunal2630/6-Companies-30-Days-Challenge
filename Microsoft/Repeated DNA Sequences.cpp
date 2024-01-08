class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        /*

        Generated all 10length substring using sliding window  and store it in map to store its frequency
        */
        vector<string>  ans;
        if(s.length()<=10) return ans;
        map<string,int> mp;

        //generated first 10length substring
        string temp=s.substr(0,10);
        mp[temp]++;


        int j=10;
        while(j<s.length()){

           //sliding the window and finding new substring
            temp.erase(0,1);
            temp+=s[j];
            j++;
            mp[temp]++;

        }

        //if frequency is greater than 1 then thats our answer
        for(auto& it:mp){

            if(it.second>1){

                ans.push_back(it.first);
            }
        }

        return ans;
    }
};
