#include <bits/stdc++.h>
using namespace std;

void permutation(string &str, int i) {
    if(i == str.size() - 1) {
        cout << str << endl;
        return;
    }

    unordered_set<int> s; // for countering repeated character
    for(int idx = i; idx < str.size(); idx++) {
        if(s.count(str[idx])) continue;
        s.insert(str[idx]);
        swap(str[idx], str[i]);
        permutation(str, i + 1);
        swap(str[idx], str[i]); // backtrack
    }
}

int main() {
    string str = "abc";
    permutation(str, 0);
    return 0;
}
