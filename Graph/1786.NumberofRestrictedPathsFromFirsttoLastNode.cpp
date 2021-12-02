#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>

using namespace std;

class Solution {
    // using topologicalsort dfs + stack + backtracking without keeping the visited node
    // also it is necessary Dynaminc programing
    void dfs(int u, int dst, string path, vector<pair<int, int>> graph[], stack<string>& topologicalsort){

        for(auto it: graph[u]){
            int v = it.first;
                dfs(v, dst, path + to_string(u) + "->", graph, topologicalsort);
        }
        // backtracking
        if(u == dst)
            topologicalsort.push(path + to_string(u));
    }
    // Run a Dijkstra from node numbered n to compute distance from the last node.
    // using dijkstra shortest path with adjLis + minHeap O(e logv)
    void dijkstra(vector<pair<int, int>> graph[], int n, int src, int dst, vector<int>& ans){

        priority_queue< pair<int,int>, vector<pair<int,int>> , greater<> > p_queue;

        vector<int> distance(n, INT_MAX);

        p_queue.push({0,src});

        while (!p_queue.empty())
        {
            int u = p_queue.top().second;
            int dis = p_queue.top().first;
            p_queue.pop();

            if(u == dst)
                break;

            for(auto it: graph[u]){
                
                int v = it.first;
                int w = it.second;

                if(distance[v] > dis + w)
                    distance[v] = dis + w,
                        p_queue.push({distance[v], v});
            }
        }
        ans[src] = distance[dst];
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        n+=1;
        vector<pair<int,int>> graph[n];
        vector<int> shortestPath(n, 0);

        for(auto edge: edges)
            graph[edge[0]].push_back({edge[1],edge[2]}),
                graph[edge[1]].push_back({edge[0],edge[2]});

        // 1st step to calculate shortestpath from node 1 to last node
        for(int u = 1; u < n-1; ++u)
            dijkstra(graph, n, u, n-1, shortestPath);

        // remove unecessary edges to transform the graph as DAG
        // Consider all edges [u, v] one by one and direct them such that distance of u to n > distance of v to n.
        // If both u and v are at the same distance from n, discard this edge.
        for(auto& v: graph)
            v.clear();

        for(auto edge: edges){
            if(shortestPath[edge[0]] > shortestPath[edge[1]])
                graph[edge[0]].push_back({edge[1], edge[2]});
            else if(shortestPath[edge[0]] < shortestPath[edge[1]])
                graph[edge[1]].push_back({edge[0], edge[2]});
        }

        // topologicalsort over DAG
        // Now this problem reduces to computing the number of paths from 1 to n in a DAG, a standard DP problem.
        stack<string> topologicalsort;

        dfs(1, n-1, "", graph, topologicalsort);
        
        return topologicalsort.size();
    }
};

int main(){

    //ex1
    // vector<vector<int>> edges = {
    //     {1,2,3},
    //     {1,3,3},
    //     {2,3,1},
    //     {1,4,2},
    //     {5,2,2},
    //     {3,5,1},
    //     {5,4,10}
    // };
    // int n = 5;

    //ex2
    vector<vector<int>> edges = {
        {1,3,1},
        {4,1,2},
        {7,3,4},
        {2,5,3},
        {5,6,1},
        {6,7,2},
        {7,5,3},
        {2,6,4}
    };
    int n = 7;

    Solution sl;
    cout << sl.countRestrictedPaths(n, edges);
}
