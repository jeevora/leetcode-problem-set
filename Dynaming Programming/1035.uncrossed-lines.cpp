/*
 * @lc app=leetcode id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

// @lc code=start
class Solution {
    // bottom-Up aproach
    int bottomUp(vector<int>& nums1, vector<int>& nums2){

        int n = nums1.size(), w = nums2.size();

        int dp[n+1][m+1];

        for(int row = 0; row <= n; ++row)
            dp[row][0] = 0;
        for(int col = 0; col <= w; ++col)
            dp[0][col] = 0;
        
        for(int row = 0; row <= n; ++row)
            for(int col = 0; col <= w; ++col){

                if(col < nums1[row-1])
                    dp[row][col] = 

            }


        

    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
    }
};
// @lc code=end

int main(){
    vector<int> nums1 = {2,5,1,2,5}, nums2 = {10,5,2,1,5,2};

    Solution sl;
    cout << sl.maxUncrossedLines(nums1,nums2);
}
