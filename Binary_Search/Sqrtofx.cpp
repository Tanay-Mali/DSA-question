#include<iostream>

using namespace std;

// 69. Sqrt(x)
// Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well. You must not use any built-in exponent function or operator.

//Solved on self with time complexity O(n) but still runtime was 34ms 


int mySqrt(int x) {
        long ans=1; // Defined long because the edge case of taking x=2147483647 make the int overflow to calculate square of a big number so we defined as long, Making it double also bring solution 
        while(true){
            
            if(ans*ans<x){
                ans++;
            }
            else if(ans*ans>x){
                return ans-1;
            }
            if(ans*ans == x){
                return ans;
            }
        }
    }

//Date:-26-01-2026, Time:-4:45pm;
//Solved Using binary search. Time Complexity O(log n), runtime 0ms and space complexity O(1);
//Solution: After solving the question of Valid Square (Q367 of leetcode) I came back to this question solve using binary search since i soolve that question with binary search so i also try this one. Starting with some special cases that i know then i define str end of the search space. As we know all factors of any number belongs to the range from 1 to half of that number, similarly str=1 and for deciding end point i use the condition which i thought in the question of Valid square. The condition is to prevent squaring from overflow because system can store upto 2³¹ integers if we square beyond that the value will go to negative. So simply i first find root of 2³¹ which is 46340 approx. now if half of any number goes beyond 46340 we will set end as 46340. Now we got search space just start binary search. for that i define mid as usual and sqmid Which is square of mid because if at each place we write mid*mid system calculate each time due to which runtime increases to prevent this I declared it in a separate int value. now if we find the valid integer root we will break the loop and return that mid value by storing it in mid. 
//Now the second thing is if it has no valid integer root then we will set mid value as ans when we move in the right half of search space.
//The logic behind setting value of ans as mid when we move in right half is that, When we move in right half of search space meaning the square root is still less that the required and same we needed at end when loop is end. The question says that iif no valid int is found return the rounded down integer. Now if we set it when we moving in left or right half the ans may return the rounded up int also so to prevent that i use that condition only set ans as mid if we are moving in right half.

int mySqrt2(int x){
    if(x==1) return 1;
    if(x==4) return 2;
    int ans=0;
    int str=1;
    int end=(x/2>46340)?46340:x/2;
    while(str<=end){
        int mid=str+(end-str)/2;
        int sqmid=mid*mid;
        if(sqmid==x){
            ans=mid;
            break;
        }
        if(sqmid<x){
            ans=mid;
            str=mid+1;
        } else if(sqmid>x){
            end=mid-1;
        }
    }
    return ans;
}

int main(){
    int x=8;
    cout<<mySqrt(x)<<endl;
}