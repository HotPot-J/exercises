#define _CRT_SECURE_NO_WARNINGS 1

/*
1����������������������1�ĸ���
��ʵ�����½ӿڣ�
	public static int findNumberOf1(int num)
	{
		
	}
��������:
	����һ������ 5
���������
	����������������1�ĸ��� 2

*/

//˼·��λ����
#include<iostream>
using namespace std;

int findNumberOf1(int num)
{
	int res = 0;
	for (int i = 0; i < 32; ++i){
		if ((num >> i)&1){
			++res;
		}
	}
	return res;
}
//int main(){
//	int num = 0;
//	while (cin >> num){
//		cout << findNumberOf1(num) << endl;
//	}
//	return 0;
//}

/*
2.����
	�����ҷ���n����ɫ�����ף����׷������֣�����ÿ����ɫ�����������׸�����һ��
	��ͬ,A��������Ҫ���ţ������������һЩ���ף�Ȼ��ѡ��һ˫��ɫ��ͬ��������
	���ס����ڵ������ǣ�������Ҫ�ö���ֻ��������(����+����)�����ܱ�֤һ����
	ѡ��һ˫��ɫ��ͬ�����ס�
	������ɫ����n(1<=n<=13)��ͬʱ������������Ϊn�����飬left��right���ֱ����
	ÿ����ɫ�������׵����������ݱ�֤���ҵ�����������������26����һ����������һ��
	�Ϸ�������
��������:
	4,[0,7,1,6] [1,5,0,6]
���أ�10(���ͣ�������������ȡ��ֻ����������ȡ8ֻ)
*/

/*
˼·�� �����ȷδ������� �ο������ϴ��е�˼·��
	��һ�γ���Ϊn���������У�2 4 6 9  ѡ��һ�����������ܹ���֤������
	��ѡn-1�����ĺͶ�С����ѡ�����أ���Ȼ��ѡ������������֮��
	��θ���ס���������أ�
	��Ȼ��ѡ������������֮����+1 ����2+4+6+9��-2+1 ����ѡ��n-1�������ٶ�ѡһ��������ѡ��û��ʣ�µ��Ǹ�����һ����λ��
	���Ƶã���С������ = sum(arr)-arr[min]+1

���⼴Ϊ���ҵ�left����С������ �ҵ�right����С������ ��ѡ����С�ĸ�����+1��Ϊ���
����һ����ɫΪ0һ�����ײ�Ϊ0�����������Ҫ����ȱ����ȫ���߲��ܱ�֤����
*/

#include<vector>

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int res = 0;
		int sum_left = 0;
		int sum_right = 0;
		//������ɫ�͸���һһ��Ӧ �޷�ֱ������ѡ����Сֵ ���ﶨ��min����Сֵɸѡ����
		int left_min = INT_MAX;
		int right_min = INT_MAX;
		for (int i = 0; i < n; ++i){
			if (left[i] && right[i]){
				//��ͣ�������һ���и���ɫ���ף�һ���޸�ɫ���ף�
				sum_left += left[i];
				sum_right += right[i];
				//ɸѡ��Сֵ
				left_min = left_min>left[i] ? left[i] : left_min;
				right_min = right_min > right[i] ? right[i] : right_min;
			}
			else{
				//������һ��Ϊ0
				res += (left[i] + right[i]);
			}
		}
		int L = sum_left - left_min + 1;
		int R = sum_right - right_min + 1;
		int lr_min = L < R ? L : R;
		return  res + lr_min + 1;
	}
};
//int main(){
//	vector<int> l = { 0, 7, 1, 6 };
//	vector<int> r = { 1, 5, 0, 6 };
//	Gloves a;
//	a.findMinimum(4, l, r);
//	return 0;
//}