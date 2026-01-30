#include<iostream>
#include<vector>
using namespace std;

//Q Painter's Partition Problem
// Given are N boards of length of each given in the form of array, and Mpainters, such that each painter takes 1 unit of time to paint 1 unit of the board.
// The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards
//This question is not on leetcode i saw it on youtube channel. And since this is a variant of book allocation question i solved it on self without any help

//Date:-30-01-2026,Time-11:00am
//Solution: This is a Variant of the question of Book Allocation. I had solved it you can find it here Binary-Search/bookallocation.cpp
//The logic is clearly same as that question here we have to minimize the maximum time taken by painter to paint the board.
//So i will suggest to either see the solution of book allocation question or on youtube video solution and try to think on yourself.
//Just one mistake that i do is for search space i took the str(or starting) As 0 assuming 0 unit time is minimum possible but this is not possible. So the minimum case will occur when we assign one painter to each board in that case the time will be minimum and equal to maximum length board 
//this is the only correction

bool isvalid(vector<int>& board,int n,int m,int mid){
    int painter=1;
    int len=0;
    for(int i=0;i<n;i++){
        if(len+board[i]<=mid){
            len+=board[i];
        }else{
            painter++;
            len=board[i];
        }
    }
    if(painter>m) return false;
    else return true;
}


int minitime(vector<int>& board,int n, int m){
    if(n<m) return -1;
    int maxtime=0;
    int mintime=0;
    for(int i=0;i<n;i++){
        maxtime+=board[i];
        mintime=max(mintime,board[i]);
    }
    int str=mintime,end=maxtime;
    int ans=0;
    while(str<=end){
        int mid=str+(end-str)/2;
        if(isvalid(board,n,m,mid)){
            ans=mid;
            end=mid-1;
        }else{
            str=mid+1;
        }
    }
    if(ans==0) return -1;
    else return ans;
}

int main(){
    vector<int> board={40,30,10,20};
    int n=4,m=2;
    cout<<minitime(board,n,m);
    return 0;
}