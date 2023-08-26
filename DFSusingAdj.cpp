#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;

class Solution {
  private: 
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1; 
        ls.push_back(node); 
        // traverse all its neighbours
        for(auto it : adj[node]) {
            // if the neighbour is not visited
            if(!vis[it]) {
                dfs(it, adj, vis, ls); 
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // vis is an array used for storing visited nodes
        int *vis = new int();
        for(int i=0;i<V;i++)
           vis[i]=0;
        int start = 0;
        // create a list to store dfs
        vector<int> ls; 
        // call dfs for starting node
        dfs(start, adj, vis, ls); 
        return ls; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    ifstream inputFile("data.txt"); // Open the file
    
    if (!inputFile) {
        cerr << "Error opening file." << endl;
        return 1;
    }
    int m,n;

    vector <int> adj[10];
    int count = 0;

    if(inputFile.eof())
        cout<<"No data in the file";

    while (inputFile>>m>>n) 
        addEdge(adj, m, n);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(9, adj);
    printAns(ans);

    return 0;
}