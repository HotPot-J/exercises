#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*
问题描述
　　给定三个整数 a, b, c，如果一个整数既不是 a 的整数倍也不是 b 的整数倍还不是 c 的整数倍，则这个数称为反倍数。
  　请问在 1 至 n 中有多少个反倍数。
	输入格式
	　　输入的第一行包含一个整数 n。
	  　　第二行包含三个整数 a, b, c，相邻两个数之间用一个空格分隔。
		输出格式
		　　输出一行包含一个整数，表示答案。
		  样例输入
		  30
		  2 3 6
		  样例输出
		  10
		  样例说明
		  　　以下这些数满足要求：1, 5, 7, 11, 13, 17, 19, 23, 25, 29。
			评测用例规模与约定
			　　对于 40% 的评测用例，1 <= n <= 10000。
			  　对于 80% 的评测用例，1 <= n <= 100000。
				对于所有评测用例，1 <= n <= 1000000，1 <= a <= n，1 <= b <= n，1 <= c <= n。
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
问题描述
　　给定一个单词，请使用凯撒密码将这个单词加密。
  　凯撒密码是一种替换加密的技术，单词中的所有字母都在字母表上向后偏移3位后被替换成密文。即a变为d，b变为e，...，
	w变为z，x变为a，y变为b，z变为c。
	 例如，lanqiao会变成odqtldr。
	  输入格式
	  　　输入一行，包含一个单词，单词中只包含小写英文字母。
		输出格式
		　　输出一行，表示加密后的密文。
		  样例输入
		  lanqiao
		  样例输出
		  odqtldr
		  评测用例规模与约定
		  　对于所有评测用例，单词中的字母个数不超过100。
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
问题描述
　　对于一个 n 行 m 列的表格，我们可以使用螺旋的方式给表格依次填上正整数，我们称填好的表格为一个螺旋矩阵。
  　例如，一个 4 行 5 列的螺旋矩阵如下：
	　　1 2 3 4 5
	  　14 15 16 17 6
		13 20 19 18 7
		12 11 10 9 8
			输入格式
			　　输入的第一行包含两个整数 n, m，分别表示螺旋矩阵的行数和列数。
			  　　第二行包含两个整数 r, c，表示要求的行号和列号。
				输出格式
				　　输出一个整数，表示螺旋矩阵中第 r 行第 c 列的元素的值。
				  样例输入
				  4 5
				  2 2
				  样例输出
				  15
				  评测用例规模与约定
				  　对于 30% 的评测用例，2 <= n, m <= 20。
					对于 70% 的评测用例，2 <= n, m <= 100。
					对于所有评测用例，2 <= n, m <= 1000，1 <= r <= n，1 <= c <= m。
*/

int arr[1000][1000] = { 0 };
void fun(int m,int n){
	int up = 0, down = m - 1, l = 0, r = n - 1;
	int flag = 0, i = 0, j = 0;
	while (l<=r||up<=down){
      //从左到右
		i = l; j = r;
		for (i; i <= j; ++i){
			arr[up][i] = ++flag;
		}
		++up;
		if (up>down){
			break;
		}
	 //从上到下
		i = up; j = down;
		for (i; i <= j; ++i){
			arr[i][r] = ++flag;
		}
		--r;
		if (r < l){
			break;
		}
	 //从右到左
		i = r; j = l;
		for (i; i >= j; --i){
			arr[down][i] = ++flag;
		}
		--down;
		if (down < up){
			break;
		}
	 //从下到上
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
问题描述
　　如果一个序列的奇数项都比前一项大，偶数项都比前一项小，则称为一个摆动序列。即 a[2i]<a[2i-1], a[2i+1]>a[2i]。
  　　小明想知道，长度为 m，每个数都是 1 到 n 之间的正整数的摆动序列一共有多少个。
	输入格式
	　　输入一行包含两个整数 m，n。
	  输出格式
	  　　输出一个整数，表示答案。答案可能很大，请输出答案除以10000的余数。
		样例输入
		3 4
		样例输出
		14
		样例说明
		　　以下是符合要求的摆动序列：
		  　　2 1 2
			　2 1 3
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
			评测用例规模与约定
	对于 20% 的评测用例，1 <= n, m <= 5；
	对于 50% 的评测用例，1 <= n, m <= 10；
	对于 80% 的评测用例，1 <= n, m <= 100；
	对于所有评测用例，1 <= n, m <= 1000。
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
问题描述
　　小明和朋友们一起去郊外植树，他们带了一些在自己实验室精心研究出的小树苗。
  　　小明和朋友们一共有 n 个人，他们经过精心挑选，在一块空地上每个人挑选了一个适合植树的位置，总共 n 个。他们准备把自己带的树苗都植下去。
	　　然而，他们遇到了一个困难：有的树苗比较大，而有的位置挨太近，导致两棵树植下去后会撞在一起。
	  　　他们将树看成一个圆，圆心在他们找的位置上。如果两棵树对应的圆相交，这两棵树就不适合同时植下（相切不受影响），称为两棵树冲突。
		　　小明和朋友们决定先合计合计，只将其中的一部分树植下去，保证没有互相冲突的树。他们同时希望这些树所能覆盖的面积和（圆面积和）最大。
		  输入格式
		  　　输入的第一行包含一个整数 n ，表示人数，即准备植树的位置数。
			　　接下来 n 行，每行三个整数 x, y, r，表示一棵树在空地上的横、纵坐标和半径。
			  输出格式
			  　　输出一行包含一个整数，表示在不冲突下可以植树的面积和。由于每棵树的面积都是圆周率的整数倍，请输出答案除以圆周率后的值（应当是一个整数）。
				6
				1 1 2
				1 4 2
				1 7 2
				4 1 2
				4 4 2
				4 7 2
				样例输出
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
