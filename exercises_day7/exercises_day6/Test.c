#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
/*
输入一个单词，请输出这个单词中第一个出现的元音字母。
　　元音字母包括 a, e, i, o, u，共五个。
  输入格式
  　　输入一行，包含一个单词，单词中只包含小写英文字母。
	输出格式
	　　输出一行包含一个字母，为单词中第一个出现的元素字母。若单词中不存在元音字母，输出字母n。
	  样例输入
	  hello
	  样例输出
	  e
	  样例输入
	  fly
	  样例输出
	  n
	  评测用例规模与约定
	  　　对于所有评测用例，单词中的字母个数不超过100。
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

//问题描述
//小明非常不喜欢数字 2，包括那些数位上包含数字 2 的数。如果一个数的数位不包含数字 2，小明将它称为洁净数。
//请问在整数 1 至 n 中，洁净数有多少个？
//输入格式
//输入的第一行包含一个整数 n。
//输出格式
//输出一行包含一个整数，表示答案。
//样例输入
//30
//样例输出
//18
//评测用例规模与约定
//对于 40 % 的评测用例，1 <= n <= 10000。
//对于 80 % 的评测用例，1 <= n <= 100000。
//对于所有评测用例，1 <= n <= 1000000。
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

//给定三个整数 a, b, c，如果一个整数既不是 a 的整数倍也不是 b 的整数倍还不是 c 的整数倍，则这个数称为反倍数。
//请问在 1 至 n 中有多少个反倍数。
//输入格式
//输入的第一行包含一个整数 n。
//第二行包含三个整数 a, b, c，相邻两个数之间用一个空格分隔。
//输出格式
//输出一行包含一个整数，表示答案。
//样例输入
//30
//2 3 6
//样例输出
//10
//样例说明
//以下这些数满足要求：1, 5, 7, 11, 13, 17, 19, 23, 25, 29。
//评测用例规模与约定
//对于 40 % 的评测用例，1 <= n <= 10000。
//对于 80 % 的评测用例，1 <= n <= 100000。
//对于所有评测用例，1 <= n <= 1000000，1 <= a <= n，1 <= b <= n，1 <= c <= n。
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
问题描述
小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、
右四小块空地扩展，这四小块空地都将变为有草的小块。请告诉小明，k 个月后空地上哪些地方有草。

输入格式
输入的第一行包含两个整数 n, m。
接下来 n 行，每行包含 m 个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，
如果字母为 g，表示种了草。接下来包含一个整数 k。
 
输出格式
输出 n 行，每行包含 m 个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为 g，
表示长了草。
				样例输入
				4 5
				.g...
				.....
				..g..
				.....
				2
				样例输出
				gggg.
				gggg.
				ggggg
				.ggg.
*/
void grow(char arr[][1000], int n,int m,int i, int j){  //长新草
	if (i == 0 && j == 0){  //左上角
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
	else if (j == (m - 1) && i == 0){ //右上角
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
	else if (j == 0 && i == (n - 1)){ //左下角
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
	else if (j == (m - 1) && i == (n - 1)){ //右下角
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
	else if (j == 0){ //第一列
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
	else if (i == 0){ //第一行
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}//下
		if (arr[i][j - 1] =='g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//左
		if (arr[i][j + 1] == 'g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}//右
	}
	else if (i == (n - 1)){ //最后一行
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//左
		if (arr[i][j + 1] == 'g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}//右
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}//上
	}
	else if (j==(m-1)){//最右列
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}//上
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}//下
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//左
	}
	else{
		if (arr[i - 1][j] == 'g'){
			;
		}
		else{
			arr[i - 1][j] = 'k';
		}//上
		if (arr[i + 1][j] == 'g'){
			;
		}
		else{
			arr[i + 1][j] = 'k';
		}//下
		if (arr[i][j - 1] == 'g'){
			;
		}
		else{
			arr[i][j - 1] = 'k';
		}//左
		if (arr[i][j + 1] =='g'){
			;
		}
		else{
			arr[i][j + 1] = 'k';
		}//右
	}
}
void oldgrow(char arr[][1000], int n, int m, int i, int j){//新草变旧草
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
