#include <iostream>
#include <vector>
using namespace std;
//GFG 1st question
int print2largest(vector<int>& arr) {
    int first = -1, second = -1;

    for (int num : arr) {
        if (num > first) {
            second = first;
            first = num;
        } else if (num < first && num > second) {
            second = num;
        }
    }

    return second;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << print2largest(arr) << endl;  // Output: 34
    return 0;
}
