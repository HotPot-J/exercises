#define _CRT_SECURE_NO_WARNINGS 1
/*
��������
����ƽ�������������Σ����ǵı�ƽ����ֱ������ϵ��X���Y�ᡣ����ÿ�����Σ����Ǹ�������һ����Զ�������꣬����������������εĽ��������
  �����ʽ
  ����������������У�ÿ������һ�����Ρ�
	������ÿ���У��������ε�һ����Զ�������꣬ÿ��������궼����������ֵ������10^7��ʵ����ʾ��
	  �����ʽ
	  �������������һ��ʵ����Ϊ���������������С������λ��
		��������
		1 1 3 3
		2 2 4 4
		�������
		1.00
*/
#include<stdio.h>
double max1(double a, double b){
	return a > b ? a : b;
}
double min1(double a, double b){
	return a < b ? a : b;
}
void judge(double arr[][4]){//�ж����������Ƿ��ཻ ���Ƶ����̱����ڸ��ļ��µĻ�ͼ���ļ���
	double a = 0, b = 0, c = 0, d = 0;
	double Ax = (arr[0][2] - arr[0][0]) / 2 + arr[0][0];
	double Ay = (arr[0][3] - arr[0][1]) / 2 + arr[0][1];
	double Bx = (arr[1][2] - arr[1][0]) / 2 + arr[1][0];
	double By = (arr[1][3] - arr[1][1]) / 2 + arr[1][1];
	double tmp1 = Bx - Ax;//�����ĺ������
	double tmp2 = By - Ay;//�������������
	double tmp3 = (arr[0][2] - arr[0][0]) / 2 + (arr[1][2] - arr[1][0]) / 2;
	double tmp4 = (arr[0][3] - arr[0][1]) / 2 + (arr[1][3] - arr[1][1]) / 2;
	if (tmp1 < tmp3&&tmp2 < tmp4){//�ཻ
		a = max1(arr[0][0], arr[1][0]);
		b = max1(arr[0][1], arr[1][1]);
		c = min1(arr[0][2], arr[1][2]);
		d = min1(arr[0][3], arr[1][3]);
		printf("%0.2f", (a - c)*(b - d));
	}
	else{//���ཻ
		printf("0.00");
	}
}
int main(){
	double arr[2][4] = { 0.00 }; //�������������������� 
	double arr1[2][4] = { 0.00 };//��������������������
	int i = 0, j = 0;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 4; j++){
			scanf("%lf", &arr[i][j]);
		}
	}
	judge(arr);
	return 0;
}
//�ü���double��������ʹ��%lf  flout������%f