#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
��������
����FJ��ɳ����д������һЩ�ַ�����
  ����A1 = ��A��
	����A2 = ��ABA��
	  ����A3 = ��ABACABA��
		����A4 = ��ABACABADABACABA��
		  ������ ��
			���������ҳ����еĹ��ɲ�д���е�����AN��
			  �����ʽ
			  ��������һ������N �� 26��
				�����ʽ
				�����������Ӧ���ַ���AN����һ�����з�����������в��ú��ж���Ŀո���С��س�����
				  ��������
				  3
				  �������
				  ABACABA
*/
void FJ(int k){
  //���ɾ��� ÿ���ٱ����ַ��� ǰ��ͺ������ ��һ�ε��ַ�
		if (!k){
			;
		}
		else{
			FJ(k - 1);
			printf("%c", 'A' + k - 1);
			FJ(k - 1);
		}

}
int main(){
	int k = 0;
	scanf("%d", &k);
	FJ(k);
	return 0;
}