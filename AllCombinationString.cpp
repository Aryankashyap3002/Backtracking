#include<bits/stdc++.h>

using namespace std;

void permutation(string str, string output) {

    if(str.size() == 0) {
        cout<<output<<endl;
        return;
    }

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        string firstSubString = str.substr(0, i);
        string secondSubString = str.substr(i+1);
        permutation(firstSubString + secondSubString, output + ch);
    }
}

int main() {
    string str = "abc";
    permutation(str, "");
}