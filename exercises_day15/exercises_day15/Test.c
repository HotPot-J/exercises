#define _CRT_SECURE_NO_WARNINGS 1
/*
��������
��������һ������Ϊ��λ��ʱ��t��Ҫ���á�<H>:<M>:<S>���ĸ�ʽ����ʾ���ʱ�䡣<H>��ʾʱ�䣬<M>��ʾ���ӣ���<S>��ʾ�룬���Ƕ���������û��ǰ���ġ�0�������磬��t=0����Ӧ����ǡ�0:0:0������t=3661���������1:1:1����
  �����ʽ
  ��������ֻ��һ�У���һ������t��0<=t<=86399����
	�����ʽ
	�������ֻ��һ�У����ԡ�<H>:<M>:<S>���ĸ�ʽ����ʾ��ʱ�䣬���������š�
	  ��������
	  0
	  �������
	  0:0:0
	  ��������
	  5436
	  �������
	  1:30:36
*/
#include<stdio.h>
int fun(int tmp){
	int flag= 0;
	while (tmp){
		flag++;
		tmp = tmp / 10;
	}
	return flag;
}

 int main(){
	 int n = 0;
	 int tmp = 0;
	 int tmp1 = 0;
	 int tmp2 = 0; //��¼Сʱ
	 int tmp3 = 0; //��¼����
	 int r = 0;
	 int i = 0;
	 int size1 = 0;
	 int size2 = 0;
	 int size3 = 0;
	 char arr[100] = { '0' };
	 scanf("%d", &n); 
	 if (n == 0){
		 arr[0] = '0';
		 arr[1] = ':';
		 arr[2] = '0';
		 arr[3] = ':';
		 arr[4] = '0';
		 for (i = 0; i < 5; i++){
			 printf("%c", arr[i]);
		 }
		 printf("\n");
	 }
	 else{
		 tmp = n / 3600;
		 tmp2 = tmp;
		 size1 = fun(tmp);
		 r = size1 - 1;
		 for (i = 0; i < size1; i++){
			 arr[r--] = tmp % 10 + '0';
			 tmp = tmp / 10;
		 }//111222
		 arr[size1] = ':';  

		 tmp = (n- size1*3600)/60;
		 tmp3 = tmp;
		 size2 = fun(tmp);
		 r = size1+size2;
		 for (i = 0; i < size2 ; i++){
			 arr[r--] = (tmp % 10)+'0';
			 tmp = tmp / 10;
		 }
		 arr[size1+size2+1] = ':';

		 tmp = n - tmp2* 3600-tmp3*60;
		 size3 = fun(tmp);
		 r = size1 + size2 +size3+1 ;
		 for (i = 0; i < size3; i++){
			 arr[r--] = tmp % 10 + '0';
			 tmp = tmp / 10;
		 }
		 for (i = 0; i < (size1+size2+size3+2); i++){
			 printf("%c", arr[i]);
		 }
	 }
     return 0;
	
}
