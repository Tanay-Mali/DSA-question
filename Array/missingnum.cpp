#include<iostream>
#include<vector>
using namespace std;

//Q268. Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.


int missingNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<=n;i++){
            bool isfound=false;
            for(int j=0;j<n;j++){
                if(i==nums[j]){
                    isfound=true;
                    break;
                }
            }
            if(!(isfound)){
                return i;
            }
        }
        return 0;
}

int main(){
    vector<int> nums={3,0,1};
    cout<<missingNumber(nums);
    return 0;
}