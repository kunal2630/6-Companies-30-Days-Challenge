class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        
        /*
        
        From each water cell move to its four adjacent cells increase its heights by 1 such that  
        absolute height difference of at most 1
        
        */
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,int>> q;


        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(isWater[i][j]==1)  {

                    q.push({i,j});
                }

            }
        }

        int dlrow[]={0,1,0,-1};
        int dlcol[]={-1,0,1,0};

        while(!q.empty()){

            int size=q.size();

            while(size--){

            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            int height=ans[row][col];

            for(int i=0;i<4;i++){

                int newrow=row+dlrow[i];
                int newcol=col+dlcol[i];

                //isWater[newrow][newcol]==0 so that we set height of land cell
                // ans[newrow][newcol]==0 to ensure that we set the height of the cell once in current run
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && isWater[newrow][newcol]==0 && ans[newrow][newcol]==0){

                    q.push({newrow,newcol});
                    ans[newrow][newcol]=height+1;
                }
            }
            }
        }
   
        return ans;
    }
};
