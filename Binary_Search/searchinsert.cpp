#include<iostream>
#include<vector>
using namespace std;


//Q35. Search Insert Position
// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
// You must write an algorithm with O(log n) runtime complexity.

//This solution is accepted with Time Complexity O(n) (Date:-11-01-2026 ; Time:-8:20am)
int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == target){
                return i;
            }
            else if(target < nums[i]){
                return i;
            }
        }
        return n;
    }

int main(){
    vector<int> nums={1,3,5,6};
    int target=7;
    cout<<searchInsert(nums,target)<<endl;
}