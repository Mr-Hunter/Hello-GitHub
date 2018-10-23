#pragma once

#include "../all.h"

class num_sequence {
public:
    // PtrType ��һ��ָ�룬ָ�� num_sequence �ĳ�Ա������
    //  �ó�Ա��������ֻ����һ�� int �Ͳ������Լ���������Ϊ void
    typedef void (num_sequence::*PtrType)(int);

    enum { cnt_seq = 2 };              // Ԥ��������������
    enum ns_type {
        ns_fibonacci, ns_square
    };

    // ���캯����Ĭ��ָ��쳲���������
    num_sequence() : _pmf(func_tbl[ns_fibonacci]) { }

    // ����ָ��ָ��
    void set_sequence(ns_type nst) {
        switch (nst) {
        case ns_fibonacci: case ns_square:
            _pmf = func_tbl[nst];
            break;
        default:
            cerr << "invalid sequence type\n";
        }
    }
    void print(int n) {
        (this->*_pmf)(n); // ͨ��ָ��ѡ����Ҫ���õĺ���
    }
    // _pmf ����ָ�������κ�һ������
    void fibonacci(int n) {
        int f = 1;
        int g = 1;
        for (int i = 2; i <= n; i++)
            g = g + f, f = g - f;
        cout << f << endl;
    }
    void square(int n) {
        cout << n * n << endl;
    }

private:
    PtrType _pmf;
    static PtrType func_tbl[cnt_seq];  // �����������к�����ָ��
                                       // Ϊ�˼����ԣ����Ƽ�д�� `static vector<vector<int>��û�пո�> _seq;`
};

// static ��Ա������ʼ��
num_sequence::PtrType
num_sequence::func_tbl[cnt_seq] = {
    &num_sequence::fibonacci,
    &num_sequence::square,
};

void solve() {
    auto ns = num_sequence();
    ns.print(5);  // 5
    ns.set_sequence(num_sequence::ns_square);  // ��������ָ���Ի�ö�̬��Ч��
    ns.print(5);  // 25
}
