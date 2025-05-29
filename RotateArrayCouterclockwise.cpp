#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        if (n == 0) return;

        d = d % n;  // handle d > n
        if (d == 0) return;

        // Step 1: Reverse first d elements
        reverse(arr, 0, d - 1);

        // Step 2: Reverse remaining n - d elements
        reverse(arr, d, n - 1);

        // Step 3: Reverse the whole array
        reverse(arr, 0, n - 1);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    cout << "Original Array: ";
    for (int num : arr) { //can use normal for loop
        cout << num << " ";
    }
    cout << endl;

    sol.rotateArr(arr, d);

    cout << "Array after rotating left by " << d << " positions: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
