#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s = "codility";
    std::unordered_map<std::string, int> digrams;
    int ans = -1;
    for (int i = 0; i < s.size(); ++i) {
        std::string digram = s.substr(i, 2);
        if (digram.size() < 2) {
            continue;
        }
        if (digrams.count(digram) == 0) {
            digrams[digram] = i;
        }
        if (digrams.count(digram) == 1 && digrams[digram] != i) {
            int d = i - digrams[digram];  // distance between digrams
            ans = std::max(ans, d);
        }
    }
    std::cout << ans;
}