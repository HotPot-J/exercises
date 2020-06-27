#define _CRT_SECURE_NO_WARNINGS 1

/*
1006. ���׳�
ͨ���������� n �Ľ׳�������С�ڻ���� n ���������ĳ˻������磬factorial(10) = 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1��

�෴�����������һ�����׳� clumsy���������ĵݼ������У�������һ���̶�˳��Ĳ����������������滻ԭ�еĳ˷����������˷�(*)������(/)���ӷ�(+)�ͼ���(-)��

���磬clumsy(10) = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1��Ȼ������Щ������Ȼʹ��ͨ������������˳���������κμӡ�������֮ǰִ�����еĳ˷��ͳ������裬���Ұ������Ҵ����˷��ͳ������衣

���⣬����ʹ�õĳ����ǵذ������floor division�������� 10 * 9 / 8 ���� 11���Ᵽ֤�����һ��������

ʵ�����涨��ı�����������һ������ N�������� N �ı��׳ˡ�



ʾ�� 1��

���룺4
�����7
���ͣ�7 = 4 * 3 / 2 + 1
ʾ�� 2��

���룺10
�����12
���ͣ�12 = 10 * 9 / 8 + 7 - 6 * 5 / 4 + 3 - 2 * 1


��ʾ��

1 <= N <= 10000
-2^31 <= answer <= 2^31 - 1  ���𰸱�֤���� 32 λ��������
*/
class Solution {
public:
	int clumsy(int N) {
		int res = 0;
		for (int i = N; i >= 1;)
		{
			int temp = 0;
			if (i >= 4)
			{
				temp = i*(i - 1) / (i - 2);
				res += i - 3;
			}
			else if (i == 3)
				temp = i*(i - 1) / (i - 2);
			else if (i == 2)
				temp = i*(i - 1);
			else if (i == 1)
				temp = i;
			if (i == N)
				res += temp;
			else res = res - temp;
			i = i - 4;
		}
		return res;
	}
};
