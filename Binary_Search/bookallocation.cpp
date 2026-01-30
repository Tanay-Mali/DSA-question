#include<iostream>
#include<vector>
using namespace std;


//Q. Book Allocation Problem
// There are N books, each ith book has A[i] number of pages.
// You have to allocate books to M number of students so that the maximum number of pages allocated to a student is minimum.
// Each book should be allocated to a student.
// Each student has to be allocated at least one book.
// Allotment should be in contiguous order.
// Calculate and return that minimum possible number.
// Return -1 if a valid assignment is not possible.

//Date:-30-01-2026, Time:10:15am
//This question is not present on leetcode. But i saw it on Youtube. In first instance I can't even find the brute force approach so i just watch the video solution and understand the solution logic properly then after many day's taday i try to write it without watching the solution a successfully write the solution.
//This is the video by which I just not develope that logic but also use the logic to solve the question of H-index which was in this repository Array/h-index.cpp 

//Solution: This may be difficult to understand so i will suggest to watch the video solution on the Apna college channel.
//The solution starts from a search space we need i sorted search space for binary search. Taking in mind the maximum pages we can allot is sum of all pages and minimum is 0; so we will run binary search on this range 0-sum of all pages. Now the main thing is to decide whether to go left or right in search space. So we need to minimize the maximum alloted pages. In search space the number on mid is valid or not Like can we allote pages to m no.of students while pages to one student<=mid. to check this we write anothor function is valid.
//Now if the mid is valid means we can allote pages to m students while no one will get pages greater that mid. So this is possible solution to minimize it we will cancel the right half and search in left half. And the else case is if it is not valid we will serach in right half while cancel the left half. 

bool isvalid(vector<int>& book, int m, int mid){
    int student=1;
    int pages=0;
    for(int i=0;i<book.size();i++){
        if(pages+book[i]<=mid){
            pages+=book[i];
        }else{
            student++;
            pages=book[i];
        }
    }
    if(student>m) return false;
    else return true;
}


int bookallocation(vector<int>& book, int m){
    if(m>book.size()) return -1;
    int maxpages=0;
    for(int i=0;i<book.size();i++){
        maxpages+=book[i];
    }
    int str=0,end=maxpages;
    int ans=0;
    while(str<=end){
        int mid=str+(end-str)/2;
        if(isvalid(book,m,mid)){
            ans=mid;
            end=mid-1;
        }else{
            str=mid+1;
        }
        cout<<ans<<endl;
    }
    if(ans==0)return -1;
    else return ans;
    
}


int main(){
    vector<int> book={2,1,3,4};
    int m=2;
    cout<<bookallocation(book,m);
    
    return 0;
}