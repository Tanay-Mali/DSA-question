#include<iostream>
using namespace std;

// 191. Number of 1 Bits
// Given a positive integer n, write a function that returns the number of set bits in its binary representation (also known as the Hamming weight).

//Date:21-01-2026 Time:7:00pm;
//Solved:Accepted with Time Complexiety O(log n) Runtime 0ms and Space comlexiety O(1);
//It is easy question if you know how to convert a decimal to binary. To convert it just divide the decimal number by 2 until it reaches to 0 and record all the remainders and arrange them in reverse order as you obtain. Means the last remainder you obtain is first bit of the binary from. Now to count the no.of 1-bits in its binary form just count it when the reaminder is 1 when number is divided by 2 and hence you get no.of 1-bits in its binary from  


int hammingWeight(int n) {
        int count=0;
        int origin=n;
        while(origin>0){
            if(origin%2 == 1){
                count++;
            }
            origin/=2;
        }
        return count;
    }

int main(){
    int n=11;
    cout<<hammingWeight(n);
    return 0;
}