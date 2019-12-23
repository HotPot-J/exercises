#define _CRT_SECURE_NO_WARNINGS 1
/*
问题描述
给定圆的半径r，求圆的面积。
输入格式
输入包含一个整数r，表示圆的半径。
输出格式
输出一行，包含一个实数，四舍五入保留小数点后7位，表示圆的面积。
说明：在本题中，输入是一个整数，但是输出是一个实数。

对于实数输出的问题，请一定看清楚实数输出的要求，
比如本题中要求保留小数点后7位，则你的程序必须严格的输出7位小数，
输出过多或者过少的小数位数都是不行的，都会被认为错误。

实数输出的问题如果没有特别说明，舍入都是按四舍五入进行。

样例输入
4
样例输出
50.2654825
数据规模与约定
1 <= r <= 10000。
提示
本题对精度要求较高，请注意π的值应该取较精确的值。你可以使用常量来表示π，
比如PI=3.14159265358979323，也可以使用数学公式来求π，比如PI=atan(1.0)*4。
*/
//该题要求保留小数点后7位  以%0.1f %0.2f ......%0.7f 输出一个double类型的数据 则分别表示保留小数点后1 2 ......7位
//小数
#include<stdio.h>
#include<math.h>
#define PI 3.14159265358979323
int main(){
	int r = 0;
	scanf("%d", &r);
	printf("%0.7f", PI*(pow((double)r, 2)));
	return 0;
}