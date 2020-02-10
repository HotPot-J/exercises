#define _CRT_SECURE_NO_WARNINGS 1
/*
����һ���ַ����������ҳ����в������ظ��ַ���?��Ӵ�?�ĳ��ȡ�

ʾ��?1:

����: "abcabcbb"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ��� "abc"�������䳤��Ϊ 3��
ʾ�� 2:

����: "bbbbb"
���: 1
����: ��Ϊ���ظ��ַ�����Ӵ��� "b"�������䳤��Ϊ 1��
ʾ�� 3:

����: "pwwkew"
���: 3
����: ��Ϊ���ظ��ַ�����Ӵ���?"wke"�������䳤��Ϊ 3��
?    ��ע�⣬��Ĵ𰸱����� �Ӵ� �ĳ��ȣ�"pwke"?��һ�������У������Ӵ���

	 ��Դ�����ۣ�LeetCode��
	 ���ӣ�https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˫ָ�뱩���� ����ÿһ���ִ� ʱ�临�ӶȽϸ�
#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring1(char * s){
	char *head = s;
	char *temp = NULL;//����head-tail֮���ֵ
	char *tail = NULL;//�µ�β
	int flag = 1;//��¼ÿ�εĳ��� 
	int max = 0;//��¼��ĳ��ȣ���Ϊ����ֵ
	//Ϊ�յ����
	if (*head == '\0'){
		return 0;
	}
	//ֻ��һ���ַ������
	if (*(head + 1) == '\0'){
		return 1;
	}
	//��ͨ���
	while (*head){//head��
		temp = head;
		tail = head + 1;
		while (*tail){//β����
			if (*temp != *tail){ //��*temp��*tail�����
				temp++;
				if (temp == tail){
					tail++;
					temp = head;
					flag++;
				}
			}
			else{
				break;
			}
		}
		if (flag>max){
			max = flag;
		}
		flag = 1;
		head++;
	}
	return max;
}

//˫ָ��  �ù�ϣ������Ϊ�����������жϵķ��� ʱ�临�Ӷ�O��n��
char HashMap[256] ;//���ù�ϣ���Ӧascii��  ���磺HashMap[a] ��a��ascii��Ϊ97������HashMap[97]
int Hash(char a){
	if (HashMap[a]){
		return 1;//˵�����ַ������ڴ�����
	}
	return 0; //�������ڴ�����
}
int lengthOfLongestSubstring(char * s){
	char *top = s, *tail = s;
	int  ret = 0,flag = 0;
	memset(HashMap, 0, sizeof(HashMap));
	if (s == NULL){
		return 0;
	}
	if (s[0] == '\0'){
		return 0;
	}
	while (*tail){
		if (Hash(*tail)){ // ˵�������ڵ�ǰ����
			flag = tail - top;
			if (flag >= ret){
				ret = flag;
			}
			while (*top != *tail){
				HashMap[*top] = '\0';
				top++;
			}
			HashMap[*tail] = '\0';
			top++;
		}
		else{//�������ڵ�ǰ����
			HashMap[*tail] = *tail;//��������ϣ����
			tail++;
		}
	}
	flag = tail - top;
	if (flag > ret){
		ret = flag;
	}
	return ret;
}
int main(){
	char* s = " ";
	printf("%d", lengthOfLongestSubstring(s));
	return 0;
}