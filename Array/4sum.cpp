#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

//Q 18. 4Sum
// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
// 1. 0 <= a, b, c, d < n
// 2. a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

//Date:07-02-2026: Time:10:15am;
//Solved: Accepted with time complexity O(N³) runtime 327ms and space complexity O(N).
//I solved the question 3sum after watching the solution and the optimal solution.
//I use the thinking of the optimal solution my be there is even better approach i will try to find and optimize it.

//Solution: 
//I start with sorting the give array to implement my solution. we need to find 4 numbers sum upto target. so i select all possible pairs of first two numbers using loop then for remaining two number, we know the whole sum must be target and we have two numbers selected so sum of remaning two can be obtained by subtrating first two numbers from target now just apply the two pointer method to find the remaining two number because array is sorted.
//I store these ans in a set to avoid repetation and the push back all ans to vectored array and return it as answer.


vector<vector<int>> fourSum(vector<int>& nums, long target) {
        vector<vector<int>> ans;
        set<vector<int>> valid_ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long tofind = target-(nums[i]+nums[j]);
                if(tofind<INT32_MIN || tofind>INT32_MAX) continue;
                int k=j+1,t=n-1;
                while(k<t){
                    if(nums[k]+nums[t]==tofind){
                        valid_ans.insert({nums[i],nums[j],nums[k],nums[t]});

                    }
                    (nums[k]+nums[t]<=tofind)?k++:t--;
                }
            }
        }
        for(auto val: valid_ans){
            ans.push_back(val);
        }
        return ans;
    }


//This is also similar like solution. here i try to optimize the solution using hashing like we already choose first two numbers and for remaining two number i use hashing, use a loop for third number and try to find the fourth number in hash table if found then insert in our set if not then insert the third number in unorederd set so that next time when we need it we can access it in O(1) runtime.
//After this i thought it will improve runtime but instead runtime became 1745ms and time is same O(N³) ans space used is 474 mb which is bad
    
vector<vector<int>> fourSum(vector<int>& nums, long target) {
        vector<vector<int>> ans;
        set<vector<int>> valid_ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            for (int j = i + 1; j < n - 2; j++) {
                long sum_of_two=nums[i]+nums[j];
                unordered_set<int> number;
                for(int t=j+1;t<n;t++){
                    long missing = target-(nums[t]+sum_of_two);
                    if (missing < INT32_MIN || missing > INT32_MAX)
                        continue;
                    if(number.find(missing)!=number.end()){
                        valid_ans.insert({nums[i],nums[j],nums[t],(int)missing});
                    }
                    number.insert(nums[t]);
                }
            }
        }
        for (auto val : valid_ans) {
            ans.push_back(val);
        }
        return ans;
    }