#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
    }
};

int main()
{
    //edge as adjMatrix
    vector<vector<int>> prerequisites = { 
        {1,0}
    };

    vector<vector<int>> queries = { 
        {0,1},
        {1,0}
    };
    int numCourses = 4;
    
    Solution sl;
    for(auto it: sl.checkIfPrerequisite(numCourses, prerequisites, queries))
        cout << it << "\n";
}