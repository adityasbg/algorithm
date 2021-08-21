#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{

    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        V = v;
        //Array of link list
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool bidir = true)
    {
        l[u].push_back(v);
        if (bidir)
        {
            l[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i
                 << "->";
            for (int vertex : l[i])
            {
                cout << vertex << ",";
            }
            cout << endl;
        }
    }

    void bfg(int source)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << endl;
            q.pop();

            for (auto nvbr : l[f])
            {
                if (!visited[nvbr])
                {
                    q.push(nvbr);
                    visited[nvbr] = true;
                }
            }
        }
    }
    // bfs can also give us shotest path for undirected graph

    void shortest_path(int source, int dest = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{0};
        int *parent = new int[V];
        int *distance = new int[V]{0};
        // init parent to -1
        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }
        // visit first node
        q.push(source);
        visited[source] = true;
        parent[source] = source;
        distance[source] = 0;

        while (!q.empty())
        {
            int f = q.front();
            q.pop();

            for (auto nvbr : l[f])
            {
                if (!visited[nvbr])
                {
                    q.push(nvbr);
                    visited[nvbr] = true;
                    parent[nvbr] = f;
                    distance[nvbr] = distance[f] + 1;
                }
            }
        }

        for (int i =0 ; i<V ; i++){
            cout<<"Shortest didtance to"<<i<<" is "<<distance[i]<<endl;
        }

        // parent path
        if (dest != -1)
        {
            int temp = dest;
            while (temp != source)
            {
                cout << temp << "<--";
                temp = parent[temp];
            }
            cout<<source<<endl;
        }
    }
};

int main()
{

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    // g.printAdjList();
    // g.bfg(1);
    g.shortest_path(1 ,6);
    return 0;
}