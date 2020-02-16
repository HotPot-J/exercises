#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ӡ������� ��������Ƿ�����ɹ�
void PrintArry(int* a, int size){
	int i = 0;
	for (i = 0; i < size; i++){
		printf("%d ", a[i]);
	}
}
//����

//�������� O(n^2)
/*
˼�룺 ������һ������iʱ ������֮ǰ�������Ѿ����� ��ʱ��iȥ�ȶԸ����в����������ȷ��λ�� ��λ�õ�ԭ�������������
�ƶ�һ����Ԫ   
�������еĵ�һ�����ֶ�λ���� �����������ֱ��a[size-2] ÿ�ν�a[i+1]��ǰ����
*/
void InsertSort(int* a, int size){
	int end = 0, tmp = 0, i = 0;
	for (i = 0; i < size - 1; i++){
		end = i;
		tmp = a[i + 1];
		//�������� ��tmp����[0,end]���������� ���ɱ�������
		while (end >= 0){     
			if (a[end] > tmp){  //��ǰendָ���λ�����Ų
				a[end + 1] = a[end--];
			}
			else{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

//ϣ������(�Բ�������ĸĽ��Ż�) O(N^1.3-N^2);
/*
˼�룺 Ԥ���򣺽ӽ�����  ������в��� 
       �������� ������
*/
void ShellSort(int* a, int size){
	int distance = size, tmp = 0, end = 0, i = 0;
	while (distance > 1){   //��distance�ļ�����1��ʱ��ͽ��в�����С���Ĳ�������
		distance = distance / 3 + 1;  //+1����������еĽ�����ն�������Ϊ1 ʹ������������
		for (i = 0; i<size - distance; i++){ //i++�������ͬʱ�÷����������
			end = i;
			tmp = a[i + distance];
			while (end >= 0){ //���˷����������
				if (a[end] > tmp){
					a[end + distance] = a[end];
					end -= distance;
				}
				else{
					break;
				}
			}
			a[end+ distance] = tmp;
		}
	}
}

int main(){
	int a[] = { 3, 4, 2, 6, 4, 3, 60, 1 };
	int size = sizeof(a) / sizeof(int);
	//InsertSort(a, size);
	ShellSort(a, size);
	PrintArry(a, size);

	return 0;
}