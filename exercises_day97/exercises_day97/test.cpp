#define _CRT_SECURE_NO_WARNINGS 1

/*
1、最近公共祖先
有一个无穷大的满二叉树，其节点按根节点一层一层的从左往右依次编号，根节点编号为1.现有两个
结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a b为给定结点的编号。请返回a b的最近公共祖先的编号。注意这里的结点本身也可以是
祖先
例子：
	2 3
返回：1
*/

/*思路 递归：根据满二叉树的性质 其编号是规律的从左至右  那么当编号为 
(因为根节点序号为1所以其推导祖先结点的公式一致) 
1.偶数则为左子树寻找祖先结点的公式: x/2  
2.奇数则为右子树寻找祖先结点的公式: x/2
3.较小的有可能是祖先结点，若不是则较大的向上寻找 依次递归下去
*/

#include<iostream>
using namespace std;
class LCA {
public:
	int getLCA(int a, int b) {
		int _min = a < b ? a : b;
		int _max = a>b ? a : b;
		if (a == b){
			return a;
		}
		return getLCA(_min, _max / 2);
	}
};

//int main(){
//	lca a;
//	a.getlca(6, 7);
//	return 0;
//}


/*
2、最大连续bit数
功能:求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制位00000011中，最大连续
2个1
输入：一个byte型的数字
输出：无
返回：对应二进制中1的最大连续数
*/

#include<iostream>
#include<string>
#include <algorithm>
using namespace std;
int main(){
	int a = 0;
	int max = 0;
	string s;
	while (cin >> a){
		max = 0;
		s.clear();
		while (a){
			s.push_back(a % 2);
			a /= 2;
		}
		reverse(s.begin(), s.end());
		for (size_t i = 0; i < s.size(); ++i){
			int tmp = 0;
			while (i < s.size() && s[i] == 1){
				++tmp;
				++i;
			}
			if (tmp>max){
				max = tmp;
			}
		}
		cout << max << endl;
	}
	return 0;
}