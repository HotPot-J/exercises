#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*��������
����������������a��b����������������ĺ͡�a��b��������100λ��
�㷨����
��������a��b���Ƚϴ����Բ���ֱ��ʹ�������еı�׼�����������洢�������������⣬һ��ʹ������������
��������һ������A��A[0]���ڴ洢a�ĸ�λ��A[1]���ڴ洢a��ʮλ���������ơ�ͬ��������һ������B���洢b��
��������c = a + b��ʱ�����Ƚ�A[0]��B[0]��ӣ�����н�λ��������ѽ�λ�����͵�ʮλ��������r���Ѻ͵ĸ�λ������C[0]����C[0]����(A[0]+B[0])%10��Ȼ�����A[1]��B[1]��ӣ���ʱ��Ӧ����λ��������ֵrҲ����������C[1]Ӧ����A[1]��B[1]��r�������ĺͣ�������н�λ���������Կɽ��µĽ�λ���뵽r�У��͵ĸ�λ�浽C[1]�С��������ƣ��������C������λ��
�������C������ɡ�
�����ʽ
��������������У���һ��Ϊһ���Ǹ�����a���ڶ���Ϊһ���Ǹ�����b������������������100λ�����������λ������0��
�����ʽ
�������һ�У���ʾa + b��ֵ��
��������
20100122201001221234567890
2010012220100122
*/
void fun(char* p){
	char* top = p;
	char* tail = strlen(p)-1+p;
	char tmp = '0';
	while (top < tail){
		tmp = *tail;
		*tail = *top;
		*top = tmp;
		top++;
		tail--;
	}
}
void Add(char *a,char* b){
	int i = 0, flag = 0, csize = 0;
	char c[101] = { 0 };
	int asize = strlen(a);
	int bsize = strlen(b);
	int tmp = asize >= bsize ? bsize : asize;
	fun(a);
	fun(b);
	for (i = 0; i<tmp;i++){
		c[i] = (a[i]-'0' + b[i]-'0' + flag) % 10+'0';
		flag = (a[i]-'0' + b[i]-'0' + flag) / 10;
	}
	if (asize>bsize){
		for (i; i < asize; i++){
			c[i] = (a[i]-'0'+ flag) % 10+'0';
			flag = (a[i]-'0'+ flag) / 10;
		}
	}
	else{
		for (i; i < bsize; i++){
			c[i] = (b[i]-'0' + flag) % 10+'0';
			flag = (b[i]-'0' + flag) / 10+'0';
		}
	}
	fun(c);
	printf("%s", c);
}
int main(){
	char a[101] = { '0' };
	char b[101] = { '0' };
	scanf("%s", a);
	scanf("%s", b);
	Add(a, b);
	return 0;
}
