#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int sgn(int n){
        return (0 < n) - (n < 0);
    }

    int positive_to_1_else_0(int n){
        return 2 * (n > 0) - 1;
    }

    int max(int a, int b){
        return a > b ? a : b;
    }

    int min(int a, int b){
        return a < b ? a : b;
    }

    int count_dip(vector<int> &ratings, int a, int b){

    }

    int candy(vector<int> &ratings){
        vector<int> dif_ratings(ratings.size() - 1);
        int rel_first_rating = 0;
        int bottom_rating = 0;
        int index_bottom_rating = 0;
        int count = 1;
        int t = 0;
        int plato = 0;

        // for (int i = 0; i < ratings.size() - 1; ++i){
        //     dif_ratings[i] = sgn(ratings[i] - ratings[i + 1]);
        // }

        for (int i = index_bottom_rating; i < dif_ratings.size(); ++i){
            t += dif_ratings[i];
            count += t;
        }


        // for (int i = 0; i < dif_ratings.size(); ++i){
        //     t += dif_ratings[i];
        //     if(t < bottom_rating){
        //         bottom_rating = t;
        //         index_bottom_rating = i - 1; 
        //     }
        // }


        // cout << index_bottom_rating << endl;
        // for (int i = index_bottom_rating; i < dif_ratings.size(); ++i){
        //     t += dif_ratings[i];
        //     count += t;
        // }

        // t = 0;
        // for (int i = index_min_rating; i > 0; --i){
        //     t += positive_to_1_else_0(ratings[i - 1] - ratings[i]);cout << t << endl;
        //     count += t;
        // }
        return count;
    }
};

int main()
{
    Solution solution;

    int n;
    cin >> n;
    vector<int> ratings(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ratings[i];
    }
    cout << solution.candy(ratings);

    return 0;
}