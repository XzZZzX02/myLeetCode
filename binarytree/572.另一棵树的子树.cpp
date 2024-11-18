/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
 */
#include "leetcode.h"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    template <typename T>
    inline void getNext(T pattern, std::vector<int>& next) {
        int j = 0;
        next[0] = j;
        for (int i = 1; i < pattern.size(); i++) {
            while (j > 0 && pattern[i] != pattern[j]) {
                j = next[j - 1];
            }
            if (pattern[i] == pattern[j]) {
                j++;
            }
            next[i] = j;
        }
    }

    template <typename T>
    inline int kmp(T goal, T pattern) {
        std::vector<int> next(pattern.size(), 0);
        getNext(pattern, next);
        int i = 0, j = 0;
        while (i < goal.size() && j < pattern.size()) {
            if (goal[i] == pattern[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = next[j - 1];
            } else {
                i++;
            }
        }
        if (j == pattern.size()) {
            return i - j;
        }
        return -1;
    }
    void preorder(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        vec.push_back(root->val);
        if (root->left) {
            preorder(root->left, vec);
        } else {
            vec.push_back(10001);
        }
        if (root->right) {
            preorder(root->right, vec);
        } else {
            vec.push_back(10001);
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<int> root_vec, sub_vec;
        preorder(root, root_vec);
        preorder(subRoot, sub_vec);
        kmp(root_vec, sub_vec);
        return kmp(root_vec, sub_vec) != -1;
    }
};
// @lc code=end
