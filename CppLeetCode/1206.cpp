class Skiplist {
#define MAX_LEVEL 8
public:
    struct SkipNode {
        int value_;
        std::vector<std::shared_ptr<SkipNode>> next_;

        SkipNode(int val) : value_(val) {
            next_.resize(MAX_LEVEL, nullptr);
        }
    };
public:
    Skiplist() {
        root_ = make_shared<SkipNode>(-1);
    }
    
    bool search(int target) {
        vector<shared_ptr<SkipNode>> pre(MAX_LEVEL);
        pre = find_node(target);
        auto p = pre[0]->next_[0];
        return p && p->value_ == target;
    }
    
    void add(int num) {
        vector<shared_ptr<SkipNode>> pre(MAX_LEVEL);
        pre = find_node(num);

        auto new_node = make_shared<SkipNode>(num);

        // 从上往下插入新节点
        for (int i = 0; i < MAX_LEVEL; ++i) {
            auto nt = pre[i]->next_[i];
            new_node->next_[i] = nt;
            pre[i]->next_[i] = new_node;
            if (rand() % 2) {
                break;
            }
        }
    }
    
    bool erase(int num) {
        vector<shared_ptr<SkipNode>> pre(MAX_LEVEL);
        pre = find_node(num);

        auto p = pre[0]->next_[0];
        if (!p || p->value_ != num) {
            return false;
        }

        for (int i = 0; i < MAX_LEVEL && pre[i]->next_[i] == p; ++i) {
            pre[i]->next_[i] = p->next_[i];
        }

        return true;
    }
    // 寻找小于 target 值的最大节点
    vector<shared_ptr<SkipNode>> find_node(int target) {
        vector<shared_ptr<SkipNode>> ret(MAX_LEVEL, nullptr);
        auto cur = root_;
        for (int i = MAX_LEVEL - 1; i >= 0; i--) {
            while(cur->next_[i] && cur->next_[i]->value_ < target) {
                cur = cur->next_[i];
            }
            ret[i] = cur;
        }
        return ret;
    }

private:
    shared_ptr<SkipNode> root_;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */