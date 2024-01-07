class Solution {
public:
    string getHint(string secret, string guess) {
        
        map<char,int> mp;
        int b=0,c=0;
        for(auto& it:secret){

            mp[it]++;

        }

        //calaculated all bulls first as for finding cows we need non-bulls that can be rearranged 
        for(int i=0;i<guess.size();i++){

            if(secret[i]==guess[i]){

                b++;
                mp[guess[i]]--;
            }

        }
 
        //each character can only be cows if it is present in our secret and it is not used before that is we have not used it as bull (thats why we calculated bull first)

        for(int i=0;i<guess.size();i++){

            if(secret[i]!=guess[i]){
            
                if(mp.find(guess[i]) !=mp.end()){

                    if(mp[guess[i]]>0){

                        c++;
                        mp[guess[i]]--;

                    }
                }
            }
            
        }

        string ans="";
        ans +=to_string(b);
        ans+='A';
        ans +=to_string(c);
        ans+='B';
        return ans;

    }
};
