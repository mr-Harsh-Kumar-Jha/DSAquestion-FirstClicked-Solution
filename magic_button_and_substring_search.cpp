// you have two strings S of length N and T of length M and a magic Button . Every time you press the magic button , the last letter of the string S is deleted and added to the beginning of the string S you decide to press the magic buttons n times . Each time you press the magic button you will search for the location of string T as a substring in the string S. if you are able to find T as a Subarray of S you will add the beginning index value of thosse substring to answer

// Time Complexity:- O(n^2 + n * m)
//Space Complexity:- O(n^2)

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findSubstringIndices(string S, string T) {
    int N = S.length();
    int M = T.length();
    vector<vector<int>> ans(N);

    for (int i = 0; i < N; i++) {
        int j = 0;
        while (j < N) {
            if (S.substr(j, M) == T) {
                ans[i].push_back(j);
            }
            j++;
        }
        if (i < N - 1) {
            S = S.substr(N - 1, 1) + S.substr(0, N - 1);
        }
    }

    return ans;
}

int main() {
    string S = "aaa";
    string T = "aaa";

    vector<vector<int>> allIndices = findSubstringIndices(S, T);
    int ans = 0;
    for (int i = 0; i < allIndices.size(); i++) {
        for (int idx : allIndices[i]) {
            ans+=idx+1;
        }
    }
    cout << ans<<endl;

    return 0;
}