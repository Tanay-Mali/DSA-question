#include<iostream>
#include<vector>

using namespace std;

int binarysearch(vector<int> &nums, int target){
    int n = nums.size();
    int str=0;
    int end=n-1;
    while(str<=end){
        int mid=str+(end-str)/2;
        if(nums[mid] == target){
            return mid;
        }
        (target<nums[mid])?end=mid-1:str=mid+1;
    }
    return -1;
}

int main(){
    vector<int> nums={1,0,3,5,9,12};
    int target=9;
    cout<<binarysearch(nums,target);
    return 0;
}