#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

//Q 2965. Find Missing and Repeated Values
// You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
// Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

//Date:-05-02-2026;
//Solved:Accepted with Time Complexity O(N²) runtime 0ms and space complexity O(N²).
//Solution:
//We use unordered set for hashing. It is like i solve whole question and it is got accepted but after i watch the solution i got the optimization using maths.
//We have two aims here first find the repeated number and a missing number who's place was taken by the repeated number.
//The solution starts with Making a set where we will store all values one by one and check whether the current value is already existed in the set. And that's why we use unordered set because .find() use O(1) time complexity. So if any number is repeated it will 100% found in the set. after that i just store all the remaining numbers in the set without breaking the loop. and after that loop i again run a loop on the set because all the unique numbers from grid will be in set. and grid consist of all the numbers from 1 to n², the loop will check whether each number between that range is exists in set or not the one which does not there is our ans.
//But the optimization i got from video does not use the loop it use maths. since we know the grid will contain the number from that range so we know what sum is expected but the grid contains on repeated number and one is missing so grid sum will be different.
//It is like we add the repeated number in expected sum and remove the missing number and this is our actual sum of the given grid, to get the missing number we can just subtract actual sum of grid from the expected and add the repeated number
//for example consider 2x2 grid let it be {{1,2},{3,3}} so here the n=2 repeated number is 3 
//we know that sum of natural numbers from 1 to x is x(x+1)/2 in this case x=n² so expected sum  will be 4(5)/2=10;
//now see this illustration the expected sum is obtain by this 1+2+3+4 = 10 but from actual grid the sum is 9;
//(1+2+3+4)+3-b=9; here b is the repeated number and we add 3 in expected sum because it is repeated; from this we get b=4. and that is correct 4 is missing.
//So this is the optimization using maths.

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_set<int> values;
        vector<int> ans(2,0);
        int sum=0,sec;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                if(values.find(grid[i][j])!=values.end()){
                    ans[0]=grid[i][j];
                }
                values.insert(grid[i][j]);
            }
        }
        int expectedsum=(n*n) * ((n*n)+1)/2;
        sec=ans[0]+expectedsum-sum;
        ans[1]=sec;
        return ans;
    }