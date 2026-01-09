#include <iostream>
#include <string>
#include<vector>
using namespace std;

//Q13. Roman to Integer
//Que is to just convert the Give Roman number in String form to Integer and return the int value

//NOTE:
//Symbol       Value
// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

//Solve on self using only onee hint from leetcode by time complexity O(n); and runtime 0ms
//Hint is to try the question from Right → left
//first self solved have runtime of 2ms but then i gave it to chatgpt it also says it is right just update the previous at the end of loop because i am updating previous in every if else block so due to which runtime was 2ms but after the small correction of chatgpt give me learing and runtime 0ms




int romanToInt(string s) {
        char previous;
        int ans=0;

        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == 'I'){
                if(previous == 'V' || previous == 'X'){
                    ans-=1;
                }else{
                ans+=1;}
            }else if(s[i] == 'V'){
                ans+=5;
            }else if(s[i] == 'X'){
                if(previous == 'L' || previous == 'C'){
                    ans-=10;
                }else{
                ans+=10;}
            }else if(s[i] == 'L'){
                ans+=50;
            }else if(s[i] == 'C'){
                if(previous == 'D' || previous == 'M'){
                    ans-=100;
                }else{
                ans+=100;}
            }else if(s[i] == 'D'){
                ans+=500;
            }else if(s[i] == 'M'){
                ans+=1000;
            }
            previous = s[i];
        }
    return ans;
        
    }

int main(){
    
    int x=5274;
    string roman="MCMXCIV";
    cout<< romanToInt(roman);

    return 0;
}