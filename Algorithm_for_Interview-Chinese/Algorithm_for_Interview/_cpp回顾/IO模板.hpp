/*
��Щ������Բ��� LeetCode ����ʽ����Ҫ�ֶ�����������ش˼�¼

�������뷽ʽ��
    1. ���벻˵���ж��ٸ� Input���� EOF Ϊ������־
    2. ָʾ�� N �� Input
    3. ���벻˵���ж��ٸ� Input����ĳ����������Ϊ������־
    4. �������룬��ĳ�����������˳���2 �� 1 �� 3 ��ϣ�
    5. ������һ���е��ַ��������ո�
    6. �����Ƕ����ַ��������ո�
    7. ���ļ����Ǹ���ȡ�������� cin �� cout

�����
    �Ƿ��У������У����л��ǿո�Ҫ����������
    
> ACMѧϰ����2����ACM��Ŀ�г��õ����������ʽ - CSDN���� https://blog.csdn.net/u010480899/article/details/52280065
*/
#pragma once

#include "../all.h"

#define MAXN 1000

class Solution {
public:
    void foo() {
    /* 1. ���벻˵���ж��ٸ� Input���� EOF Ϊ������־*/
        int a, b;
        // C ��ʽ
        while (scanf("%d %d", &a, &b) != EOF) {  // scanf ����ֵΪ���������ĸ��������û�з��� -1��EOF ��һ��Ԥ����ĳ��� -1
            //
        }
        // C++
        while (cin >> a >> b) {
            //
        }

    /*2. ָʾ�� N �� Input*/
        // C
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &a, &b);
        }
        // C++
        cin >> n;
        while(n--) {
            cin >> a >> b;
        }

    /*3. ���벻˵���ж��ٸ� Input����ĳ����������Ϊ������־*/
        // C
        // ʾ�� 1
        //while (scanf("%d %d", &a, &b) && (a != 0 && b != 0)) {
        while (scanf("%d %d", &a, &b) && (a || b)) {  // ������д��
            printf("%d\n", a + b);
            // �Ƿ��У������У����л��ǿո�Ҫ����������
        }
        // ʾ�� 2
        while (scanf("%d", &n) != EOF && n != 0) {
            cout << a + b << endl;
        }

        // C++
        // ʾ�� 1
        while (cin >> a >> b) {
            if (a == 0 && b == 0)
                break;
            //
        }
        // ʾ�� 2
        while (cin >> n && n != 0) {
            //
        }

    /*4. �������룬��ĳ�����������˳���2 �� 3 ��ϣ�*/
        // C++
        while (cin >> n && n != 0) {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                cin >> a;
                tmp.push_back(a);
            }
        }

    /*5. ������һ���е��ַ��������ո�*/
        // 1���� char[] ����
        // C
        char buff[MAXN];  // MAXN = 1000
        gets(buff);  // VS 2017 ���Ҳ����˺���
        // C++
        cin.getline(buff, MAXN);  // ����������Ĭ���� '\n'
        cin.getline(buff, MAXN, '\n');
        
        // 2���� string ����
        string s;
        getline(cin, s);
        getline(cin, s, '\n');  // ���Ƶģ�����������Ҳ��Ĭ�� '\n'��ע�⣬���յ��ַ����в���������ַ�

    /*6. �����Ƕ����ַ��������ո�*/
        cin >> n;
        cin.get();  // ���룬����n Ҳ���������� getline()��������һ������
        while (n--) {
            string s;
            getline(cin, s);
        }

    /*7. ���ļ����Ǹ���ȡ�������� cin �� cout*/
        // C
        FILE *cfin = fopen("in.txt", "r");
        FILE *cfout = fopen("out.txt", "w");
        int a, b;
        while (fscanf(cfin, "%d %d", &a, &b) != EOF) { // ���Ƶģ��� scanf ���� fscanf
            fprintf(cfout, "%d\n", a + b);
        }
        fclose(cfin);
        fclose(cfout);

        // C++
        ifstream fin("in.txt");
        ofstream fout("out.txt");
        int a, b;
        while (fin >> a >> b) {
            fout << a + b;
        }
        fin.close();
        fout.close();
    }
};