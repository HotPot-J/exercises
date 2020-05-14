#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*
1357. ÿ�� n ���˿ʹ���
���������ھ��д��ۻ��ÿ�� n ���˿ͻ�õ� discount ���ۿۡ�

��������һЩ��Ʒ���� i ����ƷΪ products[i] ��ÿ����Ʒ�ļ۸�Ϊ prices[i] ��

����ϵͳ��ͳ�ƹ˿͵���Ŀ��ÿ�� n ���˿ͽ���ʱ���ù˿͵��˵�������ۣ��ۿ�Ϊ discount ��Ҳ�������ԭ���˵�Ϊ x ����ôʵ�ʽ����� x - (discount * x) / 100 ����Ȼ��ϵͳ�����¿�ʼ������

�˿ͻṺ��һЩ��Ʒ�� product[i] �ǹ˿͹���ĵ� i ����Ʒ�� amount[i] �Ƕ�Ӧ�Ĺ��������Ʒ����Ŀ��

����ʵ�� Cashier �ࣺ

Cashier(int n, int discount, int[] products, int[] prices) ��ʼ��ʵ�����󣬲����ֱ�Ϊ����Ƶ�� n ���ۿ۴�С discount �����������Ʒ�б� products �����ǵļ۸� prices ��
double getBill(int[] product, int[] amount) �����˵���ʵ�ʽ�����д��ۣ��뷵�ش��ۺ�Ľ���������ؽ�����׼������� 10^-5 ���ڶ���Ϊ��ȷ�����


ʾ�� 1��

����
["Cashier","getBill","getBill","getBill","getBill","getBill","getBill","getBill"]
[[3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]],[[1,2],[1,2]],[[3,7],[10,10]],[[1,2,3,4,5,6,7],[1,1,1,1,1,1,1]],[[4],[10]],[[7,3],[10,10]],[[7,5,3,1,6,4,2],[10,10,10,9,9,9,7]],[[2,3,5],[5,3,2]]]
���
[null,500.0,4000.0,800.0,4000.0,4000.0,7350.0,2500.0]
����
Cashier cashier = new Cashier(3,50,[1,2,3,4,5,6,7],[100,200,300,400,300,200,100]);
cashier.getBill([1,2],[1,2]);                        // ���� 500.0, �˵����Ϊ = 1 * 100 + 2 * 200 = 500.
cashier.getBill([3,7],[10,10]);                      // ���� 4000.0
cashier.getBill([1,2,3,4,5,6,7],[1,1,1,1,1,1,1]);    // ���� 800.0 ���˵�ԭ��Ϊ 1600.0 �������ڸù˿��ǵ���λ�˿ͣ������õ� 50% ���ۿۣ�����ʵ�ʽ��Ϊ 1600 - 1600 * (50 / 100) = 800 ��
cashier.getBill([4],[10]);                           // ���� 4000.0
cashier.getBill([7,3],[10,10]);                      // ���� 4000.0
cashier.getBill([7,5,3,1,6,4,2],[10,10,10,9,9,9,7]); // ���� 7350.0 ���˵�ԭ��Ϊ 14700.0 ��������ϵͳ�����ٴδﵽ�����ù˿ͽ��õ� 50% ���ۿۣ�ʵ�ʽ��Ϊ 7350.0 ��
cashier.getBill([2,3,5],[5,3,2]);                    // ���� 2500.0
*/

//˼·����ϣ

class Cashier {
private:
	unordered_map<int, int> price;
	int n, discount;
	int custom_id;

public:
	Cashier(int _n, int _d, vector<int>& products, vector<int>& prices) : n(_n), discount(_d), custom_id(0) {
		for (int i = 0; i < products.size(); ++i) {
			price[products[i]] = prices[i];
		}
	}

	double getBill(vector<int> product, vector<int> amount) {
		++custom_id;
		double payment = 0;
		for (int i = 0; i < product.size(); ++i) {
			payment += price[product[i]] * amount[i];
		}
		if (custom_id % n == 0) {
			payment -= payment * discount / 100;
		}
		return payment;
	}
};

