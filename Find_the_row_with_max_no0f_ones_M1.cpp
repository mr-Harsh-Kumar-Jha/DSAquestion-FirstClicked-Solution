#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

// Function that returns index of row
// with maximum number of 1s.
int rowWithMax1s(bool mat[R][C]) {
    // code here
    int rowIndex = -1 ;
    int maxCount = 0 ;

    for(int i = 0 ; i < R ; i++){
        int count = 0 ;
        for(int j = 0 ; j < C ; j++ ){
            if(mat[i][j] == 1){
                count++ ;
            }
        }
        if(count > maxCount){
            maxCount = count ;
            rowIndex = i ;
        }
    }

    return rowIndex ;
}


// Driver Code
int main()
{
    bool mat[R][C] = { {0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};

    cout << "Index of row with maximum 1s is " << rowWithMax1s(mat);

    return 0;
}
