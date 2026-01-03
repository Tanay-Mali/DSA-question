#include<iostream>
#include<vector>

using namespace std;

int removeDuplicates(vector<int> &nums){
    int k=0;
    int curr=nums[0];
    for(int i=0;i<nums.size();i++){
        if(nums[i] == curr){
            continue;
        }
        else{
            k++;
            curr=nums[i];
            nums[k]=curr;
        }
    }
    return k+1;
}

int main(){
    vector<int> nums={0,0,1,1,1,2,2,3,3,4};
    cout<<removeDuplicates(nums)<<endl;
}