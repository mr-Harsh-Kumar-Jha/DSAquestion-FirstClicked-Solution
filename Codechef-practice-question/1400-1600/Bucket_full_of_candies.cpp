// https://www.codechef.com/problems/BFOC

/* Today is your birthday. You have decided to give away candies to your friends.

You have N friends and M candies. Suppose the 1st friend has L buckets, 2nd has L+1 buckets, 3rd has L+2 buckets, and so on — in general, the ith friend has L+i−1 buckets.

You start distributing candies from the Nth friend and go towards the 1st friend.

For each friend, you put the maximum number of candies in each bucket such that all the buckets for that friend have an equal number of candies in them. Now, you take the remaining candies, move to the next friend, and repeat the above step.

Find the number of candies which will remain with you after visiting all your friends.

a. ] Input Format
The first line of input will contain a single integer T, the number of test cases. Then the test cases follow.
Each test case consists of a single line of input, containing three space-separated integers N,M,L — representing the number of friends, number of candies that you have, and the number of buckets with the 1st friend respectively.
Output Format
For each test case, output a single integer representing the total number of candies left with you after distributing candies to all your friends.

b.] Constraints
1≤T≤105
0≤N,M≤1018
1≤L≤1018
Sample Input 1
4
2 8 2
3 9 2
3 10 2
4 100 10
Sample Output 1
0
1
0
9

c.] Explanation
Test case 1: There are two friends. The 1st friend has 2 buckets and the 2nd friend has 3 buckets. You will give 6 candies to 2nd friend (2 in each bucket). Now you are left with 2 candies, which you will give to the 1st friend (1 in each bucket). You will be left with 0 candies at the end.

Test case 2: There are 3 friends and 9 candies. The 1st friend has 2 buckets, 2nd friend has 3 buckets, and 3rd friend has 4 buckets. You will give 8 candies to the 3rd friend (2 in each bucket). Now the 2nd friend and 1st friend will get 0 candies. You will be left with 1 candy at the end.

Test case 3: There are 3 friends and 10 candies. You will give 8 candies to the 3rd friend (2 in each bucket). Next, the 2nd friend will get 0 candies. Finally, the 1st friend will get 2 candies (1 in each bucket). You will be left with 0 candies at the end.
*/

#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll chocolateDistri(ll frnd, ll total_choco, ll bucketFirst)
{
   ll ans = total_choco - ((total_choco / (bucketFirst + frnd - 1)) * (bucketFirst + frnd - 1));
   if (frnd == 0)
      return total_choco;
   else if (ans >= bucketFirst && ans <= bucketFirst + frnd - 1)
   {
      return 0;
   }
   else if (ans < bucketFirst)
   {
      return ans;
   }
}

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      ll frnd, total_choco, bucketFirst;
      cin >> frnd >> total_choco >> bucketFirst;
      ll ans = chocolateDistri(frnd, total_choco, bucketFirst);
      cout << ans << endl;
   }
   return 0;
}

// the case i was missing was when no_of_friends = 0. for this the ans would be no_of_chocklets itlsef.