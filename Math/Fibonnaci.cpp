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

//Solution-2; Date:-08-02-2026; Time:4:15pm;
//Solved using loop and time complexity if O(N) runtime is 0ms and space complexity O(1);
//Using the main idea i.e. number on any index is equal to sum of previous two i store the first two of base in prevans1 and 2 and start loop with i=2 because numbers on 0th and 1st index are already taken in prevans the run the loop by adding both the prevans and changing the value of prevans1 to prevans2 and prevans2 to ans;
//here prevans1=f(n-2) and prevans2=f(n-1)

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int ans;
    int prevans1=0;
    int prevans2=1;
    for(int i=2;i<=n;i++){
        ans=prevans1+prevans2;
        prevans1=prevans2;
        prevans2=ans;
    }
    return ans;
    
}

int main(){
    int n=4;
    cout<<fib(n)<<endl;

    return 0;
}