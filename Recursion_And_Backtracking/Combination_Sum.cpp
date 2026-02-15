#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Date:15-02-2026: Time: 4:30pm
//Solved: Accepted with runtime 4ms

//Solution:
//The solution is diffucult to explain here i will try to make a video solution of how i solved it using backtracking and recursion tree.
//The only way to understand this is by recursion tree 


void combinesum(vector<int>& candy, int tar, vector<vector<int>>& ans,
                    vector<int>& sum, int idx) {
        int n = candy.size();
        // int val;
        for (int i = idx; i < n ; i++) {
            int val = tar - candy[i];
            sum.push_back(candy[i]);
            if (val == 0) {
                ans.push_back(sum);
                sum.pop_back();
                return;
            } else if (val > 0) {
                combinesum(candy, val, ans, sum, i);
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

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sum;
        sort(candidates.begin(),candidates.end());
        combinesum(candidates, target, ans, sum, 0);
        return ans;
    }

int main(){
    vector<int> candidates={2,3,6,7};
    int target=7;
    vector<vector<int>> ans=combinationSum(candidates,target);
    return 0;
}