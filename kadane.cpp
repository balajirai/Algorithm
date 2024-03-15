// Kadane's Algorithm 
// Max subarray sum in O(n)

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int arr[], int n){
    int mx_sum = INT_MIN;
    int curr_sum = 0;
    for(int i=0; i<n; i++){
        curr_sum += arr[i];
        mx_sum = max(mx_sum, curr_sum);
        if(curr_sum < 0){
            curr_sum = 0;
        }
    }
    return mx_sum;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<maxSubarraySum(arr,n)<<endl;

return 0;
}


/*
-2 -3 4 -1 -2 1 5 -3
*/