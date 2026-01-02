#include<iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
        int sum=0,maxsum=INT32_MIN;
        for(int val:nums){
            sum += val;
            maxsum=max(maxsum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return maxsum;
    }

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int maxsum = maxSubArray(nums);
    cout<<maxsum<<endl;
    return 0;
}