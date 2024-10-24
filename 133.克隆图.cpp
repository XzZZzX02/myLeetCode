/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */
#include "leetcode.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (node == nullptr) {
            return nullptr;
        }
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        for (auto& neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neighbor, visited));
        }
        return cloneNode;
    }
};
// @lc code=end

