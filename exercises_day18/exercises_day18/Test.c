#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述
　　平面上有两个矩形，它们的边平行于直角坐标系的X轴或Y轴。对于每个矩形，我们给出它的一对相对顶点的坐标，请你编程算出两个矩形的交的面积。
  输入格式
  　　输入仅包含两行，每行描述一个矩形。
	　　在每行中，给出矩形的一对相对顶点的坐标，每个点的坐标都用两个绝对值不超过10^7的实数表示。
	  输出格式
	  　　输出仅包含一个实数，为交的面积，保留到小数后两位。
		样例输入
		1 1 3 3
		2 2 4 4
		样例输出
		1.00
*/
#include<stdio.h>
double max1(double a, double b){
	return a > b ? a : b;
}
double min1(double a, double b){
	return a < b ? a : b;
}
void judge(double arr[][4]){//判断两个矩形是否相交 其推导过程保存在该文件下的画图板文件中
	double a = 0, b = 0, c = 0, d = 0;
	double Ax = (arr[0][2] - arr[0][0]) / 2 + arr[0][0];
	double Ay = (arr[0][3] - arr[0][1]) / 2 + arr[0][1];
	double Bx = (arr[1][2] - arr[1][0]) / 2 + arr[1][0];
	double By = (arr[1][3] - arr[1][1]) / 2 + arr[1][1];
	double tmp1 = Bx - Ax;//两重心横向距离
	double tmp2 = By - Ay;//两重心纵向距离
	double tmp3 = (arr[0][2] - arr[0][0]) / 2 + (arr[1][2] - arr[1][0]) / 2;
	double tmp4 = (arr[0][3] - arr[0][1]) / 2 + (arr[1][3] - arr[1][1]) / 2;
	if (tmp1 < tmp3&&tmp2 < tmp4){//相交
		a = max1(arr[0][0], arr[1][0]);
		b = max1(arr[0][1], arr[1][1]);
		c = min1(arr[0][2], arr[1][2]);
		d = min1(arr[0][3], arr[1][3]);
		printf("%0.2f", (a - c)*(b - d));
	}
	else{//不相交
		printf("0.00");
	}
}
int main(){
	double arr[2][4] = { 0.00 }; //保存左下右上两个坐标 
	double arr1[2][4] = { 0.00 };//保存左上右下两个坐标
	int i = 0, j = 0;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 4; j++){
			scanf("%lf", &arr[i][j]);
		}
	}
	judge(arr);
	return 0;
}
//用键入double类型数据使用%lf  flout类型用%f