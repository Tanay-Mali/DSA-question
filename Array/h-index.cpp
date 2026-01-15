#include<iostream>
#include<vector>
using namespace std;

//Q274. H-Index
// Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.
// According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.

//Date: 15-01-2026 Time:-4:00pm
//Solved: Today in morning i just found this question on leetcode and realize that it is easy to solve. The first approach came to my mind is the approach i saw on in the video of book allocation question solved by Shradha didi. I directly try to think with binary search on the search range but then realize that it may give wrong answer in some cases so i just do linear search on the search range then check whether each index is valid by the function checkindex()
//Solution was accpeted with Time complexity O(N*M) and runtime 4ms, I will try to solve it with the binary search on the search range

//Solution:
//This solution is may be diffucult to someone so i will suggest to watch the video of book allocation on Apna College YouTube channel
//Basically I think on the defination of H-index i.e. h paper has atleast h citation. Means that H-index is depend on no.of paper and no.of citation on papers,H-index can't be greater than no.of paper publish by researcher and also can't be greater that maximum no.of citation on his any research paper
//So i stored both on them in variable n and m respectively(See in function hIndex). Use a loop to find maximum citation on his papers.
//After that i decide which may be the end point of search range, like if no.of papers(n) is less than maximum citation(m) then h-index can't be greater than n and vice versa is also true
//Hence we get the search range from 0-(end); Since H-index is highest valid number in search range I run the loop in reverse direction as you can see the hIndex function, and for checking the each number present in that range is valid h-index or not i compare it with every paper's citation in function checkindex and increase count from zero, after the loop end if count >= index means no.of paper which has citation greater than or equal to parameter index is greater than or equal to that index then it is valid return that index in ans


bool checkindex(int index,vector<int> &citations){
    int count=0;
    for(int i=0;i<citations.size();i++){
        if(citations[i]>=index){
            count++;
        }
    }
    if(count>=index){
        return true;
    }
    return false;
}

int hIndex(vector<int>& citations) {
    int n=citations.size();
    int m=0;
    int end;
    int ans;
    for(int i=0;i<n;i++){
        m=max(m,citations[i]);
    }
    end=(m>n)?n:m;
    for(int i=end;i>=0;i--){
        if(checkindex(i,citations)){
            ans=i;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> citations1={3,0,6,1,5};
    vector<int> citations2={1,3,1};

    cout<<hIndex(citations2)<<"  "<<hIndex(citations2);
    return 0;
}
