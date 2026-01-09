#include <iostream>
#include<vector>
using namespace std;

//Q169. Majority Element
//Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.



int majorityElement(vector<int>& nums){
    int freq=0;//to track the frequency of the number;
    int curr=nums[0];//we set the a number to track;
    for(int i=0;i<nums.size();i++){
        if(curr==nums[i]){//if current number and number present at i index is same the freq will increase;
            freq++;
        }
        else{//if both are different then the power or strength of current num willl be decrease and hence its frequncy will decrease(consider it as voting the curr is most voted and different num is decreasing its voting by taking one vote from the arr);
            freq--;
        }
        if(freq<0){//if curr number lost his all votes and the other number is getting more votes then we will set it as the curr;
            freq=0;
            curr=nums[i];
        }
    }
    //finally the one who has most vote (the one who occur most in array) will have some frequncy at the end and that is our ans;
    return curr;

}
int main(){
    vector<int> nums={3,2,3};
    cout << majorityElement(nums);
    return 0;
}