#include<iostream>
#include<string>
using namespace std;


//Q125. Valid Palindrome
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

//Date:-27-01-2026, Time:6:30pm;
//Solved: Accepted with time O(N) runtime 3ms and space complexity O(N). Since we have to travel the whole string so time complexiety will be O(N) and i use the approach to store the string only with alphnumeric values so that's why space complexity is O(N).
//Solution:The approach is easy but i got so many errors and finally came to the solution which is given below. First i count no.of alphanumeric charaters in string using loop to make perfect size string to store the string only with alphanumric character. Then store that string in x then compare the first and last corresponding character is same or not if not same then return false else after end of loop it will return true which means it is a palindrome.

bool isPalindrome(string s) {
        int size=0;
        for(int i=0;i<s.size();i++){//counting the no.of alphanumeric charaters.
            if(s[i]!=' ' && ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) || (s[i]>='0' && s[i]<='9')){
                size++;
            }
        }
        string x(size,'a');
        int index=0;//To track the index of string x;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z'){
                s[i]+=32;
            }
            if(s[i]!=' ' && ((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9') )){
                x[index]=s[i];
                index++;//increment only when new valid character is added to x then point to next index.
            }
        }
        for(int i=0,j=size-1;i<j;i++,j--){//checking whether the string is palindrome or not
            if(x[i]!=x[j]){
                return false;
            }
        }
        return true;
    }

int main(){
    string s="A man, a plan, a canal: Panama";     //The reverse string will be "amanaplanacanalpanama" which is palindrome;
    cout<<isPalindrome(s);
}