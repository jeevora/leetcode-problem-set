#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

class Solution {
    // using topological sort


    // using dijkstra shortest path with adjLis + minHeap
    void dijkstra(vector<pair<int, int>> graph[], int src, int dst, vector<int>& ans){

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>> , greater<> > queue;

        vector<int> distance(n, INT_MAX);
        

    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        
        vector<pair<int, int>> graph[n];
        vector<int> shortestPath(n, 0);

        for(auto edge: edges)
            graph[edge[0]].push_back({edge[1],edge[2]}),
            graph[edge[1]].push_back({edge[0],edge[2]});

        // 1st step to calculate shortestpath from node 1 to last node
        for(int u = 1; u < n; ++u)
            dijkstra(graph, u, n, shortestPath);

        // remove unecessary edges to transform the graph as DAG

        // topologicalsort over DAG
    }
};

int main(){

    vector<vector<int>> edges = {
        {1,2,3},
        {1,3,3},
        {2,3,1},
        {1,4,2},
        {5,2,2},
        {3,5,1},
        {5,4,10}
    };
    int n = 3;

    Solution sl;
    cout << sl.countRestrictedPaths(n, edges);
}