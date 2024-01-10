class Solution {
public:
    
    /*

    For lowest price we have two option -

    1.Take all items at regular price
    2.Take some or all items at special price then remaining items at special price

    So each special[i] has two options either take or not take , so standard dp 

    In case we didnt pick any special[i] then at last we take items at regular price 
    */

    int cost=0;
    bool check(int idx, vector<vector<int>>& special, vector<int>& needs,int n){

            for(int i=0;i<n;i++){

                if(needs[i]<special[idx][i]) return false;
            }
        return true;
    }

    int f(int idx, vector<int>& price,vector<vector<int>>& special, vector<int>& needs,int n){

        
        //In case we didnt pick any special[i] then at last we take items at regular price  or if we pick some items at special price then taking remainig items at regular price
        if(idx>=special.size()){   
            int temp=0;

            
            for(int i=0;i<n;i++){
                 temp +=(price[i]*needs[i]);
            }
            return temp;
        } 

        int cost=1e9;

        //pick
        if(check(idx,special,needs,n)){

            //updating needs[i] as we have picked  current item
            for(int i=0;i<n;i++){

                needs[i]=needs[i]-special[idx][i];
            }
            cost=min(cost,special[idx][n]+f(idx,price,special,needs,n));
            
            //while backtracking make needs same as before
            for(int i=0;i<n;i++){

                needs[i]=needs[i]+special[idx][i];
            }
        }
        //not pick
        cost=min(cost,f(idx+1,price,special,needs,n));
        return cost;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {

        int price1=0;
        int n=price.size();
       
        return f(0,price,special,needs,n);
    }
};
