#define _CRT_SECURE_NO_WARNINGS 1

/*
1�����������������С������ɺ� ��ţ�ͣ�
*/

/*
˼·:��arr���� ���min��max   ������ʵ����[min��max]��������С���ܱ�arr����ӵõ�������
 ��dfs+���ݷ�+��֦+�����������ȥ�� ȥѰ�ҿ��ܽ�
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	/**
	*	���������е���С������ɺ�
	*	���룺��������arr
	*	���أ����������е���С������ɺ�
	*/
	bool flag = false;
	void dfs(int begin, int target,vector<int>& arr){
		//beginΪ��������������±�  (�������Ӽ��������������ͬ���֣���һ���������Ϊ��һ�����+1)
		if (target == 0){
			//�ҵ����н�
			flag = true;
			return;
		}
		for (size_t i = begin; i < arr.size(); ++i){
			if (target - arr[i] < 0){
				//���������� "��֦" ��ߵ�����Ҳ�����ж��� �˳�ѭ�����л���
				break;
			}
			target -= arr[i];
			dfs(i+1, target, arr);
			target += arr[i];
		}
	}
	int getFirstUnFormedNum(vector<int> arr, int len) {
		sort(arr.begin(), arr.end());
		int min = arr[0];
		int max = 0;
		for (int i = 0; i < len; ++i){
			max += arr[i];
		}
		for (int i = min; i <= max; ++i){
			flag = false;
			dfs(0,i,arr);
			if (flag == false){
				return i;
			}
		}
		return max + 1;
	}
};

//int main(){
//	Solution a;
//	vector<int> arr = { 3,2,5 };
// 	a.getFirstUnFormedNum(arr,3);
//	return 0;
//}

/*
2���мٱ� ��ţ�ͣ�

��Ȼ�мٱң������������ˣ�����ũ�����Ĺ��ʲ����ǣ�ûǮ��ô������?nowcoder���ȥ�����⣬
�����������Ǯ���мٱҡ���ϧnowcoderһ��С�İ��������������ˡ�ֻ֪���ٱұ�����ᣬ
����һ����ƽ(��ƽ��������������Ӳ��)����������ʱ���ҳ��ٱҡ�
���룺
	1<=n<=2^30������0����
���:
	���Ҫ�Ƽ���һ�����ҳ��ٱң�
*/

/*
˼·��ö��һ�����ҹ���
	1--��0
	2--��1
	3�� ��Ϊ 1 1 1 ���� ֻ��Ҫ��һ�ξ��ܶ��ԣ�ƽ��ʣΪ��  ��ƽ���Ϊ��
	4����Ϊ 1 1 2����  ����������1 1ƽ�� ��2��Ҫ�ٳ�һ�� �ܹ�2��
	5����Ϊ 2  2 1����  ���� �ֱ������2����� ��һ����ʣ�µ��ĸ� ���Գ�2��

	�����Ƴ� ��Ϊ�����Ժ� �����һ�Ѽ���ȥ�� ֱ��n==1 ����0�� n<=3����һ��
	
*/
#include<iostream>
using namespace std;

int func(int n){
	if (n <= 1){
		return 0;
	}
	if (n <= 3){
		return 1;
	}
	//��n+0��/3 == (n+1)/3==(n+2)/3 ��n%3��0��1��2,�����һ�� = ��n/3+n%3��/3 = ��n+2��/3
	return func((2 + n) / 3) + 1;
}
int main(){
	int n = 0;
	while (cin >> n){
		if (n == 0){
			break;
		}
		cout << func(n) << endl;
	}
	return 0;
}