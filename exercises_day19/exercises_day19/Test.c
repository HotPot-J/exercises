#define _CRT_SECURE_NO_WARNINGS 1
/*问题描述
回文串，是一种特殊的字符串，它从左往右读和从右往左读是一样的。小龙龙认为回文串才是完美的。现在给你一个串，它不一定是回文的，请你计算最少的交换次数使得该串变成一个完美的回文串。
交换的定义是：交换两个相邻的字符
例如mamad
第一次交换 ad : mamda
第二次交换 md : madma
第三次交换 ma : madam(回文！完美！)
输入格式
第一行是一个整数N，表示接下来的字符串的长度(N <= 8000)
第二行是一个字符串，长度为N.只包含小写字母
输出格式
如果可能，输出最少的交换次数。
否则输出Impossible
样例输入
5
mamad
样例输出
3
*/
#include<stdio.h>
#include<stdlib.h>
//不构成回文的两个中情况： N为奇数 有两个字符单独出现 则不构成
//                         N为偶数 有一个字符单独出现 则不构成 
int main(){
	int N = 0;
	int n = 0;
	int alone = 0; //记录单个字符的个数
	int ok = 1, time = 0 ;
	char tmp = '0';
	char* arr = NULL;
	int i = 0, j = 0, k = 0;
	scanf("%d", &N);
	n = N-1;
	arr = (char *)malloc((N + 1)*sizeof(char));
	scanf("%s", arr);
	for (i = 0; i < n; i++){ //从左到右
		for (j = n; j>=i; j--){//从右到左
			if (i == j){ // 没匹配上
				alone++;
				if (N % 2 == 0 || alone >= 2){ //在没匹配上的情况下 如果N其为偶数 或 单个数个数大于等于2则无法构成
					ok = 0;
					break;
				}
				else{
					time += (N / 2 - i); //单个字符移到中间所需要的步数
					break;
				}
			}
			if (arr[i] == arr[j]){ // 匹配上了
				for (k = j; k <n; k++){
					tmp=arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = tmp;
					time++;
				}
				n--;//每次将j调整好一次就不用管该字母了
				break;
			}

		}
		if (!ok){
			break;
		}
	}
	if (!ok){
		printf("Impossible");
	}
	else{
		printf("%d", time);
	}
	free(arr);
	return 0;
}