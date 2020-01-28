#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>       
#include<math.h>
#include<stdlib.h>
#include<string.h>


/*
���������������ַ������������ǵĺͣ��ö����Ʊ�ʾ����

����Ϊ�ǿ��ַ�����ֻ��������?1?��?0��

ʾ��?1:

����: a = "11", b = "1"
���: "100"
ʾ��?2:

����: a = "1010", b = "1011"
���: "10101"

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-binary
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/

//˼· �Ӹ�λ��ʼ��� �����Ƚ������ַ�����ת  ��������󽫽����ת��õ����
void rev(char* a){
	char* top = a;
	char* tail = a + strlen(a) - 1;
	char tmp = '0';
	while (top<tail){
		tmp = *top;
		*top = *tail;
		*tail = tmp;
		top++;
		tail--;
	}
}

char * addBinary(char * a, char * b){
	int flag = 0;
	char* pa = a;
	char* pb = b;
	char* ret = (char*)malloc(1000);
	int t = 0;
	rev(a);
	rev(b);
	while (*pa&&*pb){
		ret[t++] = (flag + (*pa - '0') + (*pb - '0')) % 2 + '0';//�������ֵ
		flag = (flag + (*pa - '0') + (*pb - '0')) / 2;//������λ��ֵ
		pa++;
		pb++;
	}
	while (*pa){
		ret[t++] = (flag + (*pa - '0')) % 2 + '0';
		flag = (flag + (*pa - '0')) / 2;
		pa++;
	}
	while (*pb){
		ret[t++] = (flag + (*pb - '0')) % 2 + '0';
		flag = (flag + (*pb - '0')) / 2;
		pb++;
	}
	if (flag == 1){
		ret[t++] = '1';
	}
	ret[t] = '\0';
	rev(ret);
	return ret;
}

/*
������ʵ��һ�� atoi ������ʹ���ܽ��ַ���ת����������
ʾ��?1:

����: "42"
���: 42
ʾ��?2:

����: "   -42"
���: -42
����: ��һ���ǿհ��ַ�Ϊ '-', ����һ�����š�
?    ���Ǿ����ܽ���������������������ֵ�����������������õ� -42 ��
	 ʾ��?3:

	 ����: "4193 with words"
	 ���: 4193
	 ����: ת����ֹ������ '3' ����Ϊ������һ���ַ���Ϊ���֡�
	 ʾ��?4:

	 ����: "words and 987"
	 ���: 0
	 ����: ��һ���ǿ��ַ��� 'w', �����������ֻ��������š�
	 ����޷�ִ����Ч��ת����
	 ʾ��?5:

	 ����: "-91283472332"
	 ���: -2147483648
	 ����: ���� "-91283472332" ���� 32 λ�з���������Χ��
	 ?    ��˷��� INT_MIN (?231) ��

		  ��Դ�����ۣ�LeetCode��
		  ���ӣ�https://leetcode-cn.com/problems/string-to-integer-atoi
		  ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//�ж��ǲ������� ������
int Judge(char a){
	switch (a)
	{
	case '-':
		return 10;
	case '+':
		return 11;
	case '0':
		return -1;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		break;
	}
	return 0;
}
int myAtoi(char * str){
	int ret = 0, tmp = 0, t = 0, y = 0;//t�жϷ���Ϊ�Ƿ����ù�,y�ж�0�ǲ�����Ч���� ���0�ڵ�һ����0����֮ǰ����Ч
	char* p = str;
	char flag = '\0';//�ж�����
	while (*p){
		if ((*p == '-' || *p == '+') && t){
			break;
		}
		if (ret > INT_MAX / 10 || ret == INT_MAX / 10){
			return flag == '-' ? INT_MIN : INT_MAX;
		}
		tmp = Judge(*p);
		if ((*p == ' '||(*p=='0')&&!y)){
			p++;
		}
		else if (tmp){//��һ���ַ������ֻ�'-'
			if (!flag&&tmp == 10){
				if (t){
					break;
				}
				flag = '-';
				p++;
				t = 1;
			}
			else if (!flag&&tmp == 11){
				if (t){
					break;
				}
				flag = '+';
				p++;
				t = 1;
			}
			else{
				y = 1;
				if (tmp == -1){
					ret = ret * 10;
					p++;
				}
				else{
					ret = ret * 10 + tmp;
					p++;
				}
			}
		}
		else{//�ַ�����'-'�����ֵ����
				break;
		}
	}
	if (flag == '-'){
		ret = -ret;
	}
	return ret;
}

/*
����һ�������������е��������� nums����һ��Ŀ��ֵ target���ҳ�����Ŀ��ֵ�������еĿ�ʼλ�úͽ���λ�á�

����㷨ʱ�临�Ӷȱ�����?O(log n) ����

��������в�����Ŀ��ֵ������?[-1, -1]��

ʾ�� 1:

����: nums = [5,7,7,8,8,10], target = 8
���: [3,4]
ʾ��?2:

����: nums = [5,7,7,8,8,10], target = 6
���: [-1,-1]

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *ret = (int*)malloc(sizeof(int)* 2);
	ret[0] = -1; ret[1] = -1;
	int i = 0, t = 0;
	*returnSize = 2;
	for (i = 0; i<numsSize; i++){
		if (t>0){
			t = 1;
		}
		if (nums[i] == target){
			ret[t] = i;
			t++;
		}
	}
	if (ret[0] != -1 && ret[1] == -1){//˵��ֻ��һ��
		ret[1] = ret[0];
	}
	return ret;
}
int main(){
	int a[6] = { 5, 7, 7, 8, 8, 10 };
	int b = 0;
	//int ret = myAtoi(a);
	int* ret = searchRange(a, 6, 8, &b);
	free(ret);
	ret = NULL;
	//char *ret = addBinary(a, b);
	//free(ret);
	return 0;
}