#define _CRT_SECURE_NO_WARNINGS 1

/*
1���������ڵ�����ת����
	������������ڣ���������һ��ĵڼ���
	����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
����������
	�������У��꣬�£���
	�ɹ���������������ĵڼ���
	ʧ��:����-1
*/

#include<iostream>
using namespace std;

class Date{
public:
	Date(int year ,int mouth,int day)
	:_year(year)
	, _mouth(mouth)
	, _day(day)
	{}

	int fun(){
		int res = 0;
		int arr[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,31};
		if ((_year % 4 == 0 && _year % 100 != 0) || _year % 400 == 0){
			arr[2] = 29;
		}
		if (_year <= 0 || _mouth<0||_mouth>12 || _day <= 0||_day>arr[_mouth]){
			return -1;
		}
		for (int i = 1; i < _mouth; ++i){
			res += arr[i];
		}
		res += _day;
		return res;
	}
private:
	int _year;
	int _mouth;
	int _day;
};
//int main(){
//	int year = 0, mouth = 0, day = 0;
//	while (cin >> year >> mouth >> day){
//		Date d(year, mouth, day);
//		cout << d.fun() << endl;
//	}
//	return 0;
//}

/*
2�����˵Ĵ���
	һ������������n����ÿ�������涼��һ������(ӵ����ͬ����������������)��
���һ�����������˵ĵ��ҽ���������ĺ���ĺʹ���������ĺ���Ļ���
������������������ĺ�����(1��1��2��3)��������Ӿ������˵ģ���Ϊ1+1+2+3>1*1*2*3
������ʵ��Ӵ������Ƴ�һЩ�򣨿����Ƴ�0�������Ǳ��Ƴ��꣩��Ҫʹ�Ƴ���Ĵ�����
���˵ġ����������̼���һ������Ի�ö����ֲ�ͬ�����˵Ĵ��ӡ�

����������
	��һ������һ��������n(n<=1000)
	�ڶ���Ϊn��������
���������
	������Բ��������˵Ĵ�����
���ӣ�
	3
	1 1 1

	�����
		2
*/

/*
˼·�����ݷ� 
*/

//����һ��ʹ����_add��_mul����ȥ��¼��ȡ�Ľ����Ȼ��ÿ�ν�����洢��vv�У������ҽ�VV�е�����ת��Ϊstring��ʹ��
//setȥ��  ʱ�临�Ӷȴ�󳬳�  �޷�AC  ������˼·û���⣬���Ǿ����ʵ�ֹ��ڸ��ӣ�����ǿ����setȥ�����ַ�����Ҳ�вο���ֵ �����ô��� ��
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
bool check(vector<int>& add,vector<int>mul){
	int _add = 0;
	int _mul = 1;
	for (size_t i = 0; i < add.size(); ++i){
		_add += add[i];
	}
	for (size_t i = 0; i<mul.size(); ++i){
		_mul *= mul[i];
	}
	if (_add>_mul){
		return true;
	}
	return false;
}

void dfs(vector<vector<int>>&vv,vector<int>& map,vector<int>_add,vector<int>_mul,int depth){
	if (depth == map.size()-1){
		//����ȫ���ó�
		if (check(_add,_mul)){
			//�������vv��
			vv.push_back(_add);
		}
		return;
	}
	_add[depth] = 0; //�Ӽӷ��������ó�
	_mul[depth] = 1;//�ӳ˷��������ó�
	dfs(vv,map, _add,_mul, depth + 1);
	//����
	_add[depth] = map[depth];
	_mul[depth] = map[depth];
	dfs(vv,map, _add,_mul, depth + 1);
}
//int main(){
//	int n = 0, a = 0;
//	while (cin >> n){
//		vector<int> map;
//		vector<int> _add;
//		vector<int> _mul;
//		vector<vector<int>> vv;
//		for (int i = 0; i < n; ++i){
//			cin >> a;
//			map.push_back(a);
//		}
//		_add = map;
//		_mul = map;
//		dfs(vv, map, _add, _mul, 0);
//		//ȥ��,��VV����ͬ������ȥ����
//		vector<string> ss;
//		for (size_t i = 0; i < vv.size(); ++i){
//			sort(vv[i].begin(), vv[i].end());
//			string s;
//			for (size_t j = 0; j < vv[i].size(); ++j){
//				s += to_string(vv[i][j]);
//			}
//			ss.push_back(s);
//		}
//		set<string> t(ss.begin(), ss.end());
//		cout << t.size() << endl;
//	}
//	return 0;
//}


/*
�������� ��������һ��ʱ�临�Ӷȹ��ߣ���μ���ʱ�临�Ӷ���?
	��ԭʼ���鰴�յ�����ǰ���򣬱��ڼ�֦����
	��map[0]��ʼ �õ������ ��Ȼ��ȥ��������������������ȫ���������  �����Ժ������ �ִ�map[1]��ʼ
	�Դ�����
 ������Ŀ��	���һ����ǰa+b>a*b �������� res++  ���Խ�����һ���ĵݹ�
			�����������һ������Ϊ1 ��Ȼ�ӷ�ʽ�ӻ��� �̷�ʽ�Ӳ��䣬�ݹ���ȥ�����ҵ���ȷ�𰸣����Խ�����һ���ݹ�
			��������Ȳ����㸣��Ҫ��+ < *������һ�������ֲ�Ϊ1 ����������Ϊ�������У������ݹ���ȥһ���˷�Խ��Խ��
			,�϶�û����ȷ�𰸣����м�֦
 
 */
void dfs(vector<int>&map, int depth, int& res,int _add,int _mul){
	size_t len = map.size();
	for (size_t i = depth; i < len; ++i){
		_add += map[i];
		_mul *= map[i];
		if (_add>_mul){
			++res;
			dfs(map, i + 1, res, _add, _mul);
		}
		else if (map[i] == 1){
			dfs(map, i + 1, res, _add, _mul);
		}
		else{
			break;  //���м�֦
		}
		//����
		_add -= map[i];
		_mul /= map[i];
		//ȥ�� �����һ�����ֺ͵�ǰ����һ�� ��û��Ҫ�����ж�
		while (i < len - 1 && map[i] == map[i + 1]){
			++i;
		}
	}
}
//int main(){
//	int n = 0, a = 0;
//  while (cin >> n){
//	 vector<int>map;
//	 int res = 0;
//	 for (int i = 0; i < n; ++i){
//		cin >> a;
//		map.push_back(a);
//	 }
//	 sort(map.begin(), map.end());
//	 dfs(map, 0, res, 0, 1);
//	 cout << res << endl;
//  }
//	return 0;
//}

