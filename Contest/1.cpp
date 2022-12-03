#include <iostream>

using namespace std;

#define N 100001
int a[N];
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int d = 0;
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ++d;
        }
    }
    cout << d;

    return 0;
}