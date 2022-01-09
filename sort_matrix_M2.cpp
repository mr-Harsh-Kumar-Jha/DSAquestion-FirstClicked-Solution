//this is a solution for row and column wise sorted array.
// time complexity for this solution is O(N^3).

#include<iostream>
#include<climits>
using namespace std;

#define INF INT_MAX
#define N 4

// A utility function to youngify a Young Tableau.  This is different
// from standard youngify.  It assumes that the value at mat[0][0] is
// infinite.
void youngify(int mat[][N], int i, int j)
{
    // Find the values at down and right sides of mat[i][j]
    int downVal  = (i+1 < N)? mat[i+1][j]: INF;
    int rightVal = (j+1 < N)? mat[i][j+1]: INF;

    // If mat[i][j] is the down right corner element, return
    if (downVal==INF && rightVal==INF)
        return;

    // Move the smaller of two values (downVal and rightVal) to
    // mat[i][j] and recur for smaller value
    if (downVal < rightVal)
    {
        mat[i][j] = downVal;
        mat[i+1][j] = INF;
        youngify(mat, i+1, j);
    }
    else
    {
        mat[i][j] = rightVal;
        mat[i][j+1] = INF;
        youngify(mat, i, j+1);
    }
}

// A utility function to extract minimum element from Young tableau
int extractMin(int mat[][N])
{
    int ret = mat[0][0];
    mat[0][0] = INF;
    youngify(mat, 0, 0);
    return ret;
}

// This function uses extractMin() to print elements in sorted order
void printSorted(int mat[][N])
{
   cout << "Elements of matrix in sorted order n"<<endl;
   int temp=N;
   for (int i=0; i<N*N; i++){
      if(i==temp){
         cout<<endl;
         temp=temp+N;
      }
      cout << extractMin(mat)<<" ";
   }

}

// driver program to test above function
int main()
{
  int mat[N][N] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  printSorted(mat);
  return 0;
}

/*
   Method 3: it uses heap
*/
