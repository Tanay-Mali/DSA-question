#include<iostream>
#include<string>
using namespace std;

//Q8. String to Integer (atoi)
// Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

//Date:-28-01-2026, Time:-5:20pm;
//Solved: Accepted with time complexity O(N) runtime 0ms and Space complexity O(1);
//Solution: This solution is full of cases that came across me while submitting the solution so i include some of the cases in main function. By observing them and other situation that came to my mind i finally made this solution which is correct;

//If i can't explain it whole here i would suggest to dry run this function with the cases that i provided in main function may be you will get how i handle each case.
//So first i start with non-digits if any non-digit occur then just break the loop and return the current ans;
//Then with "-" sign which has particularlly 2 cases if it is before the number then it means the number is nrgative. Or if it is before any other character then it is a charater break the loop. But still there is some cases if '-' id between two numbers like case s1 in main function then we have to break the loop. So for that i just make a bool to track if the number is started, if the number is started and '-' is occur then it is not valid we will break the loop.
//Similarly is the case for '+' sign same situations.
//hence at last the current element in string is a number then i added it to the answer. Here i declared ans as double because if the int is overflow then some more cases will added and it become more complex to me so i simply store it in double and check a last if it is out of range of int then return the valid answer i.e. 2147483647 in case it is greater that that.
int myAtoi(string s) {
        int n=s.size();
        double ans=0;
        bool negative=false;
        bool isnumstr=false;
        for(int i=0;i<n;i++){
            if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || s[i]=='.'){
                break;
            }
            if(s[i]==' '){
                if(isnumstr){
                    break;
                }else{
                continue;}
            }
            if(s[i]=='-'){
                if(s[i+1]>='0' && s[i+1]<='9'){
                    if(isnumstr) break;
                    else negative=true;
                }
                if(s[i+1]<'0' || s[i+1]>'9'){
                    break;
                }
            }
            if(s[i]=='+'){
                if(isnumstr){
                    break;
                }else if((s[i+1]<'0' || s[i+1]>'9')){
                 break;}
                 }
            if((s[i]>='0' && s[i]<='9')){
                isnumstr=true;
                ans=ans*10+((int)s[i]-48);
                // cout<<ans;
            }
        }
        if(negative){
            ans=-ans;
        }
        if(ans>=2147483648) return 2147483647;
        else if(ans<=-2147483649) return -2147483648;
        else return ans;
    }

int main(){
    string s1="42-05";
    string s2="3.14159";
    string s3="+-12";
    string s4="-13+8";
    string s5="     +004500";
    cout<<myAtoi(s1)<<endl<<myAtoi(s2)<<endl<<myAtoi(s3)<<endl<<myAtoi(s4)<<endl<<myAtoi(s5)<<endl;
    return 0;
}