#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
��������
�������FJΪ������ţ�ǿ�������ѧ�����Σ�FJ֪����Ҫѧ�����ſΣ�������һ���õ����Ǻ�����������������׼������ţ����һ����Sine֮�衱����Ϸ��Ԣ�����֣������ţ�ǵļ���������
  ����������
	����An=sin(1�Csin(2+sin(3�Csin(4+...sin(n))...)
	  ����Sn=(...(A1+n)A2+n-1)A3+...+2)An+1
		����FJ������ţ�Ǽ���Sn��ֵ���������FJ��ӡ��Sn���������ʽ���Է�����ţ�����⡣
		  �����ʽ
		  ��������һ������N<201��
			�����ʽ
			�����������Ӧ�ı��ʽSn����һ�����з�����������в��ú��ж���Ŀո���С��س�����
			  ��������
			  3
			  �������
			  ((sin(1)+3)sin(1�Csin(2))+2)sin(1�Csin(2+sin(3)))+1
*/
void An(int n,int k){
	if (n == k){
		printf("sin(%d)",n);
	}
	else{
		printf("sin(%d",n);
		if (n % 2 == 0){
			printf("+");
		}
		else{
			printf("-");
		}
		An(n+1,k );
		printf(")");
	}
}
void Sine(int n,int k){
	if (n == 1){
		An(n,1 );
		printf("+%d",k-n);
	}
	else{
		printf("(");
		Sine(n-1,k);
		printf(")");
		An(1, n);
		printf("+%d",k-n);
		
	}
}
int main(){
	int n = 0;
	scanf("%d", &n);
	Sine(n, n+1);
	printf("\n");
	return 0;
}