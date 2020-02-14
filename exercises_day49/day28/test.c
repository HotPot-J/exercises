#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
���� S �� T �����ַ����������Ƿֱ����뵽�հ׵��ı��༭�����ж϶����Ƿ���ȣ������ؽ���� # �����˸��ַ���
 ʾ�� 1��
 ���룺S = "ab#c", T = "ad#c"
 �����true
 ���ͣ�S �� T ������ ��ac����
 ʾ�� 2��
 ���룺S = "ab##", T = "c#d#"
 �����true
 ���ͣ�S �� T ������ ������
 ʾ�� 3��
 ���룺S = "a##c", T = "#a#c"
 �����true
 ���ͣ�S �� T ������ ��c����
 ʾ�� 4��
 ���룺S = "a#c", T = "b"
 �����false
 ���ͣ�S ���� ��c������ T ��Ȼ�� ��b����
  ��ʾ��
  1 <= S.length <= 200
  1 <= T.length <= 200
  S �� T ֻ����Сд��ĸ�Լ��ַ� '#'��

  ��Դ�����ۣ�LeetCode��
  ���ӣ�https://leetcode-cn.com/problems/backspace-string-compare
  ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//˼·�������������Ԫ��������ջ ��ǰָ�����������#���ҵ�ǰջ������ĸ ������ĸ��ջ �����ж�����ջ�Ƿ���ȼ���
int Stackpp(char* p,char *Stack){
	int i = -1;
	while (*p){
		if (*p >= 'a'&&*p <= 'z'){
			Stack[++i] = *p;
		}
		else if (*p == '#'){
			if (i != -1){ //��ǰջ��Ϊ��
				i--;
			}
		}
		p++;
	}
	return i;
}
int backspaceCompare(char * S, char * T){
	char *StackS = (char*)malloc(sizeof(char)* 201);
	char *StackT = (char*)malloc(sizeof(char)* 201);
	int i = 0, j = 0;
	i = Stackpp(S, StackS);
	j = Stackpp(T, StackT);
	if (i != j){
		return -1;
	}
	else{
		for (i = 0; i <= j; i++){
			if (StackS[i] != StackT[i]){
				return -1;
			}
		}
	}
	return 1;
}

/*
��������?0?��?1? ��ɵ�����?A?�У��ж��ٸ���Ϊ S?�ķǿ������顣

 ʾ����

 ���룺A = [1,0,1,0,1], S = 2
 �����4
 ���ͣ�
 �����������ʾ���� 4 ��������ĿҪ��������飺
 [1,0,1,0,1]
 [1,0,1,0,1]
 [1,0,1,0,1]
 [1,0,1,0,1]
 ?
  ��ʾ��
  A.length <= 30000
  0 <= S <= A.length
  A[i]?Ϊ?0?��?1

  ��Դ�����ۣ�LeetCode��
  ���ӣ�https://leetcode-cn.com/problems/binary-subarrays-with-sum
  ����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
//�û��������㷨
int numSubarraysWithSum(int* A, int ASize, int S){
	//����
	if (ASize == 0){
		return 0;
	}
	int* top = A, *tail = A+1;
	int sum = *top; int ret = 0;
	while (top < A + ASize){
			if (sum < S){
				if (tail >= A + ASize){
					break;
				}
				sum += *tail;
				tail++;
			}
			else if (sum >S){
				sum -= *top;
				top++;
			}
			else {
				ret++;
				if (tail < A + ASize){
					sum += *tail;
					tail++;
				}
				else{
					sum -= *top;
					top++;
				}
			}
	}
	return ret;
}
int main(){
	int a[5] = { 0, 0, 0, 0, 0 };
	numSubarraysWithSum(a, 5, 0);
	return 0;
}