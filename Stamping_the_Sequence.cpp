// https://leetcode.com/problems/stamping-the-sequence

// here our main moto was to just reverce the process of going from empty string to desired string , so we just did the opposite by going from desired string to empty string .
// we will first replace all the stamped position with question mark and then for left most occurance of the stamp in target we will mark as visited .

#include <bits/stdc++.h>
using namespace std;

bool canReplace(string &stamp, string &target, int pos)
{
   // the position is replacable only if there is a presence of stamp or questionmark from the index provided , inside the string .
   int m = stamp.size(), n = target.size();
   for (int i = 0; i < m; i++)
   {
      if (target[i + pos] != '?' and target[i + pos] != stamp[i])
         return false;
   }
   return true;
}

int replace(string &stamp, string &target, int pos)
{
   int cnt = 0;
   int m = stamp.size(), n = target.size();
   for (int i = 0; i < m; i++)
   {
      if (target[i + pos] != '?')
      {
         cnt++;
         target[i + pos] = '?';
      }
   }
   return cnt;
}

vector<int> movesToStamp(string stamp, string target)
{

   vector<int> ans;

   int m = stamp.size(), n = target.size();

   int count = 0;

   vector<int> vis(n + 1, 0);  // this is made in order to kepp the track of visited positon so that it not be visited next time (only those position will be marked as visited from which stamp is found in target .) .

   while (count != n)
   {
      bool flag = false;       // this is done in order to control atleast one such starting position from where stamp will be there in target , if no such position exist then target cannot be formed .
      for (int i = 0; i <= n - m; i++)
      {
         if (!vis[i] and canReplace(stamp, target, i))
         {
            vis[i] = 1;
            count += replace(stamp, target, i);
            flag = true;
            ans.push_back(i);
         }
      }
      if (!flag)
         return {};
   }
   reverse(ans.begin(), ans.end());
   return ans;
}

int main()
{
   string stamp, target;
   cin >> stamp >> target;
   vector<int> m = movesToStamp(stamp, target);
   for (auto it : m)
   {
      cout << it << " ";
   }
}