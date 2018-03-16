/*
347. Top K Frequent Elements

Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& n, int k) {
        vector<int> a;
        int s=n.size();
        unordered_map<int,int> mp;
        unordered_map<int,int> ::iterator it;
        for(int i=0;i<s;i++){
                mp[n[i]]++;    
        }
        while(k--){
            int m = INT_MIN;
            int t;
            for(it=mp.begin();it!=mp.end();it++){
                if(m<it->second){
                    m=it->second;
                    t=it->first;
                }
            }
            a.push_back(t);
            mp.erase(t);
        }
        return a;
    }
};