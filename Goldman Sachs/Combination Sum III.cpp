/*

   Standard pick ,not pick method where we pick a element if current element is less target , element can be between 1 to 9

   */

    void f(int num,int k, int n,vector<int> temp,vector<vector<int>>& ans){



        if(temp.size()==k && n==0){

            ans.push_back(temp);
            return;
        }

        if(num>9 ||  temp.size()>k ){

            return;
        }

        //pick the current element

        if(num<=n){

            temp.push_back(num);
            f(num+1,k,n-num,temp,ans);
            temp.pop_back();
        }
        
        // not pick the current element
        f(num+1,k,n,temp,ans);


    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>> ans;
        vector<int> temp;

        f(1,k,n,temp,ans);
        return ans;

    }
