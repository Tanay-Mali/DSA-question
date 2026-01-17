#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Q905. Sort Array By Parity
// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.Return any array that satisfies this condition.

//Date:-17-01-2026 Time:4:45pm;
//Solved with two approaches that came to my mind at first

//Solution
//In question it is said that any array can be return. If we consider to sort both part i.e. even and odd part to be sorted i think the First Approach; And if sorting is not considered in final return answer I think the Secnd approach;

//--Approach-1--// (Time Complexity O(N), Runtime 3ms, Space Complexity O(N))
//Basically I just make 2 different vector or Array for even and odd And linearly cross the given Array anf by conditions sort them in both array
//Both the Vector are taken of full size as per given array, Because we don't know the no.of odd and even in the vector it can be full of odd or even. After that sorting the no.of initial number in even and odd sums equal to size of given vector. We need even at first and odd after that part so i merge those vector in single array even and return that vector. But i failed to sort those array due to some issue i will define a proper sorting function for it and use it in this solution 

vector<int> sortArrayByParity1(vector<int>& nums) {
        int n=nums.size();
        vector<int> even(n,0);
        vector<int> odd(n,0);
        int ec=0;
        int oc=0;
        //Sorting of numbers in Even and Odd
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even[ec]=nums[i];
                ec++;
            }else{
                odd[oc]=nums[i];
                oc++;
            }
        }
        // sort(even.begin(),even.end());
        // sort(odd.begin(),odd.end());

        //Merge of two array
        int count=0;
        for(int i=ec;i<ec+oc;i++){
            even[i]=odd[count];
            count++;
        }
    return even;
}

//--Approach-2--// (Time Complexity O(N), Runtime 0ms, Space Complexity O(N))
//This approach is optimize of first approach which does not focus on the sorting this can only sort as per the given question if i can do i will try to add sorting in this approach also.
//In this solution i only declared a single answer Vector of size of given array. And set initial values even by tracking the pointer by variable front and set odd values from back side of answer array by tracking it pointer by variable back. And a single loop travel across the given array. Finally return that answer array.

vector<int> sortArrayByParity2(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int front=0;
        int back=n-1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[front]=nums[i];
                front++;
            }else if(nums[i]%2!=0){
                ans[back]=nums[i];
                back--;
            }
        }
        return ans;
}

int main(){
    vector<int> nums={3,1,2,4};
    vector<int> ans1=sortArrayByParity1(nums);
    vector<int> ans2=sortArrayByParity2(nums);
    for(int i=0;i<ans1.size();i++){
        cout<<ans1[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans2.size();i++){
        cout<<ans2[i]<<" ";
    }
    return 0;
}