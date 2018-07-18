/*
424. Longest Repeating Character Replacement
Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.

Note:
Both the string's length and k will not exceed 104.

Example 1:

Input:
s = "ABAB", k = 2

Output:
4

Explanation:
Replace the two 'A's with two 'B's or vice versa.
Example 2:

Input:
s = "AABABBA", k = 1

Output:
4

Explanation:
Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=INT_MIN;
        int i=0;
        int j=0;
        int arr[26]={};
        for(int t=0;t<26;t++){
            arr[t]=0;
        }
        while(j<s.length()){
            arr[s[j++]-'A']++;
            if(j-i-*max_element(arr,arr+26)>k){
                arr[s[i]-'A']--;
                i++;
            }else{
                ans=max(ans,(j-i));
            }
        }
        return ans==INT_MIN ? 0 : ans;
    }
};