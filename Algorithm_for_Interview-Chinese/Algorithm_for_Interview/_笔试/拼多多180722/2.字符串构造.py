"""
�ַ�������

����������
    һ��������һ���ִ�ѭ�����ɣ��� s[i]=t[i%n]������ "abcabc" �� "abc" ����

    ע�⣺"abcabcab" Ҳ���� "abc" ���ɵģ�����ʱûע�������ֻ����һ����

    *����ʹ�� Python ����ַ���������⣬����Ҳֻ�� Python ����
"""

s = input()

n = len(s)
for i in range(1, n + 1) :
    base = s[:i]
    if base * (n // i) + base[:n % i] == s:
        print(base)
        break
