#include<iostream>
using namespace std;

//Q7. Reverse Integer
// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

//Date:-28-01-2026, Time:10:45am;
//Solved: Accepted with Time complexity O(log x) runtime 0ms and space complexity O(1);
//This is brute force approach because i can't do it without taking the ans in double type otherwise some cases are not passing.
//What I do is just take ans variable in double type and store the reverse of given int. Then check if the ans is out of the range of int then return 0 otherwise return that reverse integer. Some cases like if x=0 or x=-2147483648 return 0 because running loop on 0 is waste of time and negation of -2147483648 cannot be store in int type and it's reverse will overflow it's capacity so i handled them at first.

int reverse(int x) {
        // 2147483647;
        if(x==0 || x==-2147483648 || (x>1000000000 && x%10>2) ) return 0;
        double ans=0;
        int original=(x>=0)?x:-x;
        int digit;
        while(original>0){
            digit=original%10;
            ans=ans*10+digit;
            original/=10;
        }
        if(ans>=2147483648 || ans<-2147483648) return 0;
        if(x>=0) return ans;
        else if(x<0) return -ans;
        return -1;
    }