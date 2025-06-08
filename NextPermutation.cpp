#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;

        // Step 1: Find first decreasing element from end
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find first element from end that is greater than arr[i]
            int j = n - 1;
            while (j >= 0 && arr[j] <= arr[i]) {
                j--;
            }

            // Step 3: Swap arr[i] and arr[j]
            swap(arr[i], arr[j]);
        }

        // Step 4: Reverse the subarray from i+1 to end
        reverse(arr.begin() + i + 1, arr.end());
    }
};

int main() {
    Solution sol;
    vector<int> arr = {2, 4, 1, 7, 5, 0};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    sol.nextPermutation(arr);

    cout << "Next Permutation: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    return 0;
}
