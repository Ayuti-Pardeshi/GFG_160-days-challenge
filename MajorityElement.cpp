#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
//class in c++
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        unordered_map<int, int> freq;
        vector<int> result;
        int n = arr.size();

        // Count frequency of each element
        for (int num : arr) {
            freq[num]++;
        }

        // Check which elements appear more than n/3 times
        for (auto it : freq) {
            if (it.second > n / 3) {
                result.push_back(it.first);
            }
        }

        sort(result.begin(), result.end());  // sort for increasing order
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 1, 5, 5, 5, 5, 6, 6, 6, 6, 6};

    vector<int> res = sol.majorityElement(arr);
    for (int num : res) cout << num << " ";
    cout << endl;

    return 0;
}
