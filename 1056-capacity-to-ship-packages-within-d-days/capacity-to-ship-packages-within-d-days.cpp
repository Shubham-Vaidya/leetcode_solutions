#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = *max_element(weights.begin(), weights.end());
        int sum = 0;
        int res = 0;
        for(auto it : weights) sum += it;
        int high = sum;
        while(low <= high){
            int mid = low + (high-low)/2;
            int count = 1;
            int curr = 0;
            int i = 0;
            while(i < n){
                curr += weights[i];
                if(curr > mid){
                    curr = weights[i];
                    i++;
                    count++;
                }
                else{
                    i++;
                }
            }
            if(count > days) low = mid+1;
            else{
                res = mid;
                high = mid-1;
            } 
        }
        return res;




























































    // int findDays(vector<int> &weights, int cap) {
    //     int days = 1; // First day
    //     int load = 0;
    //     for (int w : weights) {
    //         if (load + w > cap) {
    //             days++; 
    //             load = w; 
    //         } else {
    //             load += w; 
    //         }
    //     }
    //     return days;
    // }

    // int shipWithinDays(vector<int>& weights, int days) {
    //     // Using STL to get max and sum
    //     int maxWeight = *max_element(weights.begin(), weights.end());
    //     int sumWeight = accumulate(weights.begin(), weights.end(), 0);

    //     int low = maxWeight, high = sumWeight, ans = sumWeight;
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if (findDays(weights, mid) <= days) {
    //             ans = mid;
    //             high = mid - 1;
    //         } else {
    //             low = mid + 1;
    //         }
    //     }
    //     return ans;
    }
};
