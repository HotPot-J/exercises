#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*

1.���⣺������Ԫ��

����������������
A = [A1, A2, ... AN],
B = [B1, B2, ... BN],
C = [C1, C2, ... CN]��
����ͳ���ж��ٸ���Ԫ��(i, j, k) ���㣺
1. 1 <= i, j, k <= N
2. Ai < Bj < Ck

�������ʽ��
��һ�а���һ������N��
�ڶ��а���N������A1, A2, ... AN��
�����а���N������B1, B2, ... BN��
�����а���N������C1, C2, ... CN��

����30%�����ݣ�1 <= N <= 100
����60%�����ݣ�1 <= N <= 1000
����100%�����ݣ�1 <= N <= 100000 0 <= Ai, Bi, Ci <= 100000

�������ʽ��
һ��������ʾ��

���������롿
3
1 1 1
2 2 2
3 3 3

�����������
27


��ԴԼ����
��ֵ�ڴ����ģ���������� < 256M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�
*/
//int fun(int N ,int *A, int *B, int *C){
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int flag = 0;
//	for (i = 0; i < N; i++){
//		for (j = 0; j < N; j++){
//			for (k = 0; k < N; k++){
//				if (A[i] < B[j] && A[i] < C[k] && B[j] < C[k]){
//					flag++;
//				}
//			}
//		}
//	}
//	return flag;
//}
//int main(){
//	int N = 0;
//	int i = 0;
//	int *A;
//	int *B;
//	int *C;
//	scanf("%d", &N);
//	A = (int*)malloc(N*sizeof(int));
//	B= (int*)malloc(N*sizeof(int));
//	C = (int*)malloc(N*sizeof(int));
//	if (N <= 100000 && N >= 1){
//		for (i = 0; i < N;i++){
//			scanf("%d", &A[i]);
//		}
//		for (i = 0; i < N; i++){
//			scanf("%d", &B[i]);
//		}
//		for (i = 0; i < N; i++){
//			scanf("%d", &C[i]);
//		}
//	}
//	printf("\n%d", fun(N, A, B, C));
//	
//	free(A);
//	free(B);
//	free(C);
//	return 0;
//}

/*
���⣺��������

��ͼp1.png��ʾ���������߾���ƽ������������ǡ��һ�Ρ�
��������(X, Y)�����Ƕ�������ԭ��ľ���dis(X, Y)�Ǵ�ԭ�㵽(X, Y)���������߶εĳ��ȡ�

����dis(0, 1)=3, dis(-2, -1)=9

������������(X, Y)�����ܼ����dis(X, Y)��

�������ʽ��
X��Y

����40%�����ݣ�-1000 <= X, Y <= 1000
����70%�����ݣ�-100000 <= X�� Y <= 100000
����100%������, -1000000000 <= X, Y <= 1000000000

�������ʽ��
���dis(X, Y)


���������롿
0 1

�����������
3
*/
/*
�Ƶ���
     ��ÿһ����������һ��������   ��ÿһ�������γ��ȱȺ�һ�������γ�����8
	                              ����Ϊ����-n,-(n-1)��  
	                              ĩβ��Ϊ����-n,-n��
								  ���ֵBΪǰһ�������εĳ���O+1  
								  ĩβֵLΪ���+������N-1
*/
int length(n){ //���㵱ǰ�����γ���
	if (n == 0){
		return 0;
	}
	else{
		return length(n - 1) + 8;
	}
}

int dis(int x, int y){ 
	int a = 0; int b = 0;
	int O = 0; int N = 0; //O N �ֱ����ǰһ�������γ��Ⱥ͵�ǰ�����γ��ȣ�
	int start; int end;//�����յ�
	int start_length = 0;
	int end_length = 0;
	int n = 0; //���a b�нϴ��ֵ
	int mid2 = 0; //�ֱ��¼��2 . 1 .4���޵Ĺյ㳤��;
	int mid1 = 0;
	int mid4 = 0;
	if (x<0){  
		 a = x*(-1);
	}
	else{
		a = x;
	}
	if (y<0){
		b = y*(-1);
	}
	else{
		b = y;
	}
	if (a > b){ //�ж��������ڵڼ����������е�  a��b˭����ǵڼ���������
		n = a;
		N = length(a);
		O = N - 8;
	}
	else{
		n = b;
		N = length(b);
		O = N - 8;
	}
	start = n - 1;//��ʼ���������ֵ
	end = n; //ĩβ���������ֵ
	start_length = O + 1;
	end_length = start_length + N - 1;
	if (x == (-n) && y == -(n - 1)){  //����õ�Ϊ�����յ� ֱ�ӷ�������յ�ĳ��ȼ���
		return start_length;
	}
	if (x == (-n) && y == (-n)){
		return end_length;
	}
	//��������
	if (x <= 0 && y <= 0){
		if (x == -n){
			return start - b + start_length;
		}
		else{
			return end_length - (n - a);
		}
	}
	//�ڶ�����
	mid2 = start_length + (2 * n - 1);
	 if (x<=0 && y>=0){
		if (x == -n){
			return start + b + start_length;
		}
		else{
			return mid2 +( n - a);
		}
	}
	//��һ����
	mid1 = mid2 + 2 * n;
	if (x>=0 && y>=0){
		if (x == n){
			return mid1 + (n - b);
		}
		else{
			return mid2 + (n - a);
		}
	}

	//��������
	mid4 = mid1 + 2 * n;
	if (x >= 0 && y <= 0){
		if (x == n){
			return mid4 - (n - b);
		}
		else{
			return mid4 + (n - a);
		}
	}

}
int main(){
	int x = 0;
	int y = 0;
	scanf("%d%d", &x, &y);
	printf("%d",dis(x, y));
	return 0;
}
