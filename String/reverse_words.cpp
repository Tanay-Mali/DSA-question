#include<iostream>
#include<string>
using namespace std;

//Q151. Reverse Words in a String
// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

//Date:-02-02-2026; Time:- 10:30am
//Solved: Accepted with time complexity O(N) Runtime 0ms and Space complexity O(M) Here N=length of given string and M is length of ans string;

//Approach 1;
//Solution: This is may be brute force approach that came to my mind first but i will try to find the optimal approach also.
//I start with thinking how should i start to store it then i remember we have function push_back and push _front but in case of string there is no push_front so i had to rewrite the whole function using push_back.
//So now we have a function push_back. I use it as track or find the word from backside of given string and then start to push back it's letters from starting to the ans string.
//To track the word i use two pointer str and end. end will be point to end of the word while str will point to start of word.
//We started the loop from back side so end will be at same position and if there is no space at str pointer then move it or decrement it. If we found a space (' ') at str pointer then start a new loop to push_back the word letter by letter until it hit the end pointer after the loop end i push_back a space and move str or decrement and positioned end to str also.
//to avoid extra spaces if there is " " space on end point we will move it with str point and continue the loop.
//The edge case is when str==0 and it is also a character then according to condition it will decrement the str which leads to address overflow pointing to index=-1. to avoid that i use different condition when str hits 0 and it is a charater the push_back the word and break the loop;
//Then at end i use condition to check any trailing space


string reverseWords(string s) {
    int n=s.length();
    string ans="";
    int str=n-1,end=n-1;
    for(int i=n-1;i>=0;i--){
        if(s[end] == ' '){
            str--;
            end--;
            continue;
        }
        if(s[str]!=' ' && str!=0){
            str--;
        }else if(str==0 && s[str]!=' '){
            for(int j=str;j<=end;j++){
                ans.push_back(s[j]);
            }
            break;
        }
        
        else if(s[str]==' ' && end!=' '){
            for(int j=str+1;j<=end;j++){
                ans.push_back(s[j]);
            }
            ans.push_back(' ');
            str--;
            end=str;
        }
    }
    if(ans[ans.length()-1]==' ') ans.erase(ans.length()-1,1);       
    return ans;

}

//Approach-2;
//Solution: This is the solution i watch in video solution. This is also with time complexity O(N). The login was whole string is reverse in order but the order of word is not change. So first we reverse the whole string then starting with first index store the word in string word reverse it and append in final ans. To avoid the adding of space we make sure that the length of word is >0 and return the answer without the first index because when we append first word it will also append a leading " " 

string reverseWords(string s) {
        int n=s.length();
        string ans="";
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            if(word.length()>0){
            reverse(word.begin(),word.end());
            ans+=" "+word;}
        }
        return ans.substr(1);
    }

int main(){
    string s="  Hello    World    ";
    string rev=reverseWords(s);
    cout<<rev;
}