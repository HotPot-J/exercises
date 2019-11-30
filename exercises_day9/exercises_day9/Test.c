#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
/*
输入一个数字N 每次走一步 N-1或N+1  当其为斐波那契数的时候返回最短步数n
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
给出两个?非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照?逆序?的方式存储的，并且它们的每个节点只能存储?一位?数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0?开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
	 int ret = 0;//保存结果 尾插入新的链表
	 int temp = 0;//保存进位
	 while (l1&&l2){
		 ret = 0;
		 ret = l1->val + l2->val;
		 newNode = (ListNode *)malloc(sizeof(ListNode));
		 newNode->val = (ret + temp) % 10;
		 tail->next = newNode; //尾插
		 newNode->next = NULL;
		 tail = tail->next;
		 l1 = l1->next;
		 l2 = l2->next;
		 if ((ret + temp) >= 10){//对是否进位进行操作
			 temp = 1;
		 }
		 else{
			 temp = 0;
		 }
	 }
	 if (l1 == NULL){//l1走完了 直接把l2尾插到head后边
		 while (l2){
			 newNode = (ListNode *)malloc(sizeof(ListNode));
			 newNode->val = (l2->val + temp) % 10;//(之前运算结果可能有进位)
			 if ((l2->val + temp) >= 10){
				 temp = 1;
			 }
			 else{
				 temp = 0;
			 }
			 tail->next = newNode; //尾插 
			 newNode->next = NULL;
			 tail = tail->next;
			 l2 = l2->next;
		 }
	 }
	 if (l2 == NULL){//l2走完了 直接把l1尾插到head后边
		 while (l1){
			 newNode = (ListNode *)malloc(sizeof(ListNode));
			 newNode->val = (l1->val + temp) % 10;//(之前运算结果可能有进位)
			 if ((l1->val + temp) >= 10){
				 temp = 1;
			 }
			 else{
				 temp = 0;
			 }
			 tail->next = newNode; //尾插 
			 newNode->next = NULL;
			 tail = tail->next;
			 l1 = l1->next;
		 }
	 }
	 if (l1 == NULL&&l2 == NULL&&temp == 1){//l1和l2都走完且有进位 此时吧进的哪一位尾插到新链表中
		 newNode = (ListNode *)malloc(sizeof(ListNode));
		 newNode->val = temp;
		 tail->next = newNode; //尾插
		 newNode->next = NULL;
		 tail = tail->next;
	 }
	 tail = head->next;
	 free(head);
	 return tail;
 }