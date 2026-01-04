#include<iostream>
#include<vector>
using namespace std;
//Logic pata hai par constraint dhyan me rakh
// binary form ko long mein le kyuki bade negative number ka negation nai hota
// ans ko bhi double me le ;
// baki edge cases bhi dhyan me rakh 1 aur -1 aur vo n=0 wale

double myPow(double x, int n){
    long binform=n;
    double ans=1;
    
    if(n<0){
            x=1/x;
            binform=-binform;
        }
    if(x == 1){
        return 1;
    }
    if(binform == 0){
        return 1;
    }
    if(x == -1){
        if(n%2==0){
            return 1;
        } else{
            return -1;
        }
    }
    if(x == 0){
        return 0;
    }

    while(binform>0){

        if(binform%2 == 1){
            ans*=x;
        }
        x*=x;
        binform/=2;
    }
    return ans;
}

int main(){
    double x=2.000;
    int n=10;
    cout << myPow(x,n);
    return 0;
}