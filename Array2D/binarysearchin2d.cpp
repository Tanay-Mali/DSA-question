#include<iostream>
#include<vector>
using namespace std;

//Q74. Search a 2D Matrix
// You are given an m x n integer matrix matrix with the following two properties: Each row is sorted in non-decreasing order. The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.
// You must write a solution in O(log(m * n)) time complexity.

//Date:-22-01-2026 Time 11:30am
//Solved:Accepted with time comlexiety O(lon(n)+log(m)) and run time 0ms and space complexiety O(1);

//Solution;
//Solution is easy than i think because i already know about the binary search. Here I think, at first we have to find the inner martix in which our target may exist so i use binary search technique for it using the mid. If the first element of array present at mid index of main array is greater than the target then outer end(oend) will be mid-1. once we found the inner array where our target may exist i again apply binary search on that array by taking istr,iend and imid as our staring ending and mid value. it may be bit confusing but once you dry run it you will understand what logic I apply.    

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int in=matrix[0].size();
        int ostr=0;
        int oend=n-1;
        int istr=0;
        int iend=in-1;

        while(ostr<=oend){
            int mid=ostr+(oend-ostr)/2;
            if(target<matrix[mid][istr]){
                oend=mid-1;
                continue;
            }else if(target>matrix[mid][iend]){
                ostr=mid+1;
                continue;
            }
            else{
                while(istr<=iend){
                    int imid=istr+(iend-istr/2);
                    if(matrix[mid][imid]==target){
                        return true;
                    }
                    (matrix[mid][imid]<target)?istr=imid+1:iend=imid-1;
                }
            }
        }
        return false;
    }

int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target =3;
    cout<<searchMatrix(matrix,target);
    return 0;
}