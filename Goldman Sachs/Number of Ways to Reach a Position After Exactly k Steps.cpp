class Solution {
public:

   /* Standard dp question op options - here two option  either move one position left or one position right

   But since there are no limitation in moving left or moving right so from startIdx we can either move to all left (k position ) or all right 

   So any time we can be between start-k position to start+k so we can be at -ve position on number line and while doing memoistaion we can use -ve index so we have to do shifting of index

   In worst case since k is 1 to 1000 and start is between 1 to 1000 at max we can move all left  and reach at index -1000 so we can shift by adding >1000  or move all right from s=1000 tok postion at 2000 hence our start can varry from -1000 to 2000 so size of int dp[x][y] x has to be of >3000
   */ 
    
    int dp[3010][1001];
    int mod=1e9+7;
    int f(int s,int e,int k){

        if(k==0 && s==e){

            return 1;
        }
        if(k<0){

            return 0;
        }

        if(dp[s+1000][k]!=-1){

            return dp[s+1000][k];
        }

        int op1=f(s+1,e,k-1)%mod;
        int op2=f(s-1,e,k-1)%mod;

        return dp[s+1000][k]=(op1+op2)%mod;
    }
    int numberOfWays(int s, int e, int k) {
        
  
        memset(dp,-1,sizeof(dp));
        return f(s,e,k);
    }
};
