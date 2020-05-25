#include "clCircle.h"
#include "clNode.h"
#include "clEdge.h"
#include "clGraph.h"
#include <locale.h>
#include <fstream>

using namespace std;


/*
int nn = 5;
int aa[]{     0, 3, 0, 0, 1,
              3, 0, 5, 0, 4,
              0, 5, 0, 2, 6,
              0, 0, 2, 0, 7,
              1, 4, 6, 7, 0,

}; //должен вывести дерево 5 -> 1 -> 2 -> 3 -> 4
*/

int main()
{
    int size_, bit, i, j;

    ifstream input; // создаем объект класса ifstream
    input.open("input.txt"); // открываем файл

    input >> size_;
    int nn = size_;
    int aa[nn * nn] = {};
    //cout << nn << endl;
    for (i = 0; i < nn; i++){
        for (j = 0; j < nn; j ++){
            input >> bit;
            aa[i * nn + j] = bit;
            //cout << aa[i * nn + j] << " ";
        }
        //cout << endl;
    }

    setlocale(0, "Russian");
    cout << "Исполняется алгоритм Прима над взвешенным неориентированным графом размера: " << nn << endl;
    input.close();

    clGraph n_1(nn, aa);
    int gd = DETECT;
    int gm;
    initgraph(&gd, &gm,"");

    readkey();
    n_1.Show();
    readkey();
    n_1.primMST();
    readkey();
    closegraph();

    return 0;
}

