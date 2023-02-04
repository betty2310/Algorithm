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

int n, k, m;
int a[100001];

void input() {
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int solve() {
    int ans = 0;
    ll sum = 0;
    for (int j = 0; j < k; j++) {
        sum += a[j];
    }
    if (sum == m) ans++;
    for (int i = 1; i < n - k + 1; i++) {
        sum -= a[i - 1];
        if (i + k - 1 < n) sum += a[i + k - 1];
        if (sum == m) ans++;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << solve();

    return 0;
}