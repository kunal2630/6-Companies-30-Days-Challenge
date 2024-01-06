class Solution {
public:
    bool isSafe(int row,int col,int n,int m){

        if(row>=0 && row<n && col>=0 && col<m) return true;
        return false;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        
        int dlrow[]={0,1,1,1,0,-1,-1,-1};
        int dlcol[]={-1,-1,0,1,1,1,0,-1};
        int n=img.size();
        int m=img[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));


        for(int row=0;row<n;row++){

            for(int col=0;col<m;col++){

                int cnt=1;
                int sum=img[row][col];
                for(int i=0;i<8;i++){

                    int newrow=row+dlrow[i];
                    int newcol=col+dlcol[i];

                    if(isSafe(newrow,newcol,n,m)){

                        sum +=img[newrow][newcol];
                        cnt++;
                    }
                    
                }

                ans[row][col]=(sum/cnt);


            }
        }

        return ans;
    }
};
