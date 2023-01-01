/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    const int BASE_DIGITS_LENGTH = 9;
    const int BASE_NUMBER = 1000000000;

    void str_to_int(string s, vector<int>& n){
        if(s.length() <= BASE_DIGITS_LENGTH) {
            n.push_back(stoi(s));
            return;
        }
        n.push_back(stoi(s.substr(s.length() - BASE_DIGITS_LENGTH, BASE_DIGITS_LENGTH)));
        s.erase(s.end() - BASE_DIGITS_LENGTH, s.end());
        str_to_int(s, n);
    }

    string int_to_str(vector<int> n){
        if(!n.size()) return "0";
        string s, quad;
        int t = 0;
        for(int i = n.size() - 1; i >= 0; --i){
            quad = to_string(n[i]);
            if(t){  
                while(quad.length() < BASE_DIGITS_LENGTH){
                    quad = "0" + quad;
                }
            }
            s += quad;
            t = 1;
        }
        return s;
    }

    vector<int> add(vector<int> a, vector<int> b){
        if(!a.size() && !b.size()) return {0};
        if(!a.size()) return b;
        if(!b.size()) return a;

        vector<int> res;
        int64_t n = 0;
        for(int i = 0; i < a.size() || i < b.size() || n; ++i){
            n += (i < a.size() ? a[i] : 0) + (i < b.size() ? b[i] : 0);
            res.push_back(n % BASE_NUMBER);
            n /= BASE_NUMBER;
        }
        return res;

    }

    vector<int> multiply(vector<int> a, vector<int> b){
        if(!a.size() || !b.size()) return {0};

        vector<int> res;
        if(b.size() == 1){
            int64_t n = 0;
            for(int i = 0; i < a.size() || n; ++i){
                n += (int64_t)(i < a.size() ? a[i] : 0) * b[0];
                res.push_back(n % BASE_NUMBER);
                n /= BASE_NUMBER;
            }
            return res;
        } 
        for(int i = 0; i < b.size(); ++i){
            res = add(res, multiply(a, {b[i]}));
            a = multiply(a, {BASE_NUMBER});
        }
        return res;
    }

    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";

        vector<int> a;
        vector<int> b;
        str_to_int(num1, a);
        str_to_int(num2, b);
        
        return int_to_str(multiply(a, b));
    }
};
// @lc code=end

