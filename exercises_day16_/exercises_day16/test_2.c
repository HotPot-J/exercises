#define _CRT_SECURE_NO_WARNINGS 1
/*
��������
�����������[a,b]�������������������ֽ⡣
  �����ʽ
  ����������������a��b��
	�����ʽ
	����ÿ�����һ�����ķֽ⣬����k=a1*a2*a3...(a1<=a2<=a3...��kҲ�Ǵ�С�����)(����ɿ�����)
	  ��������
	  3 10
	  �������
	  3=3
	  4=2*2
	  5=5
	  6=2*3
	  7=7
	  8=2*2*2
	  9=3*3
	  10=2*5
	  ��ʾ
	  ������ɸ������������Ȼ���ٷֽ⡣
*/
#include<stdio.h>
#include<stdlib.h>
int fun(int tmp){
	int i = 0;
	int flag = 0;
	if (tmp==1||tmp==2||tmp==3){
		return 1;
	}
	for (i = 2; i <= (tmp / 2); i++){
		if (tmp%i == 0){
			return 0; //��������
		}
	}
	return 1;//������
}
int fun1(int tmp){
	int i = 0;
	for (i = 2; i <= (tmp / 2); i++){
		if (tmp%i == 0){
			break;
		}
	}
	return i;
}

void   fun2(int tmp){
		int i = 0;
		int j = 0;
		int tmp1 = 0;
		while (1){
			tmp1 =  fun1(tmp);
			printf("%d", tmp1);
			printf("*");
			tmp = tmp / tmp1;
			if (fun(tmp)){ //���tmp������
				printf("%d\n", tmp);
				break;
			}
		}
	}



int main(){
	int a = 0, b = 0;
	int i = 0, tmp = 0;
	scanf("%d%d", &a,&b);
	i = a;
	for (i; i <= b; i++){
		tmp = i;
		if (fun(tmp)){//������
			printf("%d=%d\n", tmp,tmp);
		}
		else{
		printf("%d=", tmp);
         fun2(tmp);

		}
	}
	return 0;
}
