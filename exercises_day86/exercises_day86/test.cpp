#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

/*
405. ����ת��Ϊʮ��������
����һ����������дһ���㷨�������ת��Ϊʮ�������������ڸ�����������ͨ��ʹ�� �������� ������

ע��:

ʮ��������������ĸ(a-f)��������Сд��
ʮ�������ַ����в��ܰ��������ǰ���㡣���Ҫת������Ϊ0����ô�Ե����ַ�'0'����ʾ���������������ʮ�������ַ����еĵ�һ���ַ���������0�ַ���
��������ȷ����32λ�з���������Χ�ڡ�
����ʹ���κ��ɿ��ṩ�Ľ�����ֱ��ת�����ʽ��Ϊʮ�����Ƶķ�����
ʾ�� 1��

����:
26

���:
"1a"
ʾ�� 2��

����:
-1

���:
"ffffffff"
*/

class Solution {
public:
	const char map[16] = { '0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

	string toHex(int num) {
		if (num == 0) return "0";
		string res;
		unsigned int n = num;
		unsigned calc = 0xf;
		unsigned temp = 0xf;
		int trans = 0;
		for (int i = 0; i<8; i++)
		{
			temp = (n&calc) >> trans;
			res += map[temp];
			calc <<= 4;
			trans += 4;
		}
		for (int i = res.length() - 1; i >= 0; i--)
		if (res[i] == '0') res.pop_back();
		else
		{
			reverse(res.begin(), res.end());
			return res;
		}
		return NULL;
	}
};

