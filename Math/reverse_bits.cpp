#include<iostream>
#include<string>
using namespace std;

//Q 190. Reverse Bits
// Reverse bits of a given 32 bits signed integer

//Here reverse bits means reverse the order of bits in its binary form i misunderstood it is invert the bits, but that's not the case.

//Date:-03-02-2-2026; Time:-12:15pm;
//Solved: Accepted with Time Complexity O(1) runtime 5ms and space complexity O(1);
//Solution:
//My main logic is to convert the integer in it's binary form in string and it is a 32-bit integer so string length is also constant 32 bits.
//But when we start to form the binary form we get its bits as most significant to least significant. and the number we need has absolutely this order of bits in same order. so instead of converting the integer to binary form i just get the bits and form that string.
//Now to convert this string to int new function toint is used just a normal logic to convert binary to int. 

//This is function used to convert the int to bianry but instead i use the same loop and varibles in the reverseBit function so i comment this function and use the logic in answer function.
// string tobinary(int n){
//     string binary(32,'0');
//     int original=n;
//     int m=0;
//     while(original>0){
//         binary[m]=(original%2==1)?'1':'0';
//         original/=2;
//         m++;
//     }
//     return binary;
// }
long toint(string s){
    long x=1;
    long ans=0;
    for(int i=31;i>=0;i--){
        if(s[i]=='1'){
            ans+=x;
        }
        x*=2;
    }
    return ans;
}
int reverseBits(int n) {
    // string binform=tobinary(n);
    string binary(32,'0');
    int original=n;
    int m=0;
    while(original>0){
        binary[m]=(original%2==1)?'1':'0';
        original/=2;
        m++;
    }
    int ans=toint(binary);
    return ans;
}