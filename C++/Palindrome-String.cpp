// { Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int r = S.size();
	    int start = 0, end = (r - 1);
	    while(start <= end) {
	        if(S[start] != S[end]){
	        return 0;
	        }
	        else{
	        start++;
	        end--;
	        }
	    }
	return 1;
	}

};

// { Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}  // } Driver Code Ends
