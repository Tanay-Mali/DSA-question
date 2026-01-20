#include<iostream>
#include<vector>
using namespace std;

//Q11. Container With Most Water
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.

//Date:20-01-2026 Time:10:00pm;
//Solution:Accepted With Time Complexity O(N) and runtime 0ms and Spcae Complexity O(1);
//I only able to find the brute force approach that is just check for every possible pair but that will not accepted there because we will get TLE(Time limit exceed) So i watch the solution from the video and this is one of the video where I learn  the two pointer method and i applied this method in other questions also like Single elemet question and others also 
//Approach is easy; just track the height of bars from both side by by two pointers str and end. We want maximum area. Area depends on height and breadth so breadth will decrease is we closing two pointers(arrow) from both side the only thing affect is the height of bars. Between those two bars, The bar with less height than other one will decrease the area so we will just moved that pointer towards other in hope to find another bar with height more that the last one. We will continue to calculate to maximum area in each case and update it if new area is more than the last one.
//If you don't understand the solution in text i will prefer you to watch the actual video of solution on youtube channel Apna Collge;
 
int maxArea(vector<int>& height){
    int str=0;
    int end=height.size()-1;
    int maxwater=0;

    while(str<end){
        maxwater=max(maxwater,(end-str)*min(height[str],height[end]));
        (height[str]>height[end])?end--:str++;
    }
    return maxwater;
}

int main(){
    vector<int> height={1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);
    return 0;
}