#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int lengthOfLongestSubstring(char * s){
//	char *head = s;
//	char *temp = NULL;//����head-tail֮���ֵ
//	char *tail = NULL;//�µ�β
//	int flag = 1;//��¼ÿ�εĳ��� 
//	int max = 0;//��¼��ĳ��ȣ���Ϊ����ֵ
//	//Ϊ�յ����
//	if (*head == '\0'){
//		return 0;
//	}
//	//ֻ��һ���ַ������
//	if (*(head + 1) == '\0'){
//		return 1;
//	}
//	//��ͨ���
//	while (*head){//head��
//		temp = head;
//		tail = head + 1;
//		while (*tail){//β����
//			if (*temp != *tail){ //��*temp��*tail�����
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