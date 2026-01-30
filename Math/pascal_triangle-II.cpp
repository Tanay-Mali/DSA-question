#include<iostream>
#include<vector>
using namespace std;

//Q119. Pascal's Triangle II
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

//Date:-30-01-2026, Time:5:45pm
//Solved: Accepted with Time complexity O(), Runtime 0ms and space complexity O()
//This solution is also easy than i think. I just solve the pascal triangle question (leetcode Q118) so i know the way of thinking

//Solution: First i create a prerow vector to get the previous row because we can get the element of current row from the previous row then I handle the edge cases of row=0 and row=1 to avoid infinite looping or stack overflow in recurrusion. then get the previous row by giving the parameter as row-1 which means index of previous row
//And then it is easy just run loop on that previous row add its current and previous element and it will be our current element or current row i.e. current_row[i]=prerow[i-1]+prerow[i];  

vector<int> getRow(int rowIndex) {
        int row=rowIndex;
        vector<int> prerow;
        vector<int> current_row(row+1,0);

        if(row==0) return {1};
        if(row==1) {
            current_row={1,1};    
            return current_row;
        }
        prerow=getRow(row-1);

        for(int i=0;i<row+1;i++){
            if(i == 0 || i == row){
                current_row[i]=1;
            }else{
                current_row[i]=prerow[i-1]+prerow[i];
            }
            
        }

        return current_row;
    }