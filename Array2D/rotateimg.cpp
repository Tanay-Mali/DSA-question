#include<iostream>
#include<vector>
using namespace std;


//Q48. Rotate Image
// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
//Solved with Time Complexity O(N^2) runtime 0ms and Space Complexity O(N) Yes! it says to change it in-place means solve in space O(1) but i can't think about how can i just manipulate the same 2d array and rotate while i figure out with space of O(N) i can do it 

//Date:19-01-2026 Time:6:30pm
//Solution:
//This is may be brute Force approach because This is the first approach that came to my mind. 
//First I also try to find the solution by observing the actual 2d matrix image given in question but when i carefully observe the 2d array which was given as example then i understand that after rotation the first row is made up of first element of each row from backside 
//If you see the example given if we rotate that array the first row will be {15,13,2,5} now may be you understand what i observer in this and this same pattern followed for other rows also for 2nd row it will be {14,3,4,1} 
//Now I don't know how can I manipulate or change that in-place without introducing new vector So i just try it and got so many errors like writing outer instead of j in the loop (you will understander once you see the solution) after all The solution is accepted but i will try to learn the method to change that 3d array in-place. 


void rotate(vector<vector<int>>& matrix) {
    int outer=matrix.size();
    int inner=matrix[0].size();
    vector<vector<int>> ans=matrix;
    int str=0;
    
    for(int i=0;i<inner;i++){
        int str2=0;
        for(int j=outer-1;j>=0;j--){
            ans[str][str2]=matrix[j][i];
            str2++;
        }
        str++;
    }
    matrix=ans;
}

int main(){
    vector<vector<int>> img={{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(img);
    for(int i=0;i<img.size();i++){
        for(int j=0;j<img[0].size();j++){
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}