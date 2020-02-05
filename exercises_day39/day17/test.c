#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
��������
��������һ��n*n�����̣���������һЩλ�ò��ܷŻʺ�����Ҫ�������з���n���ڻʺ��n���׻ʺ�ʹ����������ڻʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ����ܹ��ж����ַŷ���nС�ڵ���8��
  �����ʽ
  ��������ĵ�һ��Ϊһ������n����ʾ���̵Ĵ�С��
	����������n�У�ÿ��n��0��1�����������һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�
	  �����ʽ
	  �������һ����������ʾ�ܹ��ж����ַŷ���
		��������
		4
		1 1 1 1
		1 1 1 1
		1 1 1 1
		1 1 1 1
		�������
		2
*/
//дһ��check�����жϵ�ǰλ���Ƿ����  
//ͬһ�����¹���Ĳ����� ͬһ�����¹���Ĳ����� �Խ������¹���Ĳ�����
int arr[8][8] = { 0 };
int ret = 0, n = 0;

int check( int i, int j ,int s){
	int k = 0, itmp = 0, jtmp = 0, tmp = 0;
	if (arr[i][j] == 0){  //��λ�ò��ɷŻʺ�
		return 0;
	}
	for (k = 0; k < n; k++){//�ж���һ����û���Ѿ��¹���
		if (arr[i][k] == s){
			return 0;
		}
	}
	for (k = 0; k < n; k++){ //�жϸ�λ�ö�Ӧ����һ����û���Ѿ��¹���
		if (arr[k][j] == s){
			return 0;
		}
	}
	//�ж϶Խ���
   //�������ǰλ�������Ͻǻ��������Ͻǵ�λ�� ��ʼ���  �����Ͻ�itmp = i-min(i,j) jtmp = j-min(i,j)
	tmp = i >= j ? j : i;  //�����Ͻǵ����½�
	itmp = i - tmp;
	jtmp = j - tmp;
	while (itmp < n&&jtmp < n){ 
		if (arr[itmp][jtmp] == s){
			return 0;
		}
		itmp++;
		jtmp++;
	}

	tmp = i >= (n - 1 - j) ? (n - 1 - j) : i;
	itmp = i - tmp;
	jtmp = j + tmp;
	while (itmp < n&&jtmp >= 0){
		if (arr[itmp][jtmp] == s){
			return 0;
		}
		itmp++;
		jtmp--;
	}
	return 1;
}

int queen(int i,int s){
	int j;
	if (i == n){//���������ĳһ�ֻʺ�
		if (s == 2){//�׻ʺ������  
			queen(0,3);//�źڻʺ�
		}
		else{
			ret++; //�ڻʺ�Ҳ������
		}
		return 0;
	}
	for (j = 0; j < n; j++){
		if (arr[i][j] != 1){
			continue;
		}
		if (check(i, j,s)){//���Է�
			arr[i][j] = s;
		}
		else{ //�����Է�
			continue;
		}
		queen(i + 1, s);//�ж���һ��
		arr[i][j] = 1;  //���ݵ�ʱ�����̻�ԭ��
	}
		return 0;  //���л��� ��������
	
}
int main(){
	int i = 0, j = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	queen(0, 2);
	printf("%d", ret);
	return 0;
}

