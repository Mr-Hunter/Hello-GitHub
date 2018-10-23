#pragma once

#include "../binary_tree.hpp"

bool getPath(TreeNode* root, TreeNode* p, deque<TreeNode*>& path) {
    if (root == nullptr)
        return false;

    path.push_back(root);
    if (p == root)
        return true;

    bool found = false;
    if (!found)
        found = getPath(root->left, p, path);
    if (!found)
        found = getPath(root->right, p, path);

    if (!found)
        path.pop_back();

    return found;
}

/* �Ƕ������汾

struct TreeNode {
    int                       val;    
    std::vector<TreeNode*>    children;    
};

bool getPath(const TreeNode* root, const TreeNode* p, deque<const TreeNode*>& path) {
    if (root == nullptr)
        return false;

    path.push_back(root);
    if (root == p)
        return true;

    bool found = false;
    auto i = root->children.begin();            // ˳�����ÿ���ӽڵ�
    while (!found && i < root->children.end()) {
        found = GetNodePath(*i, p, path);
        ++i;
    }

    if (!found)  // ���û���ҵ��ͣ�˵����ǰ�ڵ㲻��·���ڣ�����
        path.pop_back();

    return found;
}
*/
