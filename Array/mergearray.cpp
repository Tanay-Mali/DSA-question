#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Q88. Merge Sorted Array
// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order. The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

//Date:-12-01-2026 Time:-9:18 am
//It's too easy to solve but currently confused
//Solution Was accepted on leetcode with runtime 0ms ; but i use library function for sorting for now i will also try with sorting algorithm like bubble , insertion and selection;
//currently i am confuse because the library function sort was accepted on leetcode but in my local device it shows error like sort was undefine
//Time Complexity is O((N+M)log(M+N));
//Updated :- So we have to include the library <algorithm> to use the library function sort();
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;i<m+n,j<n;i++,j++){
            nums1[i]=nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }

//Date:-12-01-2026 Time:-9:35 pm
//Solving with bubble sort algorithm
//Accepted with runtime 4ms may be time complexity is O(n^2);  Since for merging it is m-n let it is N and for sorting it is (m+n)^2 so altogeter may be it is O((m+n)^2)
void mergeBubbleSort(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m,j=0;i<m+n,j<n;i++,j++){
            nums1[i]=nums2[j];//Merging
        }
        for(int i=0;i<m+n-1;i++){
            for(int j=0;j<m+n-1;j++){
                if(nums1[j]>nums1[j+1]){
                swap(nums1[j],nums1[j+1]);//Sorting
                }
            }
            
        }
    
    }


int main(){
    vector<int> nums1={1,2,3,0,0,0};
    vector<int> nums2={2,5,6};
    int m=nums1.size();
    int n=nums2.size();
    mergeBubbleSort(nums1,m,nums2,n);
    for(int i=0;i<m;i++){
        cout<<nums1[i]<<" "<<endl;
    }
    return 0;
}