#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
����һ������N ÿ����һ�� N-1��N+1  ����Ϊ쳲���������ʱ�򷵻���̲���n
*/

//int main(){
//	int N = 0, a = 0, b = 1, c = 1, left = 0, right = 0;
//	scanf("%d", &N);
//	while (1){
//		a = b;
//		b = c;
//		c = a + b;
//		if (c > N){
//			right = c - N;
//			left = N - b;
//			if (right < left){
//				printf("%d", right);
//			}
//			else{
//				printf("%d", left);
//			}
//			break;
//		}
//	}
//	return 0;
//}


/*
��������?�ǿ� ������������ʾ�����Ǹ������������У����Ǹ��Ե�λ���ǰ���?����?�ķ�ʽ�洢�ģ��������ǵ�ÿ���ڵ�ֻ�ܴ洢?һλ?���֡�

��������ǽ��������������������᷵��һ���µ���������ʾ���ǵĺ͡�

�����Լ���������� 0 ֮�⣬���������������� 0?��ͷ��

ʾ����

���룺(2 -> 4 -> 3) + (5 -> 6 -> 4)
�����7 -> 0 -> 8
ԭ��342 + 465 = 807

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/add-two-numbers
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/
 struct ListNode {
     int val;
     struct ListNode *next;
 };

 typedef struct ListNode ListNode;
 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
	 ListNode *head = (ListNode *)malloc(sizeof(ListNode));
	 ListNode *tail = head;
	 ListNode *newNode = NULL;
	 int ret = 0;//������ β�����µ�����
	 int temp = 0;//�����λ
	 while (l1&&l2){
		 ret = 0;
		 ret = l1->val + l2->val;
		 newNode = (ListNode *)malloc(sizeof(ListNode));
		 newNode->val = (ret + temp) % 10;
		 tail->next = newNode; //β��
		 newNode->next = NULL;
		 tail = tail->next;
		 l1 = l1->next;
		 l2 = l2->next;
		 if ((ret + temp) >= 10){//���Ƿ��λ���в���
			 temp = 1;
		 }
		 else{
			 temp = 0;
		 }
	 }
	 if (l1 == NULL){//l1������ ֱ�Ӱ�l2β�嵽head���
		 while (l2){
			 newNode = (ListNode *)malloc(sizeof(ListNode));
			 newNode->val = (l2->val + temp) % 10;//(֮ǰ�����������н�λ)
			 if ((l2->val + temp) >= 10){
				 temp = 1;
			 }
			 else{
				 temp = 0;
			 }
			 tail->next = newNode; //β�� 
			 newNode->next = NULL;
			 tail = tail->next;
			 l2 = l2->next;
		 }
	 }
	 if (l2 == NULL){//l2������ ֱ�Ӱ�l1β�嵽head���
		 while (l1){
			 newNode = (ListNode *)malloc(sizeof(ListNode));
			 newNode->val = (l1->val + temp) % 10;//(֮ǰ�����������н�λ)
			 if ((l1->val + temp) >= 10){
				 temp = 1;
			 }
			 else{
				 temp = 0;
			 }
			 tail->next = newNode; //β�� 
			 newNode->next = NULL;
			 tail = tail->next;
			 l1 = l1->next;
		 }
	 }
	 if (l1 == NULL&&l2 == NULL&&temp == 1){//l1��l2���������н�λ ��ʱ�ɽ�����һλβ�嵽��������
		 newNode = (ListNode *)malloc(sizeof(ListNode));
		 newNode->val = temp;
		 tail->next = newNode; //β��
		 newNode->next = NULL;
		 tail = tail->next;
	 }
	 tail = head->next;
	 free(head);
	 return tail;
 }