class Solution {
public:
    
    int mod=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        
        vector<int> awarePeopleTracker(2001,0);

        //people aware of sectret at day 1
        awarePeopleTracker[1]=1;
        for(int day=1;day<=n;day++){

            //starting from day+delay all people which havent forgot will start telling other people and will go on telling other people till day+forget
            for(int j=day+delay;j<day+forget;j++){

                awarePeopleTracker[j]=(awarePeopleTracker[j]+awarePeopleTracker[day])%mod;
            }
        }

       int ans=0;
       while(forget){

           ans =(ans+awarePeopleTracker[n])%mod;
           n--;
           forget--;
       }


        return ans;
    }
};
