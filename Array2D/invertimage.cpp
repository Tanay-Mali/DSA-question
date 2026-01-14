#include<iostream>
#include<vector>
using namespace std;

//Q832. Flipping an Image
// Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
// To flip an image horizontally means that each row of the image is reversed.
// For example, flipping [1,1,0] horizontally results in [0,1,1].
// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
// For example, inverting [0,1,1] results in [1,0,0].

//Date:-14-01-2026 Time:8:28am;
//Solution: Accepted with runtime 0ms and Time Complexity O(N*M);
//As per the instruction give in the question i just follow that this is brute force approach may be I will try to optimize this solution 
//First I flip it horizontally by swapping the first and last number of each row 
//Then invert it by accessing each element and change it by 0 or 1


//Brute Force Approach;
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int outer=image.size();
        int inner=image[0].size();
        vector<vector<int>> invertedimg=image;
        //Horizontal flip
        for(int i=0;i<outer;i++){
            int str=0;
            int end=inner-1;
            while(str<end){
                swap(invertedimg[i][str],invertedimg[i][end]);
                str++;
                end--;
            }
        }
        //Invert
        for(int i=0;i<outer;i++){
            for(int j=0;j<inner;j++){
                (invertedimg[i][j]==0)?invertedimg[i][j]=1:invertedimg[i][j]=0;
            }
        }

        return invertedimg;
    }

 //Date:-14-01-2026 Time:-9:00am;   
//Optimize Brute force approach;
//Approach:We can just invert them while fliping the image or swapping the row
//either invert them then flip horizontally or flip horizontally then invert them;
//We just remove one extra loop and utilize the loop which was use horizontal flip
//But still Time complexity is O(N*M).
vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int outer=image.size();
        int inner=image[0].size();
        vector<vector<int>> invertedimg=image;

        for(int i=0;i<outer;i++){
            int str=0;
            int end=inner-1;
            while(str<=end){//Horizontal Flip and simultaneously Invert
                swap(invertedimg[i][str],invertedimg[i][end]);
                if(str==end){
                    (invertedimg[i][str]==0)?invertedimg[i][str]=1:invertedimg[i][str]=0;
                }
                else{
                    (invertedimg[i][str]==0)?invertedimg[i][str]=1:invertedimg[i][str]=0;
                    (invertedimg[i][end]==0)?invertedimg[i][end]=1:invertedimg[i][end]=0;
                }
                str++;
                end--;
            }
        }

        return invertedimg;
    }

int main(){
    vector<vector<int>> image={{1,1,0},{1,0,1},{0,0,0}};
    cout<<"Original Image"<<endl;
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[0].size();j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    vector<vector<int>> ans=flipAndInvertImage(image);
    cout<<"Inverted image"<<endl;
    for(int i=0;i<image.size();i++){
        for(int j=0;j<image[0].size();j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
}