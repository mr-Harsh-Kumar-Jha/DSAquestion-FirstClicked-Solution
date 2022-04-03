// https://www.codechef.com/MARCH221C/problems/GENIUS

/*
Chef attempted an exam consisting of N objective questions. The marking scheme of the exam is:

+3 marks for a correct answer.
−1 marks for an incorrect answer.
0 marks for an unattempted question.
Find whether it is possible for Chef to score exactly X marks.

If it is possible, print 3 integers A, B, and C denoting the number of correct answers, incorrect answers and unattempted questions respectively.

2.] Input Format
First line will contain T, number of test cases. Then the test cases follow.
Each test case contains of a single line of input, two integers N,X.

3.] Output Format
For each test case, print 𝚈𝙴𝚂 if it is possible to score exactly X marks, otherwise print 𝙽𝙾.

If the answer is 𝚈𝙴𝚂, print 3 integers A, B and C in the next line such that:

0≤A,B,C≤N
A+B+C=N
Chef's total score is exactly X.
In case of multiple answers, every valid tuple is accepted.

You may print each character of the string in uppercase or lowercase (for example, the strings 𝚢𝙴𝚜, 𝚢𝚎𝚜, 𝚈𝚎𝚜 and 𝚈𝙴𝚂 will all be treated as identical).

Constraints
1≤T≤1000
1≤N≤108
0≤X≤3⋅N
Sample Input 1
3
10 30
9 25
8 0
Sample Output 1
YES
10 0 0
NO
YES
1 3 4

*/

#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int no_quest;
        int marks_tobe_scored;
        cin>>no_quest>>marks_tobe_scored;
        int solved=0,delt=0,unsolved;
        if(marks_tobe_scored%3==0)
        {
            solved+=(marks_tobe_scored/3);
        }
        else if(marks_tobe_scored%3==1)
        {
            solved+=(marks_tobe_scored/3)+1;
            delt+=2;
        }
        else if(marks_tobe_scored%3==2)
        {
            solved+=(marks_tobe_scored/3)+1;
            delt++;
        }


        if(solved+delt<=no_quest)
        {
            unsolved=no_quest-solved-delt;
            cout << "YES" << endl;
            cout << solved<<" "<<delt<<" "<<unsolved << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
	return 0;
}
