#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(!intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        
        int i = 0, j = 0;
        for(i = 0; i < intervals.size(); ++i){
            if(intervals[i][0] >= newInterval[0]){
                break;
            }
        }
        --i;
        for(j = i; j < intervals.size(); ++j){
            if(intervals[j][1] > newInterval[1]){
                if(j)--j;
                break;
            }
        }
        if(i < intervals.size() && intervals[i][0] < newInterval[0]){
            newInterval[0] = intervals[i][0];
        }
        if(j < intervals.size() - 1 && intervals[j + 1][0] == newInterval[1]) ++j;

        if(j < intervals.size() && intervals[j][1] > newInterval[1]){
            newInterval[1] = intervals[j][1];
        }
        intervals.erase(intervals.begin() + i, intervals.begin() + j + 1);
        intervals.insert(intervals.begin() + i, newInterval);

        return intervals;
    }
int main(){
    vector<vector<int>> v ={{1,5}};
    vector<int> w = {2,7};
    insert(v, w);
    return 0;
}