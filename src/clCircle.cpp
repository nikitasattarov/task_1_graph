#include "clCircle.h"
using namespace std;

clCircle::clCircle():R(40){}

clCircle::clCircle(int a, int b, int c):x(a), y(b), R(c){}

clCircle::~clCircle(){}

void clCircle::Show(){
    circle(x, y, R);
}



