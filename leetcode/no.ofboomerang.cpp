/*
447. Number of Boomerangs
Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
*/
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<long, int> group(points.size());
            for (int j = 0; j < points.size(); ++j) {
                if (j == i) continue;
                int dy = points[i].second - points[j].second;
                int dx = points[i].first - points[j].first;
                int key = dy * dy;
                key += dx * dx;
                ++group[key];
            }
            for (auto& p : group) {
                if (p.second > 1) {
                    res += p.second * (p.second - 1);
                }
            }

        }
        return res;
    }
};