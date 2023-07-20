#include<bits/stdc++.h>
using namespace std;

struct Point{
   int x;
   int y;

   Point(int _x,int _y){
      x = _x;
      y = _y;
   }

   Point(){
        x = 0;
        y = 0;
    }
};

struct Node{
   Point pos;
   int data;
   Node(Point _pos, int _data){
      pos = _pos;
      data = _data;
   }

   Node(){
      data = 0;
   }
};

class QuadTree{
   Point TpLeft;
   Point BtRight;

   Node *n;

   QuadTree* topLeftTree;
   QuadTree* topRightTree;
   QuadTree* botLeftTree;
   QuadTree* botRightTree;

   public:
   QuadTree(){
      TpLeft = Point(0,0);
      BtRight = Point(0,0);

      topLeftTree = NULL;
      topRightTree = NULL;
      botLeftTree = NULL;
      botRightTree = NULL;
   }

   QuadTree(Point _TpLeft, Point _BtRight){
      topLeftTree = NULL;
      topRightTree = NULL;
      botLeftTree = NULL;
      botRightTree = NULL;

      TpLeft = _TpLeft;
      BtRight = _BtRight;
   }

   void insert(Node*);
   bool inBoundary(Point);
};

bool QuadTree::inBoundary(Point p)
{
    return (p.x >= TpLeft.x && p.x <= BtRight.x
            && p.y >= TpLeft.y && p.y <= BtRight.y);
}

void QuadTree::insert(Node* node){
   if (node == NULL) return;

   if(!inBoundary(node->pos)) return;

   // We are at a quad of unit area
    // We cannot subdivide this quad further
   if (abs(TpLeft.x - BtRight.x) <= 1
        && abs(TpLeft.y - BtRight.y) <= 1) {
        if (n == NULL) n = node;
        return;
    }
}

int main(){

}