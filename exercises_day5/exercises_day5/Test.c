#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
���⣺��־ͳ��

С��ά����һ������Ա��̳���������ռ���һ��"����"��־����־����N�С�����ÿһ�еĸ�ʽ�ǣ�

ts id

��ʾ��tsʱ�̱��id�������յ�һ��"��"��

����С����ͳ������Щ����������"����"�����һ��������������һ������ΪD��ʱ������յ�������K���ޣ�С������Ϊ�����������"����"��

������˵���������ĳ��ʱ��T���������[T, T+D)���ʱ����(ע��������ҿ�����)�յ�������K���ޣ�����������"����"��

������־���������С��ͳ�Ƴ���������"����"�����ӱ�š�

�������ʽ��
��һ�а�����������N��D��K��
����N��ÿ��һ����־��������������ts��id��

����50%�����ݣ�1 <= K <= N <= 1000
����100%�����ݣ�1 <= K <= N <= 100000 0 <= ts <= 100000 0 <= id <= 100000

�������ʽ��
����С�����˳���������id��ÿ��idһ�С�

������������
7 10 2
0 1
0 10
10 10
10 1
9 1
100 3
100 3

�����������
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
//			for (j = 0; j<flag; j++){  //�ж�p���Ƿ��Ѿ��и�id  �����flag1��0 �����ٽ���id������p��
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
2.�ַ�����ݹ鷽��
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