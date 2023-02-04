#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define MAX 1e9
#define MIN -1e9
#define FOR(i, x) for (int(i) = 0; (i) < (x); (i)++)

using namespace std;

int solve(vector<int> a, int n) {
    int dp[n][2];
    if (n == 1) {
        return a[0];
    }

    dp[0][0] = 0;
    dp[0][1] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i][1] = dp[i - 1][0] + a[i];
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << solve(a, n) << endl;
    return 0;
}