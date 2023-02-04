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

int n;

int getNum(string st) {
    int num = 0;
    for (int i = 7; i < st.length(); i++) {
        num = num * 10 + (st[i] - '0');
    }
    return num;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    string st;
    while (true) {
        getline(cin, st);
        if (st == "") continue;
        if (st[0] == 'i') {
            int num = getNum(st);
            a.push_back(num);
        } else if (st[0] == 'd') {
            int max = 0;
            int index = 0;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] >= max) {
                    max = a[i];
                    index = i;
                }
            }
            a.erase(a.begin() + index);
            cout << max << "\n";
        } else if (st == "*")
            break;
    }

    return 0;
}