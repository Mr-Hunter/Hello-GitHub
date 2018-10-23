/*
���л������� https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

**��Ŀ����**
    ```
    ��ʵ�������������ֱ��������л��ͷ����л���������
    �ӿ����£�
      char* Serialize(TreeNode *root);
      TreeNode* Deserialize(char *str);
    ```
    - ���������������һ�����������л�
    - �����л�Ҫ���ܹ�ͨ�����л��Ľ����ԭ������
    - �սڵ��� '#' ��ʾ���ڵ�֮���ÿո�ֿ�

**˼·**
    - һ���������ı���ʱ�����Էǿ�Ҷ�ӽڵ���Ϊ��ײ㣬��ʱ��ԭ����������Ҫǰ�����+���������������
    - ����Կսڵ���Ϊ������ײ㣬��ôֻ��Ҫǰ��������ܻ�ԭ���������������뷴���л�ͬ�����У�������ؼ���һ�㣩
*/
#pragma once

#include "../all.h"

class Solution {
    // ��Ϊ�ӿ����ƣ�������Ҫʹ�������� ss
    stringstream ss_fw;
    stringstream ss_bw;
    char ret[1024];
    //char* ret;

    void dfs_s(TreeNode *node) {
        if (node == nullptr) {
            ss_fw << "#";
            return;
        }
        ss_fw << node->val;
        ss_fw << " ";
        dfs_s(node->left);
        ss_fw << " ";
        dfs_s(node->right);
    }

    TreeNode* dfs_d() {
        if (ss_bw.eof())
            return nullptr;
        string val;            // ֻ���� string ���գ��� int �� char ����������
        ss_bw >> val;
        if (val == "#")
            return nullptr;
        TreeNode* node = new TreeNode{ stoi(val) }; // 
        node->left = dfs_d();
        node->right = dfs_d();
        return node;
    }

public:
    char* Serialize(TreeNode *root) {
        dfs_s(root);
        // ������˺ܾ�
        // return (char*)ss.str().c_str();  // ������⣬ԭ��δ֪
        return strcpy(ret, ss_fw.str().c_str());
    }

    TreeNode* Deserialize(char *str) {
        if (strlen(str) < 1) return nullptr;
        ss_bw << str;
        return dfs_d();
    }
};

void
solve()
{
    TreeNode n1{ 1 };
    TreeNode n2{ 2 };
    TreeNode n3{ 3 };
    TreeNode n4{ 4 };
    TreeNode n5{ 5 };
    TreeNode n6{ 6 };
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n3.left = &n5;
    n3.right = &n6;
    //solve();
    Solution s;
    auto ret = s.Serialize(&n1);
    cout << ret;
    //cout << s.Serialize(&n1) << endl;

    auto root = s.Deserialize(ret);
    cout << root->val;
}

