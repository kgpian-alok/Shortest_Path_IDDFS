/*

Iterative Deepning Depth First Search

Code Submitted by- Alok Kumar - 21CE10008 
                   Anish Majumdar - 21CE10009

CODE STARTS FROM HERE
       1   ---->level 0
      /  \
     2     3 ----> Level 1
   /   \  / \
  4    5 6   7----> Level 2

if our target is reached then the loop will stop and print the depth value*/



#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int MAXN = 1005; // maximum number of nodes in the graph

int n, m; // number of nodes and edges in the graph
int start, goal; // starting and goal nodes
int adj[MAXN][MAXN]; // adjacency matrix to store the graph
bool visited[MAXN]; // array to mark visited nodes
int depth[MAXN]; // array to store depth of each node

void iddfs(int node, int depthLimit, stack<int> path)
{
    path.push(node); // add current node to path
    visited[node] = true; // mark current node as visited
    depth[node] = path.size() - 1; // store depth of current node

    if (node == goal)
    { // goal node found
        cout << "Shortest path: ";
        while (!path.empty())
        {
            cout << path.top() << " "; // print path in reverse order
            path.pop();
        }
        cout << endl;
        return;
    }

    if (depth[node] < depthLimit)
    { // depth limit not reached
        for (int i = 1; i <= n; i++)
        {
            if (adj[node][i] && !visited[i])
            { // if i is adjacent to node and not visited
                iddfs(i, depthLimit, path); // recursive call with i as the new node
            }
        }
    }

    visited[node] = false; // mark current node as unvisited
    path.pop(); // remove current node from path
}

void findShortestPath()
{
    int depthLimit = 0; // initial depth limit

    while (true)
    {
        memset(visited, false, sizeof(visited)); // mark all nodes as unvisited
        stack<int> path; // create an empty path
        iddfs(start, depthLimit, path); // run IDDFS with current depth limit
        depthLimit++; // increase depth limit for next iteration
        if (depthLimit > n)
        { // depth limit exceeded maximum number of nodes
            cout << "No path found!" << endl;
            break;
        }
    }
}

int main()
{
    cout<<"Enter no of nodes & edges:- ";
    cin >> n >> m;
    memset(adj, 0, sizeof(adj)); // initialize adjacency matrix to 0
    cout<<endl;
    for (int i = 0; i < m; i++)
    {
        cout<<"Enter nodes of edge "<<i+1<<":- ";
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // add edge from u to v
        adj[v][u] = 1; // add edge from v to u (assuming undirected graph)
    }
    cout<<"Enter start & goal node:- ";
    cin >> start >> goal;

    findShortestPath();

    return 0;
}
