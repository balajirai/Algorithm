/*

Maximum sum of subarray less than or equal to x
https://www.geeksforgeeks.org/problems/maximum-sum-of-subarray-less-than-or-equal-to-x4033/1

*/

class Solution {
  public:
    long long findMaxSubarraySum(vector<int>& arr, long long x) {
        // sliding window (variable size)
        int n = arr.size();
        long long ans = 0, sum = 0;
        
        int start = 0, end = 0;
        while(end < n){
            // add the element to window
            sum += arr[end];
            end++;

            // shrik the window if sum exceeds x
            while(sum > x){
                sum -= arr[start];
                start++;
            }
            
            if(sum > ans && sum <= x){
                ans = sum;
            }
        }
        return ans;
    }
};
