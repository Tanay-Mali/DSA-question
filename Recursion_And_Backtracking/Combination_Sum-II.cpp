#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Date:15-02-2026: Time: 5:00pm
//Solved: Accepted with runtime 0ms

//Solution:
//The solution is diffucult to explain here i will try to make a video solution of how i solved it using backtracking and recursion tree.
//The only way to understand this is by recursion tree 

void combinesum(vector<int>& candy, int tar, vector<vector<int>>& ans,
                    vector<int>& sum, int idx) {
        int n = candy.size();
        // int val;
        for (int i = idx; i < n; i++) {
            if (i > idx && candy[i] == candy[i - 1])
                continue;
            int val = tar - candy[i];
            sum.push_back(candy[i]);
            if (val == 0) {
                ans.push_back(sum);
                sum.pop_back();
                return;
            } else if (val > 0) {
                combinesum(candy, val, ans, sum, i + 1);
            } else {
                sum.pop_back();
                return;
            }
            sum.pop_back();
            // if(ans.size()>0){
            //     sum.pop_back();
            // }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sum;
        sort(candidates.begin(), candidates.end());
        combinesum(candidates, target, ans, sum, 0);
        return ans;
    }

int main(){
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> ans=combinationSum2(candidates,target);
    return 0;
}