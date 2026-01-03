#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=0;i<n;i++){
            if(0<=digits[n-(i+1)] && digits[n-(i+1)]<=8){
                digits[n-(i+1)]++;
                break;
            } else if(digits[n-(i+1)] == 9){
                digits[n-(i+1)]=0;
            }
        }
        if(digits[0]==0){
            digits.insert(digits.begin(),1);
            digits[1]=0;
        }

        return digits;
}

int main(){
    vector<int> digits={4,3,2,1};
    plusOne(digits);
    for(int i=0;i<digits.size();i++){
        cout << digits[i] << " ";
    }
}