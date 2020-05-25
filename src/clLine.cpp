#include "clLine.h"
using namespace std;

clLine::clLine()
{
    //ctor
}

clLine::clLine(int a, int b, int c, int d): x_1(a), y_1(b), x_2(c), y_2(d){}

clLine::~clLine()
{
    //dtor
}

void clLine::Show(){
    line(x_1, y_1, x_2, y_2);
}

