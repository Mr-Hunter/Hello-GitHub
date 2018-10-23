/*
�����е������ https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

��Ŀ��Դ����ָOffer

��Ŀ����
�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P��
����P��1000000007ȡģ�Ľ������� �����P%1000000007

��������:
��Ŀ��֤�����������û�е���ͬ������

���ݷ�Χ��
    ����%50������,size<=10^4
    ����%75������,size<=10^5
    ����%100������,size<=2*10^5
ʾ��1
    ����
    1,2,3,4,5,6,7,0
    ���
    7

ʱ�����ƣ�1�� �ռ����ƣ�65536K(64MB) �ȶ�ָ����147592
����֪ʶ�㣺 ����

˼·������
    ����˼·��ð�����򣨲��������ֻ��ں�ʱ���Ͽ�����
    ע��ռ����ƺͶ� size ���ر�˵������Ȼ��Ҫ��ƽ��ʱ��Ϳռ������
    
    ˼· 2: ����ԭ���飬������������һ������λ����ǰ���٣�˵���ж��������
        �����ԣ�
        Ӧ���Ǽ�¼ÿ���������ƶ���λ��
        �����ԣ����������һ���ģ�

    ˼· 3����һ�� map ��¼ (i, min)��һ�� min �����˱仯��˵������ i �������
        ����������ֻ������һ���֣�

    �ο�����ָOffer�����鲢�����˼�룬�������������
        �е��ѣ������˺ܾã����´���ȫ��������������һ���

�ύ��¼��
    1. ����˼· ����Ȼ��ʱ���Ϲ��ˣ�

*/
#pragma once

#include "../all.h"

class Solution {
public:

    // ˼·1����ȷ�����ǳ�ʱ
    int InversePairs_1(vector<int> data) {
        if (data.empty()) return 0;

        int ret = 0;
        int sz = data.size();
        for (int i = sz-1; i >= 1; i--) {
            int tmp = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (data[j] > data[i])
                    tmp++;
            }
            ret += tmp;
        }
        return ret;
    }

    // ˼·2������
    int InversePairs_2(vector<int> data) {
        if (data.empty()) return 0;

        int ret = 0;
        vector<int> bac(data);
        map<int, int> m;
        sort(bac.begin(), bac.end());
        for (int i = 0; i < data.size(); i++)
        {
            m[data[i]] = i;
        }
        for (int i = 0; i < data.size(); i++)
        {   
            /*int tmp = m[bac[i]] - i;
            ret += tmp > 0 ? tmp : 0;*/
            int tmp = i - m[bac[i]];
            ret += tmp > 0 ? tmp : 0;
        }

        return ret;
    }

    // ˼· 3 ������
    int InversePairs(vector<int> data) {
        if (data.empty()) return 0;

        int ret = 0;
        map<int, int> m;
        int n_min = data[0];  // ��¼������ i ʱ����Сֵ
        m[0] = n_min;
        for(int i = 1; i<data.size(); i++)
        {
            n_min = min(n_min, data[i]);
            if (m[i-1] != n_min) {
                ret += i;
            }
            m[i] = n_min;
        }

        return ret;
    }
};

void solve()
{
    vector<int> data{ 364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575 };
    //vector<int> data{ 3,2,1,4,5,6,7,0 };
    int ret = Solution().InversePairs(data);  // Ӧ���� 2519
    print(ret);
}