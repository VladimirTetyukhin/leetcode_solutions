#include <iostream>
#include <vector>
#include <iterator>
#include <utility>
#include <algorithm>
#include <set>
using namespace std;
/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
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
            if(edges[i].second >= 0){                    //left borders
                if(edges[i].second > *(heights_set.begin())){
                    skyline.push_back({edges[i].first, edges[i].second});
                }
                heights_set.insert(edges[i].second);
            } else{    
                heights_set.erase(heights_set.find(abs(edges[i].second)));                                                        
                if(abs(edges[i].second) > *(heights_set.begin())){
                    skyline.push_back({edges[i].first, *(heights_set.begin())});
                }     
            }
        }

        return skyline;
    }
};

// @lc code=end

