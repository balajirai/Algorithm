/*  

Longest substring with distinct characters
https://www.geeksforgeeks.org/problems/longest-distinct-characters-in-string5848/1

*/

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // sliding window (variable size)
        int n = s.size();
        int ans = 0;
        
        int start = 0, end = 0;
        vector<int>freq(26, 0);
        
        while(end < n){
            // add curr char to window
            freq[s[end]-'a']++;
            
            // shrik the window
            while(freq[s[end]-'a']>1){
                freq[s[start]-'a']--;
                start++;
            }
            
            ans = max(ans, end-start+1);
            
            end++;
        }
        return ans;
    }
};
