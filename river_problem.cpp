#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

string h(string c, int n){
    if(!n) return "";
    if(n == 1){
        return c;
    }
    return to_string(n) + "*" + c;

}

string c(int a, int b){
    if(!a || !b) return "";
    return ",";

}


void move(int lc, int lb, int mc, int mp, int rc, int rb, bool state, ofstream &f){
    string a, b;
    if(state){
        a = "{";
        b = "}";
    } else {
        a = "   ";
        b = "";
    }
    f << a << h("C", lc) << c(lc, lb) << h("B", lb) << "|";
    f << h("C", mc) << h("P", mp) << "|";
    f << h("C", rc) << c(rc, rb) << h("B", rb) << b << endl;
}


int main(){
    ofstream f ("C:/Users/Vova/VS_code/leetcode/river_problem.txt", ofstream::out | ofstream::trunc);
    int n = 1000;
    cout << !!f;
    for(int i = 0; i < n; ++i){
        move(n - i, 0, 0, 0, i, 0, 1, f);
        move(n - 1 - i, 0, 1, 0, i, 0, 0, f);
        move(n - 1 - i, 0, 0, 0, i + 1, 0, 1, f);
        if (i != n - 1){
            move(n - 1 - i, 0, 0, 1, i, 1, 0, f);  
            move(n - 2 - i, 1, 0, 2, i, 1, 0, f);
            move(n - 2 - i, 1, 0, 1, i + 1, 0, 0, f);
        }
        f << endl;
    }
    f.close();
    //system("pause");  
    return 0;
}