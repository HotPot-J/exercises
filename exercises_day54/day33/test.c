#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*
����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ����ɵڶ����ַ���magazines������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��

(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼��)

ע�⣺

����Լ��������ַ�����ֻ����Сд��ĸ��

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/ransom-note
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//˼· ����ϣ�� ��magazine�е���ĸ�ù�ϣ�������� ����ransomNote�ж�����ĸ�����Ƿ�С�ڵ���magazine�е���ĸ����
int canConstruct(char * ransomNote, char * magazine){
	char* PR = ransomNote;
	char* PM = magazine;
	int Hash[128] = { 0 };
	if (strlen(ransomNote) > strlen(magazine)){
		return 0;
	}
	while (*PM){
		Hash[*PM]++;
		PM++;
	}
	PM = magazine;
	while (*PR){
		if (Hash[*PR]){
			Hash[*PR]--;
		}
		else{
			break;
		}
		PR++;
	}
	if (!*PR){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	char *a = "aa";
	char *b = "aab";
	canConstruct(a, b);
	return 0;
}