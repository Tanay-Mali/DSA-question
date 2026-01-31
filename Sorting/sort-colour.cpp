#include<iostream>
#include<vector>
using namespace std;

//Q75. Sort Colors
// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

//Date-31-01-2026, Time:11:00am
//Solved:Accepted with Time Complexity O(N), Runtime 0ms, Space Complexity O(1);
//Solution: The first brute force approach came to my mind is normal bubble sort. But it will take O(N²) TC. So i start to think about different approach but can't think a proper approach. Then i watch the logic on video solution then try to write code on my self and it works. 

void sortColor(vector<int>& arr){
    int zero=0,one=0,two=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) zero++;
        else if(arr[i]==1) one++;
        else two++;
    }
    for(int i=0;i<arr.size();i++){
        if(zero!=0) {
            arr[i]=0;
            zero--;
        }else if(one!=0){
            arr[i]=1;
            one--;
        }else{
            arr[i]=2;
            two--;
        }
    }
}

//This is Optimal approach the DNF algorithm (Dutch National Flag)

void sortColor(vector<int>& arr){
    int mid=0,high=arr.size()-1,low=0;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }else{
            mid++;
        }
    }
}

int main(){
    vector<int> arr={2,0,2,1,1,0,1,2,0,0};
    sortColor(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}