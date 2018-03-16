/*
318. Maximum Product of Word Lengths

##VERY IMPORTANT##

Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        if(words.size() < 2)
            return ans;
        int n = words.size();
        vector<int> val(n);
        for(int i = 0; i < n; ++ i){
            for(int j = 0; j < words[i].size();j++){
                int k = words[i][j] - 'a';
                val[i] |= (1<<k);
            }
            cout<<val[i]<<endl;
        }
        for(int i = 0; i < n - 1; ++ i){
            for(int j = i + 1; j < n; ++ j){
                if((val[i]&val[j]) == 0){
                    ans = max(ans, (int)((int)words[i].size()*(int)words[j].size()));
                }
            }
        }
        return ans;
    }
};