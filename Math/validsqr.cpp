#include<iostream>
#include<vector>
using namespace std; 
 
//Q367. Valid Perfect Square
// Given a positive integer num, return true if num is a perfect square or false otherwise. A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.
// You must not use any built-in library function, such as sqrt.

//Date:-24-01-2026 Time:-11:30am;
//Solution:Accepted with Time Complexiety O(log n) Runtime 0 ms and Space Complexiety O(1);
//Solved with binary search on the search space. The search space is something different but i choose it to avoid the problem of overflow because int can store up to number 2³¹-1. And if we square a number after a certain range it will overflow the limit of int. So first i find root of 2³¹ i.e. 46341 approx. Then the valid search space of square root of any numb is from 1 to half of that number. And if half of that number is greater that 46341 then it's square will exceed the limit of int and overflow error will occur so i keep the condition to decide the end of search space if it is greater than 46340 then end will be same otherwise end will be half of that number and if we find a valid square root of that number then return value will be true otherwise false.
//The only case is of number of 4 where it's root is half of that number so i handled that case and case of 1 separately at the beginning.
//Now if we have Valid search space we will start binary search where if square of mid is greater than given number end=mid-1 otherwise start=mid+1
//Now there is a second method also. The method it to find factors of that number. No.of factors of a number which is a perfect square is a odd number. But this will result in time Complexiety O(N). So I think with binary search first. 


bool isPerfectSquare(int num) {
        int str=1;
        int end=(num/2>46340)?46340:num/2;
        cout<<end;
        if(num==1) return true;
        if(num==4) return true;
        while(str<=end){
            int mid=str+(end-str)/2;
            if(mid*mid==num){
                return true;
            }
            (mid*mid<num)?str=mid+1:end=mid-1;
        }
        return false;
    }

int main(){
    int num=2147483647;
    bool isvalid=isPerfectSquare(num);
    cout<<isvalid;
    return 0;
}