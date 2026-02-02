#include<iostream>
#include<string>
using namespace std;


//Q8. Length of Last Word
// Given a string s consisting of words and spaces, return the length of the last word in the string.
// A word is a maximal substring consisting of non-space characters only.

//Date:02-02-2026; Time:-5:30pm
//Solved: Accepted with Time Complexity O(N) in worst case if the whole string is a single word and runtime 0ms and space complexity O(1).
//Solution:
//The approach is first start a reverse loop because we have to find the length of last word. avoid initial spaces for the i use if condition and continue the loop. then else if condition when i am at end of word and the character just before the current character is space then increment the length and break the loop. and else the current charater will be a alphabet so increment the length. this is my line of thinking. I comment out my logic. Because i saw the solution where to avoid initial space and break the loop when the word is at end that person just use simple condition that is current charater is space and length is >0 break the loop. which is easy because if length is >0 then the word is started and any space occur means word is end, break the loop.


int lengthOfLastWord(string s) {
        int length=0;
        int n=s.length();
        if(n==1 && s[0]!=' ') return 1;
        for(int i=n-1;i>=0;i--){

            // if(s[i]==' '){
            //     if(length>0) break;
            //     continue;
            // }else if(i>=1 && s[i]!=' ' && s[i-1]==' '){
            //     length++;
            //     break;
            // }
            // else{
            //     length++;
            // }

            if(s[i]==' '){
                if(length>0) break;
            }
            else{
                length++;
            }
            
        }
        return length;
    }

int main(){
    string s=" Luffy is still joyboy  ";
    cout<<lengthOfLastWord(s);

    return 0;
}