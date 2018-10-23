#pragma once

/*
ǰ׺���ʽת��׺���ʽ���沨��ʽ��

���룺
    1+((2+3)��4)-5

�����
    1 2 3 + 4 * + 5 -

��Ȼ�����кܶ��ֹ������˵�������ǵ�д�����ʱ��ŷ����кܶ��

ref: �С�ǰ����׺���ʽ - CSDN���� https://blog.csdn.net/lin74love/article/details/65631935
���Ǹ�����Ϊ˵�ĺ������������̣���ʵ�ֵ�ʱ���������˺ܶ�����

���´�������һЩѭ�������Ƕ���ģ�����ַ����Ϸ���Ӧ��ֻ��Ҫ�ж�һ�Σ�������Ҫѭ������δ��֤��
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <set>
using namespace std;

//set<char> l1{ '+', '-' };
//set<char> l2{ '*', '/' };
//
//vector<set<char>> l{ l1, l2 };

int get_level(char c) {
    switch (c) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    //case '(':
    //    return 3;
    default:
        return -1;
    }
}

string infix2suffix(const string& s) {
    stack<char> tmp;        // ����ջ
    queue<string> ans;      // ����ʹ�� string ���У���Ϊ���ܴ��ڶ�λ����
    //stringstream ret;       // ���ַ���ģ�����

    bool num_flag = false;      // �����ж����ֵ�ĩβ 
                                //��ʼ��Ϊ false ��Ϊ�˱����һ���ַ�������
    //int v = 0;            // ������ֵ
    string v{ "" };         // ���ַ���������ã���������֧����ĸ��ʽ�ı��ʽ
    for (auto c : s) {
        // ��������
        if (isalnum(c)) {           // �����λ����
            v.append(string(1, c)); // ע�⣬char �ַ�����ֱ��ת string
            num_flag = true;
        }
        else {
            if (num_flag) {     // ��Ϊ���ܴ��ڶ�λ���֣�����������Ҫ��������һ���������ַ������
                ans.push(v);
                //ret << v << ' ';
                v.clear();
                num_flag = false;
            }

            // ����������Ĺ���
            if (c == ')') {  // ������������ţ������ε���ջ�����ţ�ֱ������**��һ��**�����Ų��������ӵ� 1�����ܴ��������������ţ�
                while (!tmp.empty()) {
                    if (tmp.top() == '(') {
                        tmp.pop();
                        break;
                    }
                    ans.push(string(1, tmp.top()));
                    //ret << tmp.top() << ' ';
                    tmp.pop();
                }
            } // ע���������жϵ�˳�򣨿ӵ� 2����������ʼ�ղ�����ջ�ģ�����Ӧ���ȴ��������ţ�
            else if (tmp.empty() || tmp.top() == '(' || c == '(') {  // �������ջΪ�գ���ջ��Ϊ ')'��������������
                tmp.push(c);                                         // �򽫸��������ջ
            }
            else {
                while (!tmp.empty() && get_level(tmp.top()) >= get_level(c)) {  // ���ջ��Ԫ�ص����ȼ����ڵ��ڵ�ǰ��������򵯳�
                    if (tmp.top() == '(')  // ���ӵ� 3�������ŵ����ȼ��Ǵ�����ͨ������ģ�������Ӧ�������ﵯ����
                        break;
                    ans.push(string(1, tmp.top()));
                    //ret << tmp.top() << ' ';
                    tmp.pop();
                }
                tmp.push(c);
            }
        }
    }

    if (num_flag) {             // ���ʽ�����һ��������ջ
        ans.push(v);
        //ret << v << ' ';
    }

    while (!tmp.empty()) {      // �ַ�������������ε���ջ�е������
        if (tmp.top() == '(')   // ����жϺ����Ƕ����
            tmp.pop();
        ans.push(string(1, tmp.top()));
        //ret << tmp.top() << ' ';
        tmp.pop();
    }

    //return ret.str();

    stringstream ret;
    while (!ans.empty()) {
        ret << ans.front() << ' ';
        ans.pop();
    }
    return ret.str();
}

void solve() {
    // ֻ��������������������з����������

    cout << infix2suffix("12+(((23)+3)*4)-5") << endl;  // 12 23 3 + 4 * + 5 -
    cout << infix2suffix("1+1+1") << endl;              // 1 1 + 1 +
    cout << infix2suffix("(1+1+1)") << endl;            // 1 1 + 1 +
    cout << infix2suffix("(1+(1+1))") << endl;          // 1 1 1 + +
    cout << infix2suffix("1+(2-3)*4+10/5") << endl;     // 1 2 3 - 4 * + 10 5 / +
    cout << infix2suffix("az-(b+c/d)*e") << endl;       // az b c d / + e * -
}