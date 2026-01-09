#include<iostream>

using namespace std;

// 69. Sqrt(x)
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well. You must not use any built-in exponent function or operator.

//Solved on self with time complexity O(n) but still runtime was 34ms 


int mySqrt(int x) {
        long ans=1; // Defined long because the edge case of taking x=2147483647 make the int overflow to calculate square of a big number so we defined as long, Making it double also bring solution 
        while(true){
            
            if(ans*ans<x){
                ans++;
            }
            else if(ans*ans>x){
                return ans-1;
            }
            if(ans*ans == x){
                return ans;
            }
        }
    }


int main(){
    int x=8;
    cout<<mySqrt(x)<<endl;
}