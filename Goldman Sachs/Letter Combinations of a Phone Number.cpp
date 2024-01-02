class Solution {
public:

   //General pick,not pick and backtracking template question

    void f(int idx,string temp,vector<string>& ans,string digits,map<char,vector<char>> mp){

        if(idx==digits.size()){

            if(temp.size()>0) ans.push_back(temp);
            return;
        }

        for(int i=0;i<mp[digits[idx]].size();i++){

            temp +=mp[digits[idx]][i];
            f(idx+1,temp,ans,digits,mp);
            temp.pop_back();

        }

    }
    vector<string> letterCombinations(string digits) {
        
        map<char,vector<char>> mp;

        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};

        vector<string> ans;
        string temp="";
        f(0,temp,ans,digits,mp);

        return ans;

    }
};
