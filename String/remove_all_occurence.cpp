#include<iostream>
#include<string>
using namespace std;

//Q 1910. Remove All Occurrences of a Substring
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:
// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

//Solved: Accepted with Time Complexity O(N*M) Runtime 3ms and space complexity O(N).
//I don't know about the function of string str.find() to find the index of substring in a string and str.erase(str,end) to remove a part of string. Once i know about them then i try it on my self and write this solution.
//Approach: so i run a loop to find the position of substring if it is found then the value will be less than lenght of actual string. I try to enter the substring part which was not int the string then it return a big value so i keep the constraint in loop if not found then break the loop and return the and string  

string removeOccurrences(string s, string part) {
    string ans=s;
    int n=part.length();
    int position=-1;
    while(true){
        position=ans.find(part);
        if(position>s.length() || position<0){
            break;
        }
        ans.erase(position,n);
    }
    return ans;
}

//Now this is also a same approach but i saw this on youtube solution. this is with improve space complexity O(1). where the constraint which i write in the loop uing if condition. here we use those constraint to stop the loop.
string removeOccurrences(string s, string part) {
    while(s.length()>0 && s.find(part)<s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){
    string s="daabcbaabcbc";
    string part="abc";
    string ans=removeOccurrences(s,part);
    cout <<ans;
    return 0;
}