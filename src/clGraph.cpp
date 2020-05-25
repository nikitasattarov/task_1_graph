#include "clGraph.h"
#include "clEdge.h"
#include "clNode.h"
#include "clLine.h"


clGraph::clGraph(int t, int *p): n(t), a(new int [n * n]), v(new clNode [n])
{
    double x = 350;
    double y = 150;
    int R = 160;
    double pi = 3.14, angle = 0;
    v[0].Setx(x);
    v[0].Sety(y);
    v[0].Setnum(1);
    for (int i = 1; i < n; i++)
    {
        angle += 360 / n;
        x = x + R * cos(angle * pi / 180);
        v[i].Setx(x);
        y = y + R * sin(angle * pi / 180);
        v[i].Sety(y);
        v[i].Setnum(i + 1);

    }
    for(int i = 0; i < n * n; i++)
    {
        a[i] = p[i];
    }
}
void clGraph:: Show()
{
    for(int i = 0; i < n; i++)
    {
        v[i].Show();
    }
    for(int i = 0; i < n * n; i++)
    {
        int m = i / n, k = i % n;
        if (a[i] != 0)
        {
            clEdge edg;
            edg.Setx_1(v[m].Getx());
            edg.Setx_2(v[k].Getx());
            edg.Sety_1(v[m].Gety());
            edg.Sety_2(v[k].Gety());
            edg.Setw(a[i]);
            edg.Show();

        }
    }
}
int clGraph:: minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int vv = 0; vv < n; vv++)
        if (mstSet[vv] == false && key[vv] < min)
            min = key[vv], min_index = vv;

    return min_index;
}


int clGraph::  printMST(int parent[])
{
    for (int i = 1; i < n; i++)
    {
        setcolor(5);
        clLine ln(v[parent[i]].Getx(), v[parent[i]].Gety(), v[i].Getx(), v[i].Gety());
        ln.Show();

    }
}



void clGraph:: primMST()
{
	int parent[n];
	int key[n];
    bool mstSet[n];

	for (int i = 0; i < n; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < n - 1; count++)
	{

		int u = minKey(key, mstSet);

		mstSet[u] = true;

		for (int vv = 0; vv < n; vv++)

		{
		    if (a[u * n + vv] && mstSet[vv] == false && a[u * n + vv] < key[vv])
			{
			    parent[vv] = u;
                key[vv] = a[u * n + vv];
            }
        }
	}

	printMST(parent);
}

clGraph::~clGraph()
{
    //dtor
}

