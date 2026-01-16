#include<iostream>
#include<string>
#include<vector>
using namespace std;

//Q344. Reverse String
// Write a function that reverses a string. The input string is given as an array of characters s.You must do this by modifying the input array in-place with O(1) extra memory.

//Date:-16-01-2026 Time:-10:30am;
//Solved with time complexity O(n) and it is easy to solve also the space complexity of solution is O(1) since only one variable is declared
//Solution:
//Solution is easy just swap the first and last character.


void reverseString(vector<char>& s) {
        int i=0;
        while(i<s.size()-i-1){
            swap(s[i],s[s.size()-i-1]);
            i++;
        }
    }

int main(){
    vector<char> s= {'h','e','l','l','o'};
    reverseString(s);
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<" ";
    }
    return 0;
}