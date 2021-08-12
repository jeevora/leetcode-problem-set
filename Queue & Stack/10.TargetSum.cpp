#include<iostream>
#include<set>
#include<vector>

using namespace std;

//Backtracking / Recursion
class Solution {
    void backtrack(vector<int>& nums, int target, int sum, int pos, int& count){
        if(pos == nums.size()){
            if(sum == target) count++;
            return;
        }
        backtrack(nums, target, sum + nums[pos], pos + 1, count);
        backtrack(nums, target, sum - nums[pos], pos + 1, count);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, target, 0, 0, count);
        return count;
    }
};

//Dynamic Programing
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;

        for(auto x: nums) sum += x;

        if(sum < S || -sum > S) return 0;

        vector<int>cur(2 * sum + 1);
        vector<int>next(2 * sum + 1);
        
        cur[sum] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < 2 * sum + 1; j++){
                if(cur[j] != 0){
                    next[j + nums[i]] += cur[j];
                    next[j - nums[i]] += cur[j];
                    cur[j] = 0;
                }
            }
            swap(cur, next);
        }
        return cur[sum + S];
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    vector<int> nums = {1,1,1,1,1};
    int target = 3;
 
    Solution sl;
    cout << sl.findTargetSumWays(nums,target);
}