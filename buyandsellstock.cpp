#include<iostream>
#include<vector>
using namespace std;


//Q121.Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//NOTE:
//solution logic is known 100% but remember about the case of maxprofit<0
//and the one you forgot is if condition in for loop (whether you add it or not the code works but still add it reason on next line)
//the reason is if price is less that bestbuy the it is waste to calculate maxprofit and all
// also remember do not add extra variable for calculating current profit just fill the formula in max() function as shown

int maxProfit(vector<int>& prices){
    int bestbuy=prices[0];
    int maxprofit=0;
    for(int i=0;i<prices.size();i++){
        if(prices[i]>bestbuy){
            maxprofit=max(maxprofit,prices[i]-bestbuy);
        }
        bestbuy=min(bestbuy,prices[i]);

    }
    if(maxprofit<0){
        return 0;
    }
    return maxprofit;

}

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);
    return 0;
}