 vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {

       
        //to store access times of all employess separately
        unordered_map<string,vector<int>> mp;

        //converted the access time from string to integer and add it to map (Ex - "0500" to 500 , "1300" to 1300)
        for(auto& it:access_times){

            mp[it[0]].push_back(stoi(it[1]));
        }

         //to store employess name
         vector<string> ans;

         for(auto it:mp){


              vector<int> temp=it.second;

              //sorted access time so that i can Binary search to find employee access times 
              sort(temp.begin(),temp.end());

             if(temp.size()>=3){

                 for(int i=0;i<temp.size();i++){

                     //for a employee , traverse through its all access time to find all the access time  in a interval of 1 hr and if access time is "1249" which 12:49 so after 1 hr will be 13:49 that is add 100 to current time 
                     int idx=lower_bound(temp.begin(),temp.end(),temp[i]+100)-temp.begin();

                     //so if there are equal or more than 3  access time thats our answer
                     if(idx-i>=3){
                          ans.push_back(it.first);
                          break;
                     }
                 }

                
             }
         }

         return ans;

        
    }
