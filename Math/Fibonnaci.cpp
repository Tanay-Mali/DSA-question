#include<iostream>
using namespace std;

//Q509. Fibonacci Number
//The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
// F(0) = 0, F(1) = 1
// F(n) = F(n - 1) + F(n - 2), for n > 1.
// Given n, calculate F(n).

//Solved using recursion but got Time Complexity =O(2^N) , and runtime of 10ms;
//Soon Try to solve using Loops to get time complexity O(n); 

int fib(int n) {
        if(n==1){
            return 1;
        }
        if(n==0){
            return 0;
        }
        return fib(n-1)+fib(n-2);
    }

int main(){
    int n=4;
    cout<<fib(n)<<endl;

    return 0;
}