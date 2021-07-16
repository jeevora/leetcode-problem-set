#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<cmath>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = 5;
        vector<int> ans;
        vector<vector<int>> result(numRows);
        for (int r = 0; r < numRows; r++){
            result[r].resize(r+1);
            result[r][0] = result[r][r] = 1;
            if(r == rowIndex)
                    ans.push_back(result[r][0]);
            for (int c = 1; c < r; ++c){
                result[r][c] = result[r-1][c-1] + result[r-1][c];
                if(r == rowIndex)
                    ans.push_back(result[r][c]);
            }
            if(r == rowIndex)
                    ans.push_back(result[r][r]);
        }
        return ans;  
    }
};


int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    Solution sl;

   
    int rowIndex = 3;
    // int rowIndex = 0;
    // int rowIndex = 1;

   sl.getRow(rowIndex);
}