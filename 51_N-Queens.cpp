#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void add_comb(vector<vector<string>> &combinations, vector<int> &q_arrangment, int n){
        vector<string> new_comb(n, string (n, '.'));
        for(int i = 0; i < n; ++i){
            new_comb[i][q_arrangment[i]] = 'Q';
        }
        combinations.push_back(new_comb);
    }

    void recursion_next_move(vector<vector<string>> &combinations, vector<int> &q_arrangment, int n, int q_count) {
        if(q_count == n){
            add_comb(combinations, q_arrangment, n);
            return;
        }
        int t;
        for(int i = 0; i < n; ++i){
            t = 1;
            for(int j = 0; j < q_count && t; ++j){
                if(q_arrangment[j] == i || 
                        i - q_arrangment[j] == q_count - j || 
                        q_arrangment[j] + j == q_count + i){
                    t = 0;
                    break;
                }
            }
            if(!t) continue;

            q_arrangment[q_count] = i;
            recursion_next_move(combinations, q_arrangment, n, q_count + 1); 
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<int> q_arrangment(n);
        vector<vector<string>> combinations;
        recursion_next_move(combinations, q_arrangment, n, 0);
        return combinations;
    }

    
    void print_solution(vector<vector<string>> &combinations) {
        for (int i = 0; i < combinations.size(); ++i){
            for (int j = 0; j < combinations[0].size(); ++j){
                cout << combinations[i][j] << '\n';
            }
        cout << "\n\n";
        }
    }
};


int main(){
    Solution solution;
    int n;
    cin >> n;
    vector<vector<string>> v(n);
    v = solution.solveNQueens(n);
    solution.print_solution(v);

    

    return 0;
}