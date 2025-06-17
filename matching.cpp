#include<bits/stdc++.h>
using namespace std;

#define mode 1000000007
int dp[22][1<<22];

int f(int i, int mask, int n, vector<vector<int>>& c) {
    if(i == n+1) {
        return (mask == 0) ? 1 : 0;
    }
    if(dp[i][mask] != -1) return dp[i][mask];

    int ans = 0;
    for(int w = 1; w <= n; w++) {
        bool available = ((1 << (w-1)) & mask) != 0;
        if(available && c[i][w]) {
            ans = (ans + f(i+1, mask ^ (1 << (w-1)), n, c)) % mode;
        }
    }
    return dp[i][mask] = ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> c(n+1, vector<int>(n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }
    memset(dp, -1, sizeof dp);
    cout << f(1, (1 << n) - 1, n, c) << endl;
    return 0;
}
