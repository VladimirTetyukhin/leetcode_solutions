/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        vector<vector<int>> skyline;
        multiset<int, greater<int>> heights_set;
        vector<pair<int, int>> edges;

        for(int i = 0; i < buildings.size(); ++i){
            edges.push_back(make_pair(buildings[i][0], buildings[i][2]));
            edges.push_back(make_pair(buildings[i][1], -buildings[i][2]));
        }

        sort(edges.begin(), edges.end(), 
            [](const pair<int, int> &a, const pair<int, int> &b) {return a.first < b.first || (a.first == b.first && a.second > b.second);});

        for(int i = 0; i < edges.size(); ++i){
            if(edges[i].second >= 0){      
                heights_set.insert(edges[i].second);  //left borders
            } else {
                heights_set.erase(heights_set.find(abs(edges[i].second))); //right borders
            }

            if(abs(edges[i].second) != *heights_set.begin()){
                skyline.push_back({edges[i].first, *heights_set.begin()});
            }
        }
    }
};
// @lc code=end

