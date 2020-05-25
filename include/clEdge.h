#ifndef CLEDGE_H
#define CLEDGE_H

#include "clLine.h"
#include <cstdlib>
class clEdge:public clLine
{
    public:
        clEdge();
        virtual ~clEdge();
        char* Getw() {
            return w;
        }
        void Setw(int val) {
            itoa(val, w, 10);
        }
        void Show();

    protected:

    private:
        char* w;
};

#endif // CLEDGE_H
