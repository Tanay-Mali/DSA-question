#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
 

//Q31. Next Permutation
// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

//Date:-31-01-2026, Time:4:30pm
//Solution: I just learn that thing from video solution so it is hard to explain right now, once i familiar with it i will do.

void nextPermutation(vector<int>& A){
    int pivot=-1;
    int n=A.size();
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            pivot=i;
            break;
        }
    }
    if(pivot==-1){
        reverse(A.begin(),A.end());
        return;
    }

    for(int i=n-1;i>=pivot;i--){
        if(A[i]>A[pivot]){
            swap(A[i],A[pivot]);
            break;
        }
    }

    int i=pivot+1,j=n-1;
    while(i<=j){
        swap(A[i++],A[j--]);
    }
}

int main(){
    vector<int> num={1,2,6,5,3,4};
    nextPermutation(num);
    for(int i=0;i<num.size();i++){
        cout<<num[i]<<" ";
    }
    return 0;
}