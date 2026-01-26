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

//Date:26-01-2026, Time:12:00pm;
//Solved with Time complexity O(log N) runtime 0ms and Space Complexity O(1);
//Solution:I solved this using binary search to the target; if it is there the return it's index. Now the challenge is when the target is not present in the array.For that I just search if it can be between mid and mid+1 or mid-1 and this is simultaneous with searching the target.Like if the target is at mid then return if not then try to find is neighbout index.
//Second challenge is address overflow. If mid comes to index 0 or at end index then the condition i added will search beyond those index which are not present so i handled those two cases separately before starting of search.

int binarysearchInsert(vector<int>& nums,int target){
    int n=nums.size();
    int str=0;
    int end=n-1;
    if(target<nums[str]) return 0;
    if(target>nums[end]) return n;
    while(str<=end){
        int mid=str+(end-str)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[mid]>target && nums[mid-1]<target){
            return mid;
        } else if(nums[mid]<target && nums[mid+1]>target){
            return mid+1;
        }
        (nums[mid]<target)?str=mid+1:end=mid-1;
    }
    return -1;
}

int main(){
    vector<int> nums={1,3,5};
    int target=4;
    cout<<binarysearchInsert(nums,target)<<endl;
}