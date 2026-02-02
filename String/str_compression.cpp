#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Q 443. String Compression

//Date:-02-02-2026; Time:-3:00pm
//Solved: Accepted with Time complexity O(N) runtime 0ms and space complexity O(1);
//Solution:First i try to solve with my logic and found so many mistakes and after that the below is final solution from me

int compress(vector<char>& chars) {
        chars.push_back(' ');
        int n=chars.size();
        int index=0;
        int count=0;
        char curr_char=chars[0];

        for(int i=0;i<n;i++){
            if(chars[i]==curr_char){
                count++;
            }

            if(chars[i]!=curr_char || i==n-1){
                chars[index++]=curr_char;
                curr_char=chars[i];

                if(count==1) continue;
                else{
                    string scount=to_string(count);
                    for(char digit : scount){
                        chars[index++]=digit;
                    }
                }
                count=1;
            }
        }
        return index;
    }

//This is the youtube video solution with nearly same logic as i apply but it is easier to understand here.

int compress(vector<char>& chars) {
    int n=chars.size();
    int index=0;

    for(int i=0;i<n;i++){
        char ch=chars[i];
        int count=0;

        while(i<n && chars[i]==ch){
            count++,i++;
        }

        if(count == 1) chars[index++]=ch;
        else{
            chars[index++]=ch;
            string scount=to_string(count);
            for(char digit : scount){
                chars[index++]=digit;
            }
        }

        i--;
    }
    return index;
}