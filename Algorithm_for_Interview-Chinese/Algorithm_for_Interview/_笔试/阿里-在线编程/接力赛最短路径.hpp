/*
����������

    ����Сѧ��С������Ҫ����һ��һ�ȵĽ����ܴ����ˣ�����С������ȴ������һ�����⣺��ƽ����ܴ�������·�����ܰ���������������ô��
    ����Сѧ���Գ����һ����N���ڵ��ͼ��ÿ����䶼��һ����·����������Сѧ��ÿ���඼��M��ѧ����������ҪΪ������Ƴ�һ��ǡ�þ���M���ߵ�·����
    ����Сѧ��С������ϣ��ȫ�̿������е����أ���������Ҫ����������侭��M���ߵ����·���ľ�����������Թ��ο���
    ����Ҫ�������һ��������
        res[][] Solve( N, M, map[][]);
    
    ע�⣺map��Ȼ��N * N�Ķ�ά���飬��map[i][j] == map[j][i]��map[i][i] == 0��-1e8 <= map[i][j] <= 1e8������·ȫ��������ߣ����Ի���2 <= N <= 100, 2 <= M <= 1e6��Ҫ��ʱ�临�Ӷȿ�����O(N^3*log(M))��
    
        map�����ʾ��һ�ų���ͼ����������������ͬ�ڵ�i,j�䶼��һ���ߣ��ߵĳ���Ϊmap[i][j]��N��ʾ���еĽڵ�����
        ��Ҫ���ص�����Ҳ��Ȼ��һ��N * N�Ķ�ά���飬��ʾ��i�����ߵ�j������M���ߵ����·��
        ���·����Ӧ���ǰ����ظ��ߵ������
    ������
        N = 3
        M = 2
        map = {
            {0, 2, 3},
            {2, 0, 1},
            {3, 1, 0}
        }

    ������resultΪ��
        result = {
            {4, 4, 3},
            {4, 2, 5},
            {3, 5, 2}
        }
    �������ͣ�
        1->1�����ַ�����1->2->1������Ϊ2+2=4����1->3->1������Ϊ3+3=6��
        2->2�����ַ�����2->1->2������Ϊ2+2=4����2->3->2������Ϊ1+1=2��
        3->3�����ַ�����3->1->3������Ϊ3+3=6����3->2->3������Ϊ1+1=2��
        1->2ֻ��һ��������1->3->2������Ϊ3+1=4��
        1->3ֻ��һ��������1->2->3������Ϊ2+1=3��
        2->3ֻ��һ��������2->1->3������Ϊ2+3=5��
        ���ݶԳ��Կ��Եõ��������ֵĴ�

    �������汾: gcc 4.8.4
    ��ʹ�ñ�׼�������(stdin��stdout) ��������г���д��һ���ļ����ʹ���ѽ���ͼ�Ρ��ļ������硢ϵͳ��ص�ͷ�ļ��Ͳ�������sys/stat.h , unistd.h , curl/curl.h , process.h
    ʱ������: 3S (C/C++���������Ϊ: 5 S)   �ڴ�����: 128M (C/C++���������Ϊ: 640 M)
    ����:
        ���뷶�� ���������ʾ�ܹ�3���ڵ�ͣ�
        3    (��ʾN=3)
        2    (M=2)
        ������N*N�ľ��󣨴˴���һ��3*3�ľ���
        3 3
        0 2 3
        2 0 1
        3 1 0
    ���:
        �����һ��N*N�ľ��󣨴˴���������õ���һ��3*3�ľ���
        4 4 3
        4 2 5
        3 5 2
    ���뷶��:
        3
        2
        3 3
        0 2 3
        2 0 1
        3 1 0
    �������:
        4 4 3
        4 2 5
        3 5 2

    ����������ɣ� ͨ����80.00%
*/
#pragma once

#include<iostream>
#include<vector>

using namespace std;

void search(vector<vector<int>>& map, vector<vector<int>>& res, int m, int start, int end, int distance)
{
    if (m == 0) {
        if (distance < res[start][end]) {
            res[start][end] = distance;
            return;
        }
        return;
    }

    for (int i = 0; i < map.size(); i++) {
        if (map[end][i] != 0)
            search(map, res, m - 1, start, i, distance + map[end][i]);
    }
}

vector<vector<int>> solve(int n, int m, vector<vector<int>>& map) {
    vector<vector<int>> res(n, vector<int>(n, INT8_MAX));
    for (int i = 0; i < map.size(); i++)
        search(map, res, m, i, i, 0);

    return res;
}


int _main()
{
    int n, m, w, h;
    cin >> n;
    cin >> m;
    cin >> w >> h;  // == n
    vector<vector<int>> map(h, vector<int>(w, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
        }

    //vector<vector<int>> res(n, vector<int>(n, INT8_MAX));
    //for (int i = 0; i<data.size(); i++)
    //    search(data, res, m, i, i, 0);
    auto res = solve(n, m, map);

    for (auto s : res) {
        for (auto a : s)
            cout << a << ' ';
        cout << endl;
    }
    //for (int i = 0; i < res.size() - 1; i++) {
    //    for (int j = 0; j < res[i].size() - 1; j++)
    //        cout << res[i][j] << ' ';
    //    cout << res[i][res[i].size() - 1] << endl;
    //}
    //for (int j = 0; j < res[res.size() - 1].size() - 1; j++)
    //    cout << res[res.size() - 1][j] << ' ';
    //cout << res[res.size() - 1][res[res.size() - 1].size() - 1];
        
    return 0;
}

