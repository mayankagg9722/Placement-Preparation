/*
217. Contains Duplicate

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& n) {
        unordered_map<int,bool> m;
        for(int i=0;i<n.size();i++){
            if(m[n[i]]){
                return true;
            }
            m[n[i]]=true;
        }
        return false;
    }
};