#pragma once

#include "../binary_tree.hpp"

#include <sstream>
using namespace std;


// ţ���������л������� https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&tPage=4&rp=4&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
    stringstream ss_fw;
    stringstream ss_bw;
public:
    char* Serialize(TreeNode *root) {
        
        dfs_fw(root);

        char ret[1024];
        return strcpy(ret, ss_fw.str().c_str());
        // return (char*)ss.str().c_str();  // ������⣬ԭ��δ֪
    }

    void dfs_fw(TreeNode *node) {
        if (node == nullptr) {
            ss_fw << "#";
            return;
        }
        ss_fw << node->val;

        ss_fw << " ";
        dfs_fw(node->left);

        ss_fw << " ";
        dfs_fw(node->right);
    }

    TreeNode* Deserialize(char *str) {
        if (strlen(str) < 1) return nullptr;

        ss_bw << str;
        return dfs_bw();
    }

    TreeNode* dfs_bw() {
        if (ss_bw.eof())
            return nullptr;

        string val;            // ��Ϊ "#"���� int �� char ���ն���������
        ss_bw >> val;

        if (val == "#")
            return nullptr;

        TreeNode* node = new TreeNode{ stoi(val) };
        node->left = dfs_bw();
        node->right = dfs_bw();
        return node;
    }
};