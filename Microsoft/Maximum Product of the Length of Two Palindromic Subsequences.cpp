class Solution {
public:
int ans=INT_MIN;
int maxProduct(string s) 
{
	//im trying to get all the disjoint subsequences
	
    //the ith char can be in none of the string
	//the ith char can be in the first string
	//the ith cahr can be in the second string

    //trying to generate all pair of disjoint subsequence - disjoint subsequence are those which dont have any common character(more specifically no common indexes of that character)
	
	int idx=0;
	string s1="";
	string s2="";
    fun(s,idx,s1,s2);
	return ans;
}
void fun(string &s,int idx,string &s1,string &s2)
{
	if(idx >= s.length())
	{
		if(ispalin(s1)==true and ispalin(s2)==true)
		{
			int temp = s1.length() * s2.length();
			ans=max(ans,temp);
		}
		return;
	}
	
	char ch = s[idx];

  //Each character has three opions , op1- get in 1st subsequence , op2- get in 2nd subsequence , op3- doesn't go in either of two
	
	//Op-1 if the currchar got include in the first string s1
	s1.push_back(ch);
	fun(s,idx+1,s1,s2);
	s1.pop_back();
	
    //Op-2 if current character does get included in first string include it in second string
	s2.push_back(ch);
	fun(s,idx+1,s1,s2);
    s2.pop_back();
	
    //Op-3 doesnt include in either of two string
	fun(s,idx+1,s1,s2);
}
bool ispalin(string &s)
{
	int i = 0;
        int j = s.length() - 1;
 
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
 
        return true;
}
};
