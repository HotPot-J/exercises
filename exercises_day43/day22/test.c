#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

/*
��������
��֪һ��������N���ʴ�1~N����ѡ�������������ǵ���С������������Ϊ���١�

�����ʽ
����һ��������N��

�����ʽ
���һ����������ʾ���ҵ�����С��������
��������
9
�������
504
���ݹ�ģ��Լ��
1 <= N <= 106��
*/

//���ǰ�����ѧ��ʽ��ʵ�� ����ʱ�临�Ӷ�̫�� �޷�ͨ������ ����˳��ʵ���˵ݹ�շת��������Լ�� ������������С������

/*�󼸸���Ȼ������С�������������������������������С�����������������С�������������������С��������
��������ȥ��ֱ�����һ��Ϊֹ��������õ��Ǹ���С����������������ļ���������С��������
*/
int CommonDivisor(int a, int b){//շת����������Լ��
	if (a%b == 0){
		return b;
	}
	else{
		return CommonDivisor(b, a%b);
	}
}
int MinCommonMultiple(int a, int b){
	int max = a >= b ? a : b;
	int min = a < b ? a : b;
	if (max%min == 0){
		return max;
	}
	else{
		return max*min / CommonDivisor(max, min);//a��b����С������ = a*b / a��b�����Լ��   
	}
}
void MaxMinCommonMultiple(int n){//�����С������
	int i = 0, j = 0, tmp = 0;
	int ret = 0;
	for (i = 1; i <= n-2; i++){
		j = i + 1;
		for (j; j <= n - 1; j++){
			 tmp = MinCommonMultiple(i, j);
			 tmp = MinCommonMultiple(tmp, j + 1);
			 if (tmp > ret){
				 ret = tmp;
			 }
		}
	}
	printf("%d", ret);
}

//̰���㷨ʵ�֣�
/*
1.��������������������� ��ż���ż��ż
  �ٵ�����ż������ʱ   ��nΪ���� ������������n n-1 n-2  ����n �� n-2û��2������� ��ʹ����һ������������3 ������
  �������ֵı仯��Χ������3 ��������������֮�䲻���ڹ�Լ��3  
  �ڵ���ż��ż�����ʱ   ��nΪż��  �����n-2��Ϊn-3���ֱ����ż�������� ��ʱ�������С������  
  ���� ��n�к�������3ʱ ��n-3Ҳ�Ậ��3������� �ᵼ�¹�Լ����С����   ���������Ҫ����Ϊn-1 n-2 n-3�ͱ�Ϊ��ż������
*/

//unsigned long long�����ʹ�� %llu   
unsigned long long MaxMinCommonMultiple1(unsigned long long n){
	if (n % 2 != 0){ //nΪ���� ������ż��
		return n*(n - 1)*(n - 2);
	}
	else if (n % 3 != 0){  //nΪż�� ���ǲ���������3
		return n*(n - 1)*(n - 3);
	}
	else{  //nΪż�� ��������3
		return (n - 1)*(n - 2)*(n - 3);
	}
}
int main(){
	unsigned long long n = 0;
	scanf("%d", &n);
	printf("%llu", MaxMinCommonMultiple1(n));
	return 0;
}