//GFG QUESTION

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here
  
  //Just keep track of count variable and use to_string() to convert the count to string
  
  string ans;
  char last=s[0];
  int cnt=1;
  for(int i=1;i<s.size();i++){
      
      char curr=s[i];
      if(curr==last) cnt++;
      else{
          
          ans +=last;
          last=curr;
          ans +=to_string(cnt);
          cnt=1;
        }
    }
        
         ans +=last;
         ans +=to_string(cnt);

  return ans;
  
  
}     
 
