#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define FOR(i, x) for (int(i) = 0; (i) < (x); (i)++)

struct bank {
    std::string from;
    std::string to;
    std::string amount;
    std::string time;
    std::string code;
};

std::vector<bank> banks;
map<string, int> number;

bank extractDataFromLine(std::string line) {
    bank c;
    const char* str = line.c_str();
    char from[20], to[20], amount[20], time[20], code[20];
    sscanf(str, "%s %s %s %s %s", from, to, amount, time, code);
    c.from = from;
    c.to = to;
    c.amount = amount;
    c.time = time;
    c.code = code;
    return c;
}

ll getTotal() {
    ll total = 0;
    for (int i = 0; i < banks.size(); i++) {
        total += stoll(banks[i].amount);
    }
    return total;
}

string listAccount() {
    set<string> s;
    for (int i = 0; i < banks.size(); ++i) {
        s.insert(banks[i].from);
        s.insert(banks[i].to);
    }
    // sort set of string s with alphabet order
    string st;
    for (auto i : s) {
        st += i + " ";
    }
    return st;
}

void getTotalMoney(string source) {
    ll total = 0;
    for (int i = 0; i < banks.size(); ++i) {
        if (banks[i].from == source) {
            total += stoll(banks[i].amount);
        }
    }
    cout << total << endl;
}
bool ch = false;
void solve(string source, int value) {
    string ori = source;
    while (value) {
        for (int i = 0; i < banks.size(); ++i) {
            if (banks[i].from == source) {
                --value;
                source = banks[i].to;
                break;
            }
        }
        break;
    }
    if (value == 0 && source == ori) {
        ch = true;
    } else {
        ch = false;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    bool endInput = false;
    ll total = 0;
    string s;
    while (getline(cin, line)) {
        if (line == "#") {
            if (!endInput) {
                total = getTotal();
                s = listAccount();
                endInput = true;
            }
            continue;
        }
        if (line[0] != '?' && line[0] != '#') {
            bank c = extractDataFromLine(line);
            banks.pb(c);
        }
        if (line == "?number_transactions") {
            cout << banks.size() << endl;
        }
        if (line == "?total_money_transaction") {
            cout << total << endl;
        }
        if (line == "?list_sorted_accounts") {
            cout << s << endl;
        }
        if (line.substr(0, line.find(" ")) == "?total_money_transaction_from") {
            string source = line.substr(line.find(" ") + 1);
            getTotalMoney(source);
        }
        if (line.substr(0, line.find(" ")) == "?inspect_cycle") {
            string st = line.substr(line.find(" ") + 1);
            string source = st.substr(0, st.find(" "));
            string value = st.substr(st.find(" ") + 1);
            solve(source, stoll(value));
            if (ch)
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
    }

    return 0;
}