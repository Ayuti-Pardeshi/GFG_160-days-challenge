#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // Merge two sorted linked lists
    ListNode* mtl(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mtl(l1->next, l2);
            return l1;
        } else {
            l2->next = mtl(l1, l2->next);
            return l2;
        }
    }

    // Divide and conquer merge
    ListNode* dac(vector<ListNode*>& lists, int left, int right) {
        if (left == right) {
            return lists[left];
        }

        int mid = left + (right - left) / 2;
        ListNode* l1 = dac(lists, left, mid);
        ListNode* l2 = dac(lists, mid + 1, right);
        return mtl(l1, l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return dac(lists, 0, lists.size() - 1);
    }
};

// Helper: Print linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Helper: Create linked list from vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    // Example input: 3 sorted linked lists
    vector<ListNode*> lists;
    lists.push_back(createList({1, 4, 5}));
    lists.push_back(createList({1, 3, 4}));
    lists.push_back(createList({2, 6}));

    Solution sol;
    ListNode* merged = sol.mergeKLists(lists);

    cout << "Merged Linked List: ";
    printList(merged);

    return 0;
}
