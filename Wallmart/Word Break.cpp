class Solution {
public:
    
    bool f(int idx,string s, vector<string>& dict){

        if(idx>=s.length()){

            return true;
        }

        for(int i=idx;i<s.length();i++){

            string temp=s.substr(idx,i-idx+1);

            if(find(dict.begin(),dict.end(),temp)!=dict.end()){

                if(f(i+1,s,dict)){

                    return true;
                }
            }
        }


        return false;
    }
    bool wordBreak(string s, vector<string>& dict) {
        
        return f(0,s,dict);
    }
};
