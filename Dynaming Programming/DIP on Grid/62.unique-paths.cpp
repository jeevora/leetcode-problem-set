/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    // bottom-Up
    int bottomUp(int m, int n){

        int dp[m][n];

        for (int row = 0; row < m; row++)
            dp[row][0] = 1;

        for (int col = 1; col < n; col++)
            dp[0][col] = 1;

        for (int row = 0; row < m; row++)
            for (int col = 0; col < n; col++)
                dp[row][col] =


        

    }
    // memoization
public:
    int uniquePaths(int m, int n) {
        
        // bottom-up
        return bottomUp(m,n);
    }
};
// @lc code=end

int main(){
    int m = 3, n = 7;

    Solution sl;
    cout << sl.uniquePaths(m,n);
}