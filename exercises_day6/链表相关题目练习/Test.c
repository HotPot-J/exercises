#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> //该文件只用于保存算法
/*删除链表中等于给定值 val 的所有节点。
示例 :
输入 : 1->2->6->3->4->5->6, val = 6
输出 : 1->2->3->4->5
*/

//方法一 基础方法 设置一前一后两个指针进行删除
typedef struct SListNode{
	int data;
	struct SListNode *next;
}SListNode;
 struct SListNode* removeElements(SListNode* head, int val){
	 SListNode *newhead = head;
	 SListNode *tail = NULL;
	 if (newhead == NULL){
		 return newhead;
	 }
	 //当只存在一个节点且与val相等的时候
	 if (newhead->data == val&&newhead->next == NULL){
		 free(head);
		 newhead = NULL;
		 return newhead;
	 }
	 tail = newhead->next;
	 if (tail == NULL){
		 return newhead;
	 }
	 while (head->next != NULL || head->data == val){//临界条件  “head->data == val”该条件为了防止某一次后移 head成为最后一个且与val相等的情况下仍然可进入循环将其删除
		 //如果第一个节点就是val
		 if (newhead->data == val&&head->data == val&&head->next != NULL){//“&head->next != NULL”该条件为了防止删的只剩最后一个的时候 循环进入该条件语句而不是删除最后一个节点的条件语句 
			 free(head);
			 head = newhead = tail;
			 if (tail->next != NULL){
				 tail = tail->next;
			 }
		 }
		 else if (tail->data == val&&tail->next != NULL){//普通情况
			 head->next = tail->next;
			 free(tail);
			 tail = head->next;
		 }
		 else if (tail->data == val&&tail->next == NULL){//最后一个节点为val
			 if (newhead->next == NULL){ //如果只剩下这一个节点
				 free(head);
				 newhead = NULL;
				 return newhead;
			 }
			 head->next = NULL;
			 free(tail);
			 return newhead;
		 }
		 else{
			 head = tail;
			 if (tail->next != NULL){
				 tail = tail->next;
			 }
			 else{
				 return newhead;
			 }
		 }
	 }
	 return newhead;
 }
 // 对于每一个不是目标val的值进行尾插  是目标的则free掉
 struct SListNode* removeElements(SListNode* head, int val){
	 SListNode *newhead = (SListNode *)malloc(sizeof(SListNode));
	 newhead->data = 0;  newhead->next = NULL;
	 SListNode *temp = head;
	 SListNode *newtail = newhead;
	 if (head == NULL){
		 return head;
	 }
	 while (head != NULL){
		 if (head->data != val){
			 newtail->next = head;
			 newtail = head;
			 head = head->next;
			 temp = head;
			 newtail->next = NULL;
		 }
		 else{
			 head = head->next;
			 free(temp);
			 temp = head;
		 }
		 if (head == NULL){
			 break;
		 }
	 }
	 temp = newhead->next;
	 free(newhead);
	 return temp;
 }
 
 //反转一个单链表。 
 //该方法为： 创建了一个临时头节点 从前到后 将每个节点头插 达到反转的效果
 typedef struct SListNode SListNode;
 struct SListNode* reverseList(struct SListNode* head){
	 SListNode *Head = (SListNode *)malloc(sizeof(SListNode));
	 Head->data = 0; Head->next = NULL;
	 SListNode *ret = NULL; // 永远指向头插的新节点 并作为返回值返回
	SListNode *newhead = head;//指向当前处理的数据
	 SListNode *next = NULL;
	 if (head != NULL){//该条件防止传入一个空链表时 next越界访问
		 next = head->next;//指向下一个处理的数据
	 }
	 while (newhead){
		 if (newhead == head){ //处理第一个结点
			 Head->next = newhead;
			 newhead->next = NULL;
			 newhead = next;
			 if (next != NULL){ //防止head只有一个结点
				 next = next->next;
			 }
			 ret = Head->next;
		 }
		 else{   //其余数据做头插
			 Head->next = newhead;
			 newhead->next = ret;
			 ret = Head->next;
			 newhead = next;
			 if (next != NULL){
				 next = next->next;
			 }
		 }
	 }
	 free(Head);
	 return ret;
 }