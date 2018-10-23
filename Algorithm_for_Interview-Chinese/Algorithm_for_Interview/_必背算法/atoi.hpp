/*
atoi() �Ĺ���:
    ���ַ�����C���ת�������ͣ�
    atoi() ������ǰ��Ŀո��ַ���ֱ���������ֻ������Ųſ�ʼ��ת����
    �������� ������ �� ������('\0') ʱ����ת��������������أ�����ת�������������
    ����������������� INT_MAX �� INT_MIN;
    *���� atoi ���ᴦ�� NULL ָ��
    
    �Ϸ�������
        "123"           -> 123
        "+123"          -> 123
        "-123"          -> -123
        "123abc"        -> 123
        "   123abc"     -> 123
        "a123"          -> 0

OJ:
    ���ַ���ת�������� https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
    ��Ŀ��Դ����ָOffer

���Ĵ��룺
    while (*p >= '0' && *p <= '9') {
        ret = ret * 10 + (*p - '0');
        p++;
    }

    �������

*/
#pragma once
#include "../all.h"

int atoi_my(const char* const cs) {
    if (cs == NULL) return 0;

    int ret = 0;
    int sign = 1;
    auto *p = cs;  // cs Ϊ��ָ��

    // ����ǰ��Ŀո�
    while (isspace(*p)) p++;

    // �ж�����
    if (*p == '-') sign = -1;
    if (*p == '-' || *p == '+') p++;

    // �׸��ǿ��ַ��������֣�ע�����ж�������˳��
    // if (*p < '0' && *p > '9') return 0;       // ����Ҫ

    // ѭ��ת�����������Ĵ��룩��������ж�
    while (*p >= '0' && *p <= '9') {
        int new_ret = ret * 10 + (*p - '0');
        if (new_ret / 10 != ret) {
            return sign > 0 ? INT_MAX : INT_MIN;
        }
        ret = new_ret;
        p++;
    }
    // ������ж�
    /*while (*p >= '0' && *p <= '9') {
        ret = ret * 10 + (*p - '0');
        p++;
    }*/
    return ret * sign;
}

void solve() {
    print(atoi_my("123"));
    print(atoi_my("+123"));
    print(atoi_my("-123"));
    print(atoi_my("   123abc"));
    print(atoi_my("   +123abc"));
    print(atoi_my("   -123abc"));
    print(atoi_my("   123abc   "));
    print(atoi_my("   +123abc   "));
    print(atoi_my("   -123abc   "));
    print();
    print(atoi_my("a123"));
    print(atoi_my("+a123"));
    print(atoi_my("-a123"));
    print(atoi_my("a123   "));
    print(atoi_my("+a123   "));
    print(atoi_my("-a123   "));
    print(atoi_my("   a123"));
    print(atoi_my("   +a123"));
    print(atoi_my("   -a123"));
    print(atoi_my("   a123   "));
    print(atoi_my("   +a123   "));
    print(atoi_my("   -a123   "));
    print(atoi_my("   a+123   "));
    print(atoi_my("   a-123   "));
    print(atoi_my("222222222222222222222222"));
    print(atoi_my("-222222222222222222222222"));
    print();
    const char p[] = "   123abc";
    print(atoi_my(p));
    print(p);
    print();
    print(atoi_my(NULL));
}
