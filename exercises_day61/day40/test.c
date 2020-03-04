#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
392. �ж�������
�����ַ��� s �� t ���ж� s �Ƿ�Ϊ t �������С�
�������Ϊ s �� t �н�����Ӣ��Сд��ĸ���ַ��� t ���ܻ�ܳ������� ~= 500,000������ s �Ǹ����ַ��������� <=100����
�ַ�����һ����������ԭʼ�ַ���ɾ��һЩ��Ҳ���Բ�ɾ�����ַ������ı�ʣ���ַ����λ���γɵ����ַ����������磬"ace"��"abcde"��һ�������У���"aec"���ǣ���
ʾ�� 1:
s = "abc", t = "ahbgdc"
���� true.
ʾ�� 2:
s = "axc", t = "ahbgdc"
���� false.
*/
int isSubsequence(char * s, char * t){
	char* sp = s;
	char* tp = t;
	while (*sp&&*tp){
		if (*sp == *tp){
			sp++;
		}
		tp++;
	}
	if (*sp){
		return -1;
	}
	else{
		return 1;
	}
}
//int main(){
//	char *s = "axc";
//	char *t = "ahbgdc";
//	isSubsequence(s, t);
//	return 0;
//}

/*
1046. ���һ��ʯͷ������
��һ��ʯͷ��ÿ��ʯͷ������������������
ÿһ�غϣ�����ѡ���������ص�ʯͷ��Ȼ������һ����顣����ʯͷ�������ֱ�Ϊ x �� y���� x <= y����ô����Ŀ��ܽ�����£�

��� x == y����ô����ʯͷ���ᱻ��ȫ���飻
��� x != y����ô����Ϊ x ��ʯͷ������ȫ���飬������Ϊ y ��ʯͷ������Ϊ y-x��
������ֻ��ʣ��һ��ʯͷ�����ش�ʯͷ�����������û��ʯͷʣ�£��ͷ��� 0��
��ʾ��
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/
int cmp(const void*a, const void*b){
	return *(int*)a > *(int*)b;
}
int lastStoneWeight(int* stones, int stonesSize){
	int tmp = 0;
	while (stonesSize > 1){
		qsort(stones, stonesSize, sizeof(int), cmp);
		if (stones[stonesSize - 1] == stones[stonesSize - 2]){
			stonesSize -= 2;
		}
		else{
			stones[stonesSize - 2] = stones[stonesSize - 1] - stones[stonesSize - 2];
			stonesSize--;
		}
	}
	if (stonesSize == 0){
		return 0;
	}
	else{
		return stones[0];
	}
}

/*
860. ����ˮ����
������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ 5 ��Ԫ��
�˿��Ŷӹ�����Ĳ�Ʒ�������˵� bills ֧����˳��һ�ι���һ����
ÿλ�˿�ֻ��һ������ˮ��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ���㣬Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��
ע�⣬һ��ʼ����ͷû���κ���Ǯ��
������ܸ�ÿλ�˿���ȷ���㣬���� true �����򷵻� false ��
ʾ�� 1��
���룺[5,5,5,10,20]
�����true
���ͣ�
ǰ 3 λ�˿�������ǰ�˳����ȡ 3 �� 5 ��Ԫ�ĳ�Ʊ��
�� 4 λ�˿����������ȡһ�� 10 ��Ԫ�ĳ�Ʊ�������� 5 ��Ԫ��
�� 5 λ�˿���������һ�һ�� 10 ��Ԫ�ĳ�Ʊ��һ�� 5 ��Ԫ�ĳ�Ʊ��
�������пͻ����õ�����ȷ�����㣬����������� true��
ʾ�� 2��
���룺[5,5,10]
�����true
ʾ�� 3��
���룺[10,10]
�����false
ʾ�� 4��
���룺[5,5,10,10,20]
�����false
���ͣ�
ǰ 2 λ�˿�������ǰ�˳����ȡ 2 �� 5 ��Ԫ�ĳ�Ʊ��
���ڽ������� 2 λ�˿ͣ�������ȡһ�� 10 ��Ԫ�ĳ�Ʊ��Ȼ�󷵻� 5 ��Ԫ��
�������һλ�˿ͣ������޷��˻� 15 ��Ԫ����Ϊ��������ֻ������ 10 ��Ԫ�ĳ�Ʊ��
���ڲ���ÿλ�˿Ͷ��õ�����ȷ�����㣬���Դ��� false��
*/

//˼·������1�������������յ���Ǯ ���������ô��Ǯ+С��Ǯ�Ҹ��˿� �����Ż��и������Ǯ
int lemonadeChange(int* bills, int billsSize){
     //a[0]��ʾ5Ԫ����Ǯ a[1]��ʾ10Ԫ����
	int i = 0, tmp = 0;
	int a[2] = { 0, 0 };
	for (i = 0; i < billsSize; i++){
		tmp = bills[i];
		while (tmp>10){
			if (!a[1]){ //û10Ԫ����ֵ��
				break;
			}
			tmp -= 10;
			a[1]--;
		}
		while (tmp > 5){
			if (!a[0]){
				break;
			}
			tmp -= 5;
			a[0]--;
		}
		if (tmp == 5){
			if (bills[i] == 10){
				a[1]++;
			}
			else if(bills[i]==5){
				a[0]++;
			}
		}
		else{
			return -1;
		}
	}
	return 1;
}
int main(){
	int a[] = { 5,5,5,10,5,5,10,20,20,20};
	int len = sizeof(a) / sizeof(a[0]);
	lemonadeChange(a, len);
	return 0;
}

