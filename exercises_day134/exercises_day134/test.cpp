#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

/*
1���ϳ���
��n��ͬѧվ��һ�ţ�ÿ��ѧ����һ������ֵ��ţţ�����n��ѧ���а���˳��ѡȡK��ͬѧ��Ҫ��
��������ѧ����λ�ñ�ŵĲ����d��ʹ����K��ѧ��������ֵ�ĳ˻�������ܷ������ĳ˻�
��
��������:
	ÿ���������1������������ÿ���������ݵĵ�һ�а���һ������n(1<=n<=50)����ʾѧ���ĸ���
	��������һ�У�����n������������˳���ʾÿ��ѧ��������ֵai(-50<=ai<=50)����������һ��
	��������������k��d(1<=k<=10,1<=d<=50)
���������
	���һ�б�ʾ���ĳ˻�

����:
	���룺
		3
		7 4 7
		2 50
	�����
		49
*/

/*
˼·����̬�滮:
   ��ps������ο����������е����������ǳ--����
   ���ڱ���ĸ�������Ҫ�󣬶���̬�滮Ҫ�����һ״̬��
   �Ʋ����һ״̬�����Ž����ǲ��������Ƶ����̣�
	1.����ѡ���i��λ�ã���Ϊ��k�����ֵĹ̶�λ�ã���ôʣ�µ�k-1��������iλ��֮ǰ��
	λ��Ѱ��
	
	2.���Ǽ���jΪ��k-1�����֣���ĿҪ�������������겻�ܳ���d����ôj�������� 
	i-j<=d&&j>0 (�����������±��1��ʼ������dp����Ĺ滮)
	
	3.����һ��ҪѰ��k�����ֵĳ˻���ϣ�������dp[k+1][n+1]
	
	4.���ڸ���Ϊ�˻����Ұ����и�������ô������Ҫά������dp��dp_max��dp_min����Ϊ
	����������ʱ��max = min*����

	5.���ƹ�ʽ��Դ���� DynamicProgramming�����������±�Ƚϱ������ù�ʽ��

	6.�Ժ�һʱ�޷���⣬�ǵû��������һ������������--��
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void DynamicProgramming(vector<long long>& arr,int& n ,int& K,int& d){

	//���屣�����ֵ
	long long res = LONG_MIN;
	//�������Ƕ��岢��ʼ������dp��ά����
	vector<vector<long long>> dp_max;
	vector<vector<long long>> dp_min;
	dp_max.resize(K + 1); dp_min.resize(K + 1);
	for (int i = 0; i < K + 1; ++i){
		dp_max[i].resize(n + 1, 0);
		dp_min[i].resize(n + 1, 0);
	}
	//���������е�������
	//dp_max[k][i] = max(dp_max[k][i],dp_max[k-1][j]*arr[i],dp_min[k-1][j]*arr[i])
	//dp_max[k][i] = min(dp_min[k][i],dp_max[k-1][j]*arr[i],dp_min[k-1][j]*arr[i])
	// k�����У����ڼ�������    j�����У�����k-1�����ֵ�λ��    i��ȷ���ĵ�k������λ��
	for (int i = 1; i <= n; ++i){
		//Ϊdp[1][i]��һ�е�i�и�ֵ���Թ̶���k������
		dp_max[1][i] = arr[i];
		dp_min[1][i] = arr[i];
		//���ƽ��ΪK��������˵����ֵ
		for (int k = 2; k <= K; ++k){
			//���ǵ�k-1�����ֵ�λ�ã���Ȼ��i-1��ʼ����һ���Ѿ��̶���
			for (int j = i - 1; j > 0 && i - j <= d; --j){
				dp_max[k][i] = max(dp_max[k][i], max(dp_max[k - 1][j] * arr[i], dp_min[k - 1][j] * arr[i]));
				dp_min[k][i] = min(dp_min[k][i], min(dp_max[k - 1][j] * arr[i], dp_min[k - 1][j] * arr[i]));
			}
		}
		//���ڶ���forѭ���������ͻ�õ�һ����ǰk������˵����ֵ
		res = max(dp_max[K][i] , res);
	}
	cout << res << endl;
}

//int main(){
//	int n = 0;
//	while (cin >> n){
//		vector<long long> students;
//		int tmp = 0;
//		//����Ч���ֵ��±��1��ʼ�����ں��ڵĴ���
//		students.push_back(0);
//		for (int i = 1; i <= n; ++i){
//			cin >> tmp;
//			students.push_back(tmp);
//		}
//		int k = 0, d = 0;
//		cin >> k >> d;
//		 DynamicProgramming(students,n,k,d) ;
//	}
//	return 0;
//}


/*
1����Ϸ��
�Ѻ�Ա��С��������ü�����������Σ���ĳ��С������һ����Ϸ�ű��ݣ����ʵı��ݽ�����
�����ų����ʹ��������ǰ�������ۣ�С�����������˽⵽����Ϸ���������һ���½�Ŀ"��
���޺���"������Ϸ�ŵ��޺����ݡ����ǵ���ȫ���أ�Ҫ����޺������У�վ��ĳ���˼��ϵ���
Ӧ�ñ��Լ������ݣ�����ȡ��ų���Ҫ���ε��޺������ĵ���ߣ����������ڶ࣬����ͷ�����
������Ա��С�����úܼ򵥣�����ͳ���˲�����Ա��������أ����Һܿ��ҵ�������޺��ĸ߶ȣ�
��ݱ�����Ϸ��Ա���α��Ϊ1-N��

��������:
	����һ��������N����ʾ��Ա����
�������:
	������m����ʾ�޺����ĸ߶�
*/

/*
˼·:
	1.���Լ��ߵıض�����վ���Լ�����ϣ����԰�����߽������У��ɸߵ��ͣ�
	��sort���ɽ����
	2.Ȼ����ߴ������ұض�������������ô����ֻ��Ҫ�ҳ��������ص���ݼ����м���
	����̬�滮�� dp[i] = max(dp[j])+1 j<i��num[i]<num[j]

*/

#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;
struct man
{
	int _w;
	int _h;
};
bool cmp(man& a, man& b){
	//����
	if (a._h == b._h){
		//������ȵ������ �ص���ǰ��
		return a._w > b._w;
	}
	return a._h > b._h;
}
int main(){
	int n = 0;
	while (cin >> n){
		int index = 0, w = 0, h = 0;
		vector<man> arr;
		for (int i = 0; i < n; ++i){
			man tmp;
			cin >> index >> w >> h;
			tmp._w = w;
			tmp._h = h;
			arr.push_back(tmp);
		}
		sort(arr.begin(), arr.end(), cmp);

		//Ѱ��arr�ĳ����صݼ�����
		vector<int> dp(n, 0);
		for (int i = 0; i < n; ++i){
			dp[i] = 1;
			for (int j = 0; j < i; ++j){
				//��������������Ȳ��ܵ�
				if ((arr[j]._w>arr[i]._w)||
					(arr[j]._w == arr[i]._w&&arr[j]._h==arr[i]._h)
					){
					dp[i] = max(dp[i], dp[j] + 1);
				}
				
			}
		}
		int res = 0;
		for (int i = 0; i < n; ++i){
			res = max(res, dp[i]);
		}
		cout << res << endl;
	}
	return 0;
}