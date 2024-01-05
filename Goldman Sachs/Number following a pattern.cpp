string printMinNumberForPattern(string s){
        
        /* 
        
        For 'D' you want a decreasing sequence but for a decreasing sequence we have to start 
        the sequence from a larger number such that if adjacent 'D' is present we can deal with it
        For 'D' do nothing increase cnt by 1 and push it in stack and when you got 'I'
        then start taking element from stack and inserting it into our answer
        
        */
        
        stack<int> st;
        int cnt=1;
        string ans="";
        for(int i=0;i<s.size();i++){
            
            if(s[i]=='D'){
                
                st.push(cnt);
                cnt++;
            }
            else{
                
                st.push(cnt);
                cnt++;
                while(!st.empty()){
                    
                    ans +=(to_string(st.top()));
                    st.pop();
                }
                
                
            }
        }
        
        st.push(cnt);

       
        while(!st.empty()){
                    
                    ans +=(to_string(st.top()));
                    st.pop();
        }
        
        return ans;
        
    }
