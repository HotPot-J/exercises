#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
标题：日志统计

小明维护着一个程序员论坛。现在他收集了一份"点赞"日志，日志共有N行。其中每一行的格式是：

ts id

表示在ts时刻编号id的帖子收到一个"赞"。

现在小明想统计有哪些帖子曾经是"热帖"。如果一个帖子曾在任意一个长度为D的时间段内收到不少于K个赞，小明就认为这个帖子曾是"热帖"。

具体来说，如果存在某个时刻T满足该帖在[T, T+D)这段时间内(注意是左闭右开区间)收到不少于K个赞，该帖就曾是"热帖"。

给定日志，请你帮助小明统计出所有曾是"热帖"的帖子编号。

【输入格式】
第一行包含三个整数N、D和K。
以下N行每行一条日志，包含两个整数ts和id。

对于50%的数据，1 <= K <= N <= 1000
对于100%的数据，1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000

【输出格式】
按从小到大的顺序输出热帖id。每个id一行。

【输入样例】
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3

【输出样例】
1
3
*/
//void fun(int *arr, int N,int D, int K){
//	int *p=(int *)malloc(N*sizeof(int)); 
//	int flag = 0;
//	int i = 0; int j = 0;
//	int flag1 = 1;
//	for (i = 0; i<(2*N); i += 2){
//		flag1 = 1;
//		if (arr[i] >= K&& arr[i+1]<D){
//			for (j = 0; j<flag; j++){  //判断p中是否已经有该id  如果有flag1置0 则不用再将该id保存在p中
//				if (p[j] == arr[i + 1]){
//					flag1 = 0;
//				}
//			}
//			while (flag1){
//				p[flag] = arr[i + 1];
//				flag++;
//				flag1--;
//			}
//		}
//	}
//	for (j = 0; j<flag; j++){
//		printf("%d\n", p[j]);
//	}
//	free(p);
//}
//int main(){
//	int N = 0; int D = 0; int K = 0;
//	int i = 0;
//	int *arr = NULL;
//	int two = 2;
//	int n = 0;
//	scanf("%d%d%d", &N, &D, &K);
//	n = N;
//	arr = (int *)malloc(2 * 10 * sizeof(int));
//	while (N--){
//		for (i; i<two; i++){
//			scanf("%d", &arr[i]);
//		}
//		two += 2;
//	}
//	fun(arr, n,D, K);
//	free(arr);
//	return 0;
//}


/*
2.字符逆序递归方法
*/
char *reverse_string(char *str){
	int len = strlen(str);

	if (len <= 1){
		return NULL;
	}

	else{

		char temp = str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';
		reverse_string(str + 1);
		str[len - 1] = temp;

	}
	return  str;

}
int main(){
	char arr[100];
	gets(arr);
	reverse_string(arr);
	printf("%s", &arr);
	return 0;
}