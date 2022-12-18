#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define FOR(i, x) for (int(i) = 0; (i) < (x); (i)++)

int n;

bool check(int vi, int vc, int vk, int vh, int vu, int vs, int vt) {
    // check each number have differrent values
    if (vi == vc || vi == vk || vi == vh || vi == vu || vi == vs || vi == vt || vc == vk ||
        vc == vh || vc == vu || vc == vs || vc == vt || vk == vh || vk == vu || vk == vs ||
        vk == vt || vh == vu || vh == vs || vh == vt || vu == vs || vu == vt || vs == vt) {
        return false;
    }
    return true;
}

void solve() {
    // ict - k62 + hust = n
    int d = 0;
    for (int vi = 1; vi <= 9; ++vi) {
        for (int vc = 1; vc <= 9; ++vc) {
            for (int vk = 1; vk <= 9; ++vk) {
                for (int vh = 1; vh <= 9; ++vh) {
                    for (int vu = 1; vu <= 9; ++vu) {
                        for (int vs = 1; vs <= 9; ++vs) {
                            for (int vt = 1; vt <= 9; ++vt) {
                                if (check(vi, vc, vk, vh, vu, vs, vt)) {
                                    if (vi * 100 + vc * 10 + vt - (vk * 100 + 62) + vh * 1000 +
                                            vu * 100 + vs * 10 + vt ==
                                        n) {
                                        ++d;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve();
    return 0;
}