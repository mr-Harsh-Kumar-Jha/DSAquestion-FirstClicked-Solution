// https://www.codechef.com/MARCH221C/problems/SUBSTRING

/*
Shefin gives you a string S and you have to find a non-empty string P such that:

P is a substring of S.
No non-empty substring of P is a prefix of S.
No non-empty substring of P is a suffix of S.
For all such possible strings, find the length of the longest string satisfying all the conditions. If no such string is possible, print −1.

A string A is a substring of a string B if A can be obtained from B by deleting several (possibly zero) characters from the beginning and several (possibly zero) characters from the end.
A prefix of a string A, is a substring of A that occurs at the beginning of A. For example, "code" is a prefix of "codechef", but "ode" is not.
A suffix of a string A, is a substring of A that occurs at the end of A. For example, "chef" is a suffix of "codechef", but "he" is not.

2.] Input Format
The first line of the input contains an integer T - denoting number of test cases.
Each test case contains a string S consisting of lowercase english alphabets only.

3.] Output Format
For each test case, print a single integer. If a string P exists based on the given conditions, print the maximum length of the possible string. Otherwise, print −1.

Constraints
1≤T≤104
1≤|S|≤106
Sum of |S| over all test cases does not exceed 106.
S consists of lowercase english alphabets only.


Sample Input 1
2
abcdab
aaa
Sample Output 1
2
-1

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string str;
        cin>>str;
        int size = str.size();
        int cnt = 0, ans = 0;
        for(int i = 0 ; i < size ; i++)
        {
            if(str[i] != str[0] && str[i] != str[size-1])
                cnt+=1;
            else
                cnt = 0;
            ans = max(ans , cnt);
        }
        if(ans == 0)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
	}
	return 0;
}
