/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> v1, v2;
    void dfs1(TreeNode* node) {
        if (node->left != NULL) {
            dfs1(node->left);
        }
        if (node->right != NULL) {
            dfs1(node->right);
        }
        if (node->left == NULL && node->right == NULL) v1.push_back(node->val);
        return;
    }
    void dfs2(TreeNode* node) {
        if (node->left != NULL) {
            dfs2(node->left);
        }
        if (node->right != NULL) {
            dfs2(node->right);
        }
        if (node->left == NULL && node->right == NULL) v2.push_back(node->val);
        return;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        dfs1(root1);
        dfs2(root2);
        if (v1.size() != v2.size()) return false;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
