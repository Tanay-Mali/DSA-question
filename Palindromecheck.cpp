#include<iostream>

bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int digit;
        int original_num=x;
        int reverse=0;
        if(x<=2147483647 && x>=1000000000 && x%10>2){
            return false;
        }
        while(x>0){
            digit=x%10;
            reverse=reverse*10+digit;
            x/=10;
        }
        return (reverse == original_num)?true:false;
    }

int main(){
    int x=12345678;
    int y=1234554321;
    cout<<isPalindrome(x)<<endl;
    cout<<isPalindrome(y)<<endl;
    return 0;
}