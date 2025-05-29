#include <iostream>
#include <vector>
using namespace std;
//GFG 2nd question
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;

        while (left < right) {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

int main() {
    Solution sol;

    // ✅ Ensure the vector is properly initialized
    vector<int> arr = {1, 4, 3, 2, 6, 5};
    
    // ✅ Ensure function call is valid
    sol.reverseArray(arr);

    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
