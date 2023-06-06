#include <bits/stdc++.h>
using namespace std;

template <class T, class heap = vector<T>, class Compare = less<T>>
class Priority_Queue{
   heap vec;
   Compare compare;

   void heapifyUp(int index){
      int parent = (index - 1) / 2;
      while (index > 0 && compare(vec[parent], vec[index])){
         swap(vec[parent], vec[index]);
         index = parent;
         parent = (index - 1) / 2;
      }
   }

   void heapifyDown(int index){ // this is used for keeping the
      int size = vec.size();
      int left = 2 * index + 1;  // binary heap me left wala child
      int right = 2 * index + 2; // binary heap me right wala child
      int smallest = index;

      if (left < vec.size() && compare(vec[smallest], vec[left])){
         smallest = left;
      }
      if (right < vec.size() && compare(vec[smallest], vec[right])){
         smallest = right;
      }
      if (smallest != index){
         swap(vec[smallest], vec[index]);
         heapifyDown(smallest);
      }
   }

public:
   Priority_Queue() : vec(), compare(){}; // The vec member will be an empty vector, and the compare member will be a default-constructed object of the comparison type.

   void push(T a){
      vec.push_back(a);
      heapifyUp(vec.size() - 1);

   }

   void pop(){
      if (empty())
         throw out_of_range("Priority queue is empty!");
      swap(vec[0], vec[vec.size() - 1]);
      vec.pop_back();
      heapifyDown(0);
   }

   T top(){
      if (empty())
         throw out_of_range("Priority queue is empty!");
      return vec[0];
   }

   bool empty(){
      return vec.empty();
   }

   size_t size(){
      return vec.size();
   }
};
