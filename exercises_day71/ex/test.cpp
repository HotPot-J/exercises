#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
��������
���������������� a, b, c�����һ�������Ȳ��� a ��������Ҳ���� b �������������� c �������������������Ϊ��������
  �������� 1 �� n ���ж��ٸ���������
	�����ʽ
	��������ĵ�һ�а���һ������ n��
	  �����ڶ��а����������� a, b, c������������֮����һ���ո�ָ���
		�����ʽ
		�������һ�а���һ����������ʾ�𰸡�
		  ��������
		  30
		  2 3 6
		  �������
		  10
		  ����˵��
		  ����������Щ������Ҫ��1, 5, 7, 11, 13, 17, 19, 23, 25, 29��
			����������ģ��Լ��
			�������� 40% ������������1 <= n <= 10000��
			  ������ 80% ������������1 <= n <= 100000��
				������������������1 <= n <= 1000000��1 <= a <= n��1 <= b <= n��1 <= c <= n��
*/

//int main(){
//	int a[3] = { 0 };
//	int n = 0;
//	int res=0;
//	cin >> n;
//	for (int i = 0; i <= 2; ++i){
//		cin >> a[i];
//	}
//	for (int i = 1; i <= n; ++i){
//		if (i%a[0] != 0 && i%a[1] != 0 && i%a[2] != 0){
//			++res;
//		}
//	}
//	cout << res;
//	return 0;
//}

/*
��������
��������һ�����ʣ���ʹ�ÿ������뽫������ʼ��ܡ�
  ������������һ���滻���ܵļ����������е�������ĸ������ĸ�������ƫ��3λ���滻�����ġ���a��Ϊd��b��Ϊe��...��
	w��Ϊz��x��Ϊa��y��Ϊb��z��Ϊc��
	 ���磬lanqiao����odqtldr��
	  �����ʽ
	  ��������һ�У�����һ�����ʣ�������ֻ����СдӢ����ĸ��
		�����ʽ
		�������һ�У���ʾ���ܺ�����ġ�
		  ��������
		  lanqiao
		  �������
		  odqtldr
		  ����������ģ��Լ��
		  �������������������������е���ĸ����������100��
*/

//int main(){
//	string s;
//	getline(cin, s);
//	for (int i = 0; i <= s.size(); ++i){
//		s[i] = (char)(97 + ((int)s[i] - 97 + 3) % 26);
//	}
//	cout << s;
//	return 0;
//}

/*
��������
��������һ�� n �� m �еı������ǿ���ʹ�������ķ�ʽ�������������������������ǳ���õı���Ϊһ����������
  �����磬һ�� 4 �� 5 �е������������£�
	����1 2 3 4 5
	  ��14 15 16 17 6
		13 20 19 18 7
		12 11 10 9 8
			�����ʽ
			��������ĵ�һ�а����������� n, m���ֱ��ʾ���������������������
			  �����ڶ��а����������� r, c����ʾҪ����кź��кš�
				�����ʽ
				�������һ����������ʾ���������е� r �е� c �е�Ԫ�ص�ֵ��
				  ��������
				  4 5
				  2 2
				  �������
				  15
				  ����������ģ��Լ��
				  ������ 30% ������������2 <= n, m <= 20��
					���� 70% ������������2 <= n, m <= 100��
					������������������2 <= n, m <= 1000��1 <= r <= n��1 <= c <= m��
*/

int arr[1000][1000] = { 0 };
void fun(int m,int n){
	int up = 0, down = m - 1, l = 0, r = n - 1;
	int flag = 0, i = 0, j = 0;
	while (l<=r||up<=down){
      //������
		i = l; j = r;
		for (i; i <= j; ++i){
			arr[up][i] = ++flag;
		}
		++up;
		if (up>down){
			break;
		}
	 //���ϵ���
		i = up; j = down;
		for (i; i <= j; ++i){
			arr[i][r] = ++flag;
		}
		--r;
		if (r < l){
			break;
		}
	 //���ҵ���
		i = r; j = l;
		for (i; i >= j; --i){
			arr[down][i] = ++flag;
		}
		--down;
		if (down < up){
			break;
		}
	 //���µ���
		i = down, j = up;
		for (i; i >= j; --i){
			arr[i][l] = ++flag;
		}
		++l;
		if (l>r){
			break;
		}
	}
}
//int main(){
//	int n = 0, m = 0, r = 0, c = 0;
//	cin >> n >> m;
//	cin >> r >> c;
//	fun( n, m);
//	printf("%d\n", arr[r - 1][c - 1]);
//	return 0;
//}

/*
��������
�������һ�����е��������ǰһ���ż�����ǰһ��С�����Ϊһ���ڶ����С��� a[2i]<a[2i-1], a[2i+1]>a[2i]��
  ����С����֪��������Ϊ m��ÿ�������� 1 �� n ֮����������İڶ�����һ���ж��ٸ���
	�����ʽ
	��������һ�а����������� m��n��
	  �����ʽ
	  �������һ����������ʾ�𰸡��𰸿��ܴܺ�������𰸳���10000��������
		��������
		3 4
		�������
		14
		����˵��
		���������Ƿ���Ҫ��İڶ����У�
		  ����2 1 2
			��2 1 3
			  2 1 4
			  3 1 2
			  3 1 3
			  3 1 4
			  3 2 3
			  3 2 4
			  4 1 2
			  4 1 3
			  4 1 4
			  4 2 3
			  4 2 4
			  4 3 4
			����������ģ��Լ��
	���� 20% ������������1 <= n, m <= 5��
	���� 50% ������������1 <= n, m <= 10��
	���� 80% ������������1 <= n, m <= 100��
	������������������1 <= n, m <= 1000��
*/
//#include <iostream>
//using namespace std;
//const int mod = 10000;
//int f[1010][1010];
//int ans;
//int main() {
//	int m, n;
//	cin >> m >> n;
//	for (int i = 1; i <= n; i++)
//		f[1][i] = n - i + 1;
//
//	for (int i = 2; i <= m; i++)
//	if ((i & 1) == 1)
//	{
//		for (int j = n; j >= 1; j--)
//			f[i][j] = (f[i - 1][j - 1] + f[i][j + 1]) % mod;
//	}
//	else
//	{
//		for (int j = 1; j <= n; j++)
//			f[i][j] = (f[i - 1][j + 1] + f[i][j - 1]) % mod;
//	}
//
//	if ((m & 1) == 1) ans = f[m][1];
//	else ans = f[m][n];
//	cout << ans << endl;
//	return 0;
//}

/*
��������
����С����������һ��ȥ����ֲ�������Ǵ���һЩ���Լ�ʵ���Ҿ����о�����С���硣
  ����С����������һ���� n ���ˣ����Ǿ���������ѡ����һ��յ���ÿ������ѡ��һ���ʺ�ֲ����λ�ã��ܹ� n ��������׼�����Լ��������綼ֲ��ȥ��
	����Ȼ��������������һ�����ѣ��е�����Ƚϴ󣬶��е�λ�ð�̫��������������ֲ��ȥ���ײ��һ��
	  �������ǽ�������һ��Բ��Բ���������ҵ�λ���ϡ������������Ӧ��Բ�ཻ�����������Ͳ��ʺ�ͬʱֲ�£����в���Ӱ�죩����Ϊ��������ͻ��
		����С���������Ǿ����Ⱥϼƺϼƣ�ֻ�����е�һ������ֲ��ȥ����֤û�л����ͻ����������ͬʱϣ����Щ�����ܸ��ǵ�����ͣ�Բ����ͣ����
		  �����ʽ
		  ��������ĵ�һ�а���һ������ n ����ʾ��������׼��ֲ����λ������
			���������� n �У�ÿ���������� x, y, r����ʾһ�����ڿյ��ϵĺᡢ������Ͱ뾶��
			  �����ʽ
			  �������һ�а���һ����������ʾ�ڲ���ͻ�¿���ֲ��������͡�����ÿ�������������Բ���ʵ���������������𰸳���Բ���ʺ��ֵ��Ӧ����һ����������
				6
				1 1 2
				1 4 2
				1 7 2
				4 1 2
				4 4 2
				4 7 2
				�������
				12
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000 + 10;
int n;
int x[MAXN], y[MAXN], r[MAXN];
double pi = acos(-1);
bool vis[MAXN];
int ans = 0;

bool cal(int i)
{
	for (int j = 0; j < n; j++)
	{
		if (i != j && vis[j])
		{
			int dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
			if (dis < (r[i] + r[j]) * (r[i] + r[j])){
				return false;
			}
		}
	}
	return true;
}

void dfs(int step, int sum)
{
	if (step == n)
	{
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			int tmp = r[i];
			if (!cal(i)) {
				r[i] = 0;
			}
			vis[i] = true;
			dfs(step + 1, sum + r[i] * r[i]);
			vis[i] = false;
			r[i] = tmp;
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	dfs(0, 0);
	printf("%d", ans);
	return 0;
}