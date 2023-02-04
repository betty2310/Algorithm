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

void solve(vector<int>& arr, int n, set<vector<int> >& ans, vector<int> v, int i) {
    if (i >= n) {
        ans.insert(v);
        return;
    }
    solve(arr, n, ans, v, i + 1);
    v.push_back(arr[i]);
    solve(arr, n, ans, v, i + 1);
}

vector<vector<int> > getAll(vector<int> arr, int n) {
    set<vector<int> > ans;
    sort(arr.begin(), arr.end());
    vector<int> v;
    solve(arr, n, ans, v, 0);
    vector<vector<int> > res;
    while (!ans.empty()) {
        res.push_back(*ans.begin());
        ans.erase(ans.begin());
    }
    return res;
}

int n, a, b;
int ans = 0;

int getAns(int N, vector<int>& A) {
    vector<vector<int> > result = getAll(A, N);
    for (int i = 0; i < result.size(); i++) {
        int sum = 0;
        for (int j = 0; j < result[i].size(); j++) {
            sum += result[i][j];
            if (sum > b) break;
        }
        if (sum >= a && sum <= b) {
            ++ans;
        }
    }
    return ans;
}

int main() {
    cin >> n >> a >> b;
    vector<int> A;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    cout << getAns(n, A);
    return 0;
}