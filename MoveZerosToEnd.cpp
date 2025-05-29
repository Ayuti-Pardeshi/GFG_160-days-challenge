#include <iostream>
#include <vector>
using namespace std;
//GFG 3rd question
class Solution {
  public:
    void moveZerosToEnd(vector<int> &arr) {
        int n = arr.size();
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                arr[index++] = arr[i];
            }
        }

        while (index < n) {
            arr[index++] = 0;
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    sol.moveZerosToEnd(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    // Output: 1 2 4 3 5 0 0 0

    return 0;
}
