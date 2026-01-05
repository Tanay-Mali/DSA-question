#include<iostream>
#include<vector>
using namespace std;

//Q66. Plus One
//You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's. Increment the large integer by one and return the resulting array of digits.

//Solve on self no help needed no video needed with Time Complexity O(n) 
vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(0<=digits[n-(i+1)] && digits[n-(i+1)]<=8){
                digits[n-(i+1)]++;
                break;
            } else if(digits[n-(i+1)] == 9){
                digits[n-(i+1)]=0;
            }
        }
        if(digits[0]==0){
            digits.insert(digits.begin(),1);
            digits[1]=0;
        }

        return digits;
}

int main(){
    vector<int> digits={4,3,2,1};
    plusOne(digits);
    for(int i=0;i<digits.size();i++){
        cout << digits[i] << " ";
    }
}