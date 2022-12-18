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

int compareSet(set<char> a, set<char> b) {
    if (a.size() != b.size()) return 0;
    for (auto x : a) {
        if (b.find(x) == b.end()) return 0;
    }
    return 1;
}

int similarPairs(vector<string>& words) {
    int n = words.size();
    map<int, set<char>> dic;
    for (int i = 0; i < n; ++i) {
        string s = words[i];
        for (int j = 0; j < s.size(); ++j) {
            dic[i].insert(s[j]);
        }
    }
    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            ans += compareSet(dic[i], dic[j]);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<string> words = {"aba", "aabb", "abcd", "bac", "aabc"};
    cout << similarPairs(words);

    return 0;
}