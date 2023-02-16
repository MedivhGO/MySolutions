class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        if (!head) {
            return ans;
        }
        recur(head, ans);
        return ans;
    }

    void recur(ListNode* cur, vector<int>& res) {
        if (cur->next == nullptr) {
            res.push_back(cur->val);
            return;
        }
        recur(cur->next, res);
        res.push_back(cur->val);
    }
};

// 