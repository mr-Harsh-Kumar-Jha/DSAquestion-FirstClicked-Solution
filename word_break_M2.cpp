#include<iostream>

using namespace std;

int wordBreak(string str, string dictionary[], string result, int size, int n,string previous){

for (int j=1; j<=size; j++){
//  cout<<str.size()<<endl;

    string sub=str.substr(0,j);
   //  cout<<sub<<endl<<endl;
    int a=0;
      previous=result;
    for(int i=0;i<n;i++){
       if(dictionary[i].compare(sub)==0){
           a=a+1;

           result=result+dictionary[i]+" ";
           if(j==size){
               cout << result << endl;
               return 1;
            }
           break;
       }
    }
    if(a>0){
       wordBreak(str.substr(j,size-j),dictionary,result,size-j,n,previous);
       result=previous;
    }

}
    return 0;
}

int main(){
    string dictionary[]={"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    string result="";
    string previous;
     int n = sizeof(dictionary)/sizeof(dictionary[0]);
    string word="iloveicecreamandmango";
      cout << "First Test:\n";
      wordBreak(word,dictionary,result,word.size(),n,previous);

      word="ilovesamsungmobile";
   cout << "\nSecond Test:\n";
    wordBreak(word,dictionary,result,word.size(),n,previous);
    return 0;
}