#include<iostream>
#include<string>
using namespace std;

//Q771. Jewels and Stones
// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.
// Letters are case sensitive, so "a" is considered a different type of stone from "A".

//Date:18-01-2026 time:-9:54am
//Solved with Time Complexity O(N*M) and run time 0ms space complexity O(1);

//Solution:
//This is easy question i just compare each stone with jewel whether it is jewel or not like we actually do in real life; And comparing each stone with jewwl makes the time comlexity O(N*M)(N=no.of stones, M=no.of jewels);


int numJewelsInStones(string jewels, string stones) {
        int count=0;
        for(int i=0;i<stones.size();i++){
            for(int j=0;j<jewels.size();j++){
                if(stones[i]==jewels[j]){
                    count++;
                    break;      //Use this to avoid comparing with remaining jewels and continue with remaining stones;
                }
            }
        }
        return count;
    }

int main(){
    string jewel="aA";
    string stones="aAAbbbb"; 
    int ans=numJewelsInStones(jewel,stones);   
    cout<<ans<<endl;    
    return 0;
}