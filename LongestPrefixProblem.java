#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";
        if (v.empty()) return ans;

        sort(v.begin(), v.end());
        int n = v.size();
        string first = v[0], last = v[n - 1];

        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ans;
            }
            ans += first[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"flower", "flow", "flight"};
    string result = sol.longestCommonPrefix(words);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
