#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int N = 10000;

int n, m;
int s, t;
int p[N];
int f[N][N];
int c[N][N];
vector<int> A[N];
int ans;

void input() {
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            c[i][j] = 0;
        }
    }
    for (int k = 1; k <= m; ++k) {
        int u, v, t;
        cin >> u >> v >> t;
        c[u][v] = t;
        A[u].push_back(v);
    }
}

bool findBFS() {
    queue<int> q;
    for (int v = 1; v <= n; ++v) {
        p[v] = 0;
    }
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int j = 0; j < A[u].size(); ++j) {
            int v = A[u][j];
            if (p[v] == 0) {
                bool ok = false;
                if (c[u][v] > 0) {
                    if (f[u][v] < c[u][v]) ok = true;
                } else {
                    if (f[v][u] > 0) ok = true;
                }
                if (ok) {
                    p[v] = u;
                    q.push(v);
                    if (v == t) return true;
                }
            }
        }
    }
    return false;
}

int argumentFlow() {
    int delta = 100000;
    int u = t;
    while (p[u] > 0) {
        int pu = p[u];
        if (c[pu][u] > 0) {
            delta = min(delta, c[pu][u] - f[pu][u]);
        } else {
            delta = min(delta, f[u][pu]);
        }
        u = pu;
    }
    u = t;
    while (p[u] > 0) {
        int pu = p[u];
        if (c[pu][u] > 0) {
            f[pu][u] = delta;
        } else {
            f[u][pu] = delta;
        }
        u = pu;
    }
    return delta;
}

void maxFlow() {
    for (int u = 1; u <= n; ++u) {
        for (int i = 0; i < A[u].size(); ++i) {
            int v = A[u][i];
            f[u][v] = 0;
        }
    }
    while (true) {
        bool ok = findBFS();
        if (!ok) break;
        int delta = argumentFlow();
        ans += delta;
    }
}

int main() {
    input();
    maxFlow();
    cout << ans;
}