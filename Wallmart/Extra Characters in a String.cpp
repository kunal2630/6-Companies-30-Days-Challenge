class Solution {
public:
    
    unordered_set<string> st;
    int dp[51];

     int f(int idx,string& s){

         if(idx>=s.size()){

            
            return 0;

         }

         if(dp[idx] !=-1){

             return dp[idx];
         }
         
             int ans=INT_MAX;
 
         for(int i=idx;i<s.size();i++){

             string subst=s.substr(idx,i-idx+1);
             int len=subst.size();

             //if current substring is present it means we will have 0 extra character 
             if(st.find(subst)!=st.end()){

                ans=min(ans,0+f(i+1,s));
             }

             //else we will have extra len characters
             else{

                ans=min(ans,(len+f(i+1,s)));

             }
         }

            return dp[idx]=ans;


     }

    int minExtraChar(string s, vector<string>& dictionary) {
        
        memset(dp,-1,sizeof(dp));
        for(auto& it:dictionary){

            st.insert(it);
        }
        int n=s.size();
        return f(0,s);
    }
};
