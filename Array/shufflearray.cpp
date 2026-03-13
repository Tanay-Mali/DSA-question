#include<iostream>
#include<vector>
using namespace std;

//Q1470. Shuffle the Array
// Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
// Return the array in the form [x1,y1,x2,y2,...,xn,yn].

//Date:25-01-2026
//Solved:Accepted with Time Complexiety O(N) runtime 0ms and space complexiety O(N);
//Solution: it is easy to solve. I just created a ans array of size 2n and track a pointer size on given nums array. As we move forward store that number in even indices and then again antoher loop to store remaining half or nums on odd indices


vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n,0);
        int size=0;
        for(int i=0;i<2*n;i+=2){
            ans[i]=nums[size];
            size++;
        }
        for(int i=1;i<2*n;i+=2){
            ans[i]=nums[size];
            size++;
        }
        return ans;
}

int main(){
    vector<int> nums={2,5,1,3,4,7};
    int n=3;
    vector<int> ans=shuffle(nums,n);
    return 0;
}