#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int lengthOfLongestSubstring(char * s){
//	char *head = s;
//	char *temp = NULL;//遍历head-tail之间的值
//	char *tail = NULL;//新的尾
//	int flag = 1;//记录每次的长度 
//	int max = 0;//记录最长的长度，作为返回值
//	//为空的情况
//	if (*head == '\0'){
//		return 0;
//	}
//	//只有一个字符的情况
//	if (*(head + 1) == '\0'){
//		return 1;
//	}
//	//普通情况
//	while (*head){//head走
//		temp = head;
//		tail = head + 1;
//		while (*tail){//尾巴走
//			if (*temp != *tail){ //当*temp和*tail不相等
//				temp++;
//				if (temp == tail){
//					tail++;
//					temp = head;
//					flag++;
//				}
//			}
//			else{
//				break;
//			}
//		}
//		if (flag>max){
//			max = flag;
//		}
//		flag = 1;
//		head++;
//	}
//	return max;
//}
//int main(){
//	char *a = "au";
//	int c = lengthOfLongestSubstring(a);
//	printf("%d", c);
//	return 0;
//}
void  fun(char *ch){
	scanf("%c", ch);
	if (*ch != '#') fun(ch);
	printf("%c", *ch);
}
int main(){
	char ch = '0';
	fun(&ch);
	return 0;
}