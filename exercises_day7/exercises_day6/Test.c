#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
����һ�����ʣ��������������е�һ�����ֵ�Ԫ����ĸ��
����Ԫ����ĸ���� a, e, i, o, u���������
  �����ʽ
  ��������һ�У�����һ�����ʣ�������ֻ����СдӢ����ĸ��
	�����ʽ
	�������һ�а���һ����ĸ��Ϊ�����е�һ�����ֵ�Ԫ����ĸ���������в�����Ԫ����ĸ�������ĸn��
	  ��������
	  hello
	  �������
	  e
	  ��������
	  fly
	  �������
	  n
	  ����������ģ��Լ��
	  ���������������������������е���ĸ����������100��
		C


		1
*/
char fun(char *arr, char *temp){
	int j = 0;
	int i = 0;
	while (arr[i]){
		for (j = 0; j < 4; j++){
			if (arr[i] == temp[j]){
				return temp[j];
			}
		}
		i++;
	}
	return 'n';
}
int main(){
	char arr[100] = {0};
	char temp[5] = { 'a', 'e', 'i', '0', 'u' };
	gets(arr);
	printf("%c\n",fun(arr, temp));
	return 0;
}

//��������
//С���ǳ���ϲ������ 2��������Щ��λ�ϰ������� 2 ���������һ��������λ���������� 2��С��������Ϊ�ྻ����
//���������� 1 �� n �У��ྻ���ж��ٸ���
//�����ʽ
//����ĵ�һ�а���һ������ n��
//�����ʽ
//���һ�а���һ����������ʾ�𰸡�
//��������
//30
//�������
//18
//����������ģ��Լ��
//���� 40 % ������������1 <= n <= 10000��
//���� 80 % ������������1 <= n <= 100000��
//������������������1 <= n <= 1000000��
void fun(int n){
	int i = 1;
	int flag = 0;
	int ret = 0;
	for (i = 1; i <= n; i++){
		flag = i;
		while (flag){
			if (flag % 10 == 2){
				ret = 0;
				break;
			}
			else{
				ret = 1;
				flag = flag / 10;
			}
		}
		if (ret){
			printf("%d ", i);
		}
	}
}
int main(){
	int n = 0;
	scanf("%d",&n);
if (n >= 1 && n <= 1000000){
		fun(n);
}
	return 0;
}

//������������ a, b, c�����һ�������Ȳ��� a ��������Ҳ���� b �������������� c �������������������Ϊ��������
//������ 1 �� n ���ж��ٸ���������
//�����ʽ
//����ĵ�һ�а���һ������ n��
//�ڶ��а����������� a, b, c������������֮����һ���ո�ָ���
//�����ʽ
//���һ�а���һ����������ʾ�𰸡�
//��������
//30
//2 3 6
//�������
//10
//����˵��
//������Щ������Ҫ��1, 5, 7, 11, 13, 17, 19, 23, 25, 29��
//����������ģ��Լ��
//���� 40 % ������������1 <= n <= 10000��
//���� 80 % ������������1 <= n <= 100000��
//������������������1 <= n <= 1000000��1 <= a <= n��1 <= b <= n��1 <= c <= n��
void fun(int n, int *abc){
	int N = n;
	int ret[100000];
	int i = 1;
	int j = 0;
	int flag1 = 1;
	int flag2 = 0;
	int flag3 = 0;
	for (i = 1; i <= n; i++){
		flag1 = 1;
		for (j = 0; j < 3; j++){
			if (i%abc[j] == 0){
				flag1 = 0;
				break;
			}
		}
		if (flag1){
			ret[flag3] = i;
			flag2++;
			flag3++;

		}
	}
	printf("%d\n", flag2);
	for (j = 0; j < flag2; j++){
		printf("%d ", ret[j]);
	}
}
int main(){
	int n = 0;
	int abc[3] = {0};
	int i = 0;
	scanf("%d", &n);
	for (i = 0; i < 3; i++){
		scanf("%d", &abc[i]);
	}
	fun(n, abc);
	return 0;
}


/*
��������
С����һ��յأ��������յػ���Ϊ n �� m �е�С�飬ÿ�к�ÿ�еĳ��ȶ�Ϊ 1��
С��ѡ�����е�һЩС��յأ������˲ݣ�����С����Ȼ�����ǿյء�
��Щ�ݳ��úܿ죬ÿ���£��ݶ������ⳤ��һЩ�����һ��С�����˲ݣ����������Լ����ϡ��¡���
����С��յ���չ������С��յض�����Ϊ�вݵ�С�顣�����С����k ���º�յ�����Щ�ط��вݡ�

�����ʽ
����ĵ�һ�а����������� n, m��
������ n �У�ÿ�а��� m ����ĸ����ʾ��ʼ�Ŀյ�״̬����ĸ֮��û�пո����ΪС���㣬��ʾΪ�յأ�
�����ĸΪ g����ʾ���˲ݡ�����������һ������ k��
 
�����ʽ
��� n �У�ÿ�а��� m ����ĸ����ʾ k ���º�յص�״̬�����ΪС���㣬��ʾΪ�յأ������ĸΪ g��
��ʾ���˲ݡ�
				��������
				4 5
				.g...
				.....
				..g..
				.....
				2
				�������
				gggg.
				gggg.
				ggggg
				.ggg.
*/
void grow(char arr[][1000], int n,int m,int i, int j){  //���²�
	if (i == 0 && j == 0){  //���Ͻ�
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}
		if (arr[i][j+1] == 'g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}
	}
	else if (j == (m - 1) && i == 0){ //���Ͻ�
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}
		if (arr[i + 1][j] =='g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}

	}
	else if (j == 0 && i == (n - 1)){ //���½�
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}
		if (arr[i][j + 1] == 'g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}
	}
	else if (j == (m - 1) && i == (n - 1)){ //���½�
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}
	}
	else if (j == 0){ //��һ��
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}
		if (arr[i][j + 1] == 'g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}
	}
	else if (i == 0){ //��һ��
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}//��
		if (arr[i][j - 1] =='g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//��
		if (arr[i][j + 1] == 'g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}//��
	}
	else if (i == (n - 1)){ //���һ��
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//��
		if (arr[i][j + 1] == 'g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}//��
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}//��
	}
	else if (j==(m-1)){//������
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}//��
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}//��
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//��
	}
	else{
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}//��
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}//��
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//��
		if (arr[i][j + 1] =='g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}//��
	}
}
void oldgrow(char arr[][1000], int n, int m, int i, int j){//�²ݱ�ɲ�
	for (i = 0; i < n; i++){
		for (j = 0; j < m; j++){
			if (arr[i][j] == 'k'){
				arr[i][j] = 'g';
			}
		}
	}
}
void foundg(char arr[][1000],int n,int m,int k){
	int i = 0, j = 0;
	while (k--){
		for (i = 0; i < n; i++){		
			for (j = 0; j < m; j++){
				if (arr[i][j] == 'g'){
					grow(arr, n, m, i, j);
				}
			}
		}
		oldgrow(arr, n, m, i, j);
	}
}
int main(){
	int n = 0, m = 0, i = 0, j = 0, k = 0;
	char arr[1000][1000];
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++){
		scanf("%s", &arr[i]);
	}
	scanf("%d", &k);
	foundg(arr, n, m, k);
	for (i = 0; i < n; i++){
	printf("%s\n", arr[i]);
	
	}
	free(arr);
	return 0;
}
