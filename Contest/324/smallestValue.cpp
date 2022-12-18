#include <math.h>

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

int checkPrime(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int smallerValue(int n) {
    int sum = 0;
    int i = 2;
    while (n > 1) {
        if (n % i == 0) {
            if (checkPrime(i)) {
                sum += i;
                n /= i;
            }
        } else {
            i++;
        }
    }
    return sum;
}

int smallestValue(int n) {
    n = smallerValue(n);
    if (n == smallerValue(n)) return n;
    while (!checkPrime(n)) {
        n = smallerValue(n);
    }
    return n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 4;
    cout << smallestValue(n);
    return 0;
}