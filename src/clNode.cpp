#include "clNode.h"


clNode::clNode():clCircle(), num(new char[10]){}
clNode::clNode(int a, int b, int c, int i):clCircle(a,b,c), num(new char[10]){}
clNode::~clNode(){}

void clNode::Show(){
    int x = Getx() - 4;
    int y = Gety() - 8;
    clCircle::Show();
    outtextxy(x, y, num);;
}

