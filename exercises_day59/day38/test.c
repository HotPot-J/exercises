#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
��������һλ�ܰ��ļҳ�����Ҫ����ĺ�����һЩС���ɡ����ǣ�ÿ���������ֻ�ܸ�һ����ɡ���ÿ������ i ������һ��θ��ֵ
?gi ���������ú���������θ�ڵı��ɵ���С�ߴ磻����ÿ����� j ������һ���ߴ� sj?����� sj >= gi?�����ǿ��Խ����
 ���� j ��������� i ��������ӻ�õ����㡣���Ŀ���Ǿ���������Խ�������ĺ��ӣ��������������ֵ��
ע�⣺
����Լ���θ��ֵΪ����
һ��С�������ֻ��ӵ��һ����ɡ�
ʾ��?1:
����: [1,2,3], [1,1]
���: 1
����:
�����������Ӻ�����С���ɣ�3�����ӵ�θ��ֵ�ֱ��ǣ�1,2,3��
��Ȼ��������С���ɣ��������ǵĳߴ綼��1����ֻ����θ��ֵ��1�ĺ������㡣
������Ӧ�����1��
ʾ��?2:
����: [1,2], [1,2,3]
���: 2
����:
�����������Ӻ�����С���ɣ�2�����ӵ�θ��ֵ�ֱ���1,2��
��ӵ�еı��������ͳߴ綼���������к������㡣
������Ӧ�����2.
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/assign-cookies
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//˼·������ ̰���㷨������С�ı��ɾ�������С�ĺ���
int cmp(const void*a, const void*b){
	return *(int*)a > *(int*)b;
}
int findContentChildren(int* g, int gSize, int* s, int sSize){
	int i = 0, j = 0;
	qsort(g,gSize,sizeof(int),cmp);
	qsort(s, sSize, sizeof(int), cmp);
	while (i < gSize&&j < sSize){
		if (g[i] <= s[j]){
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	return i;
}
int main(){
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 1 };
	int size1 = sizeof(a) / sizeof(a[0]);
	int size2 = sizeof(b) / sizeof(b[0]);
	findContentChildren(a, size1, b, size2);
	return 0;
}