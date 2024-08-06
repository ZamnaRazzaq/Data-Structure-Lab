#include <iostream>
#include<Windows.h>
#include<iterator>
#include<list>
using namespace std;

class Graph {
	int v; // No. of vertices 
	list<int>* adj; // adjacency lists 
	bool* view; 
public:
	Graph()
	{
		v = 0;
		adj = 0;
		view = 0;
	}
	~Graph()
	{
		delete[]adj;
		delete[]view;
	}
	Graph(int x)
	{
		v = x;
		adj = new list<int>[v];
		view = new bool[v];
	}
	void Takeinput(int m, int n)
	{
		adj[m].push_back(n);
	}
	void Explorefunction(int first)
	{
		cout << first<< " ";
		view[first] = true;
		list<int>::iterator i;
		for (i = adj[first].begin(); i != adj[first].end(); i++)
		{
			if (!view[*i])
			{
				Explorefunction(*i);
				view[first] = false;
			}
			else if (*i == first)
			{
				view[first] = false;
			}
		}
	}
};

int main()
{   Graph g(4);
	g.Takeinput(0, 1);
	g.Takeinput(0, 2);
	g.Takeinput(1, 2);
	g.Takeinput(2, 0);
	g.Takeinput(2, 3);
	g.Takeinput(3, 3);
    cout << "Depth First Traversal from vertex 2 " << endl;
	g.Explorefunction(2);
    cout << endl<<"Depth First Traversal from vertex 1 " << endl;
	g.Explorefunction(1);
	system("pause");
}