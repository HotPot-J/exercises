#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*
�ж�һ���ַ������Ƿ������һ���ַ���
*/
int canConstruct(char * ransomNote, char * magazine){
	char* PR = ransomNote;
	char* PM = magazine;
	if (magazine == NULL){
		return -1;
	}
	while (*PM&&*PR){
		if (*PM != *PR){
			if (PR != ransomNote){
				PR = ransomNote;
			}
			else
				PM++;
		}
		else{
			PM++;
			PR++;
		}
	}
	if (!(*PR)){
		return 1;
	}
	else{
		return -1;
	}
}
/*
�жϻ������� ��������ת��Ϊ�ַ����Ľⷨ
*/
bool isPalindrome(int x){
	int a = x;
	double ret = 0;
	if (a<0){
		return false;
	}
	while (a){
		ret = ret * 10 + a % 10;
		a /= 10;
	}
	if (x == ret){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	char* r = "a";
	char* m = "b";
	canConstruct02(r, m);
	return 0;
}