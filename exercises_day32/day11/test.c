#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

/*����һ���ַ�������֤���Ƿ��ǻ��Ĵ���ֻ������ĸ�������ַ������Ժ�����ĸ�Ĵ�Сд��

˵���������У����ǽ����ַ�������Ϊ��Ч�Ļ��Ĵ���

ʾ�� 1:

���� : "A man, a plan, a canal: Panama"
��� : true
	 ʾ�� 2 :

 ���� : "race a car"
  ��� : false

	   ��Դ�����ۣ�LeetCode��
   ���ӣ�https ://leetcode-cn.com/problems/valid-palindrome
	 ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
	 */
int isPalindrome(char * s){
	char* top = s;
	char* tail = NULL;
	if (s == NULL){
		return 1;
	}
	tail = s + strlen(s) - 1;
	while (top<tail){
		if (((*top >= 'a'&&*top <= 'z') || (*top >= 'A'&&*top <= 'Z')) && ((*tail >= 'a'&&*tail <= 'z') || (*tail >= 'A'&&*tail <= 'Z'))){//top��tail��������ĸ
			if ((*top == *tail) || (*top + 32 == *tail + 0) || (*top - 32 == *tail + 0) || (*top + 0 == *tail + 32) || (*top + 0 == *tail - 32)){
				top++;
				tail--;
			}
			else{
				return 0;
			}
		}
		else if ((*top >= '0'&&*top <= '9') && (*tail >= '0'&&*tail <= '9')){//��������
			if (*top == *tail){
				top++;
				tail--;
			}
			else{
				return 0;
			}
		}
		else if ((*top >= 'a'&&*top <= 'z') || (*top >= 'A'&&*top <= 'Z')){//top��tailֻ��һ������ĸ
			if (*tail >= '0'&&*tail <= '9'){
				return 0;
			}
			else{
				tail--;
			}
		}
		else if ((*tail >= 'a'&&*tail <= 'z') || (*tail >= 'A'&&*tail <= 'Z')){
			if ((*top >= '0'&&*top <= '9')){
				return 0;
			}
			else{
				top++;
			}
		}
		else if ((*top >= '0'&&*top <= '9')){  //ֻ��һ��������
			if ((*tail >= 'a'&&*tail <= 'z') || (*tail >= 'A'&&*tail <= 'Z')){
				return 0;
			}
			else{
				tail--;
			}
		}
		else if ((*tail >= '0'&&*tail <= '9')){
			if ((*top >= 'a'&&*top <= 'z') || (*top >= 'A'&&*top <= 'Z')){
				return 1;
			}
			else{
				top++;
			}
		}
		else{ //��������ĸ
			top++;
			tail--;
		}
	}
	return 1;
}

/*
����һ���ַ���ʹ��ԭ���㷨����ѹ����

ѹ����ĳ��ȱ���ʼ��С�ڻ����ԭ���鳤�ȡ�

�����ÿ��Ԫ��Ӧ���ǳ���Ϊ1?���ַ������� int �������ͣ���

�����ԭ���޸���������󣬷���������³��ȡ�

?

 ���ף�
 ���ܷ��ʹ��O(1) �ռ������⣿

 ?

  ʾ�� 1��

  ���룺
  ["a","a","b","b","c","c","c"]

  �����
  ����6�����������ǰ6���ַ�Ӧ���ǣ�["a","2","b","2","c","3"]

  ˵����
  "aa"��"a2"�����"bb"��"b2"�����"ccc"��"c3"�����

  ��Դ�����ۣ�LeetCode��
  ���ӣ�https://leetcode-cn.com/problems/string-compression
  ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
int compress(char* chars, int charsSize){
	char*top = chars;
	char*tail = chars;
	char* change = chars;
	int changeRet = 0;
	int flag = 0;
	while (*top){
		flag = 0;
		while (*top == *tail){
			tail++;
			flag++;
			if (!(*tail)){
				break;
			}
		}
		if (flag>1){
			*(change+1) = flag+'0';
			top = tail;
			change+=2;
			changeRet += 2;
		}
		else{
			change++;
			changeRet++;
		}
	}
	return changeRet;
}
int main(){
	char a[] = "aabbccc";
	//isPalindrome(a);
	compress(a, 7);
	return 0;
}