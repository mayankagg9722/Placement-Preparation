/*
399. Evaluate Division
Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
*/

class Solution {
public:
    unordered_map<string,unordered_map<string,double>> mp;
    double checkExist(string a,string b,unordered_set<string> &s){
        if(mp[a].find(b)!= mp[a].end()){
            return mp[a][b];
        }
        for(auto i : mp[a]){
            if(s.find(i.first)==s.end()){
                s.insert(i.first);
                double t = checkExist(i.first,b,s);
                if(t){
                   return i.second*t;    
                }
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int k=0;
        for(pair<string, string> p : equations){
            string a = p.first;
            string b = p.second;
            mp[a].insert(make_pair(b,values[k]));
            if(values[k]!=0){
                mp[b].insert(make_pair(a,1.0/values[k]));
            }
            k++;
        }
        vector<double> ans;
        for(pair<string, string> p : queries){
            string a = p.first;
            string b = p.second;
            unordered_set<string> s;
            double t = checkExist(a,b,s);
            if(t){
                ans.push_back(t);   
            }else{
                ans.push_back(-1.0);
            }
        }
        return ans;
    }
};