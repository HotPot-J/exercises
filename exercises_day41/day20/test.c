#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*问题描述
　　输入两个整数a和b，输出这两个整数的和。a和b都不超过100位。
算法描述
　　由于a和b都比较大，所以不能直接使用语言中的标准数据类型来存储。对于这种问题，一般使用数组来处理。
　　定义一个数组A，A[0]用于存储a的个位，A[1]用于存储a的十位，依此类推。同样可以用一个数组B来存储b。
　　计算c = a + b的时候，首先将A[0]与B[0]相加，如果有进位产生，则把进位（即和的十位数）存入r，把和的个位数存入C[0]，即C[0]等于(A[0]+B[0])%10。然后计算A[1]与B[1]相加，这时还应将低位进上来的值r也加起来，即C[1]应该是A[1]、B[1]和r三个数的和．如果又有进位产生，则仍可将新的进位存入到r中，和的个位存到C[1]中。依此类推，即可求出C的所有位。
　　最后将C输出即可。
输入格式
　　输入包括两行，第一行为一个非负整数a，第二行为一个非负整数b。两个整数都不超过100位，两数的最高位都不是0。
输出格式
　　输出一行，表示a + b的值。
样例输入
20100122201001221234567890
2010012220100122
*/
void fun(char* p){
	char* top = p;
	char* tail = strlen(p)-1+p;
	char tmp = '0';
	while (top < tail){
		tmp = *tail;
		*tail = *top;
		*top = tmp;
		top++;
		tail--;
	}
}
void Add(char *a,char* b){
	int i = 0, flag = 0, csize = 0;
	char c[101] = { 0 };
	int asize = strlen(a);
	int bsize = strlen(b);
	int tmp = asize >= bsize ? bsize : asize;
	fun(a);
	fun(b);
	for (i = 0; i<tmp;i++){
		c[i] = (a[i]-'0' + b[i]-'0' + flag) % 10+'0';
		flag = (a[i]-'0' + b[i]-'0' + flag) / 10;
	}
	if (asize>bsize){
		for (i; i < asize; i++){
			c[i] = (a[i]-'0'+ flag) % 10+'0';
			flag = (a[i]-'0'+ flag) / 10;
		}
	}
	else{
		for (i; i < bsize; i++){
			c[i] = (b[i]-'0' + flag) % 10+'0';
			flag = (b[i]-'0' + flag) / 10+'0';
		}
	}
	fun(c);
	printf("%s", c);
}
int main(){
	char a[101] = { '0' };
	char b[101] = { '0' };
	scanf("%s", a);
	scanf("%s", b);
	Add(a, b);
	return 0;
}
