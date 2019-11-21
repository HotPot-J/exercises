#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h> //���ļ�ֻ���ڱ����㷨
/*ɾ�������е��ڸ���ֵ val �����нڵ㡣
ʾ�� :
���� : 1->2->6->3->4->5->6, val = 6
��� : 1->2->3->4->5
*/

//����һ �������� ����һǰһ������ָ�����ɾ��
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
	 //��ֻ����һ���ڵ�����val��ȵ�ʱ��
	 if (newhead->data == val&&newhead->next == NULL){
		 free(head);
		 newhead = NULL;
		 return newhead;
	 }
	 tail = newhead->next;
	 if (tail == NULL){
		 return newhead;
	 }
	 while (head->next != NULL || head->data == val){//�ٽ�����  ��head->data == val��������Ϊ�˷�ֹĳһ�κ��� head��Ϊ���һ������val��ȵ��������Ȼ�ɽ���ѭ������ɾ��
		 //�����һ���ڵ����val
		 if (newhead->data == val&&head->data == val&&head->next != NULL){//��&head->next != NULL��������Ϊ�˷�ֹɾ��ֻʣ���һ����ʱ�� ѭ�������������������ɾ�����һ���ڵ��������� 
			 free(head);
			 head = newhead = tail;
			 if (tail->next != NULL){
				 tail = tail->next;
			 }
		 }
		 else if (tail->data == val&&tail->next != NULL){//��ͨ���
			 head->next = tail->next;
			 free(tail);
			 tail = head->next;
		 }
		 else if (tail->data == val&&tail->next == NULL){//���һ���ڵ�Ϊval
			 if (newhead->next == NULL){ //���ֻʣ����һ���ڵ�
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
 // ����ÿһ������Ŀ��val��ֵ����β��  ��Ŀ�����free��
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
 
 //��תһ�������� 
 //�÷���Ϊ�� ������һ����ʱͷ�ڵ� ��ǰ���� ��ÿ���ڵ�ͷ�� �ﵽ��ת��Ч��
 typedef struct SListNode SListNode;
 struct SListNode* reverseList(struct SListNode* head){
	 SListNode *Head = (SListNode *)malloc(sizeof(SListNode));
	 Head->data = 0; Head->next = NULL;
	 SListNode *ret = NULL; // ��Զָ��ͷ����½ڵ� ����Ϊ����ֵ����
	SListNode *newhead = head;//ָ��ǰ���������
	 SListNode *next = NULL;
	 if (head != NULL){//��������ֹ����һ��������ʱ nextԽ�����
		 next = head->next;//ָ����һ�����������
	 }
	 while (newhead){
		 if (newhead == head){ //�����һ�����
			 Head->next = newhead;
			 newhead->next = NULL;
			 newhead = next;
			 if (next != NULL){ //��ֹheadֻ��һ�����
				 next = next->next;
			 }
			 ret = Head->next;
		 }
		 else{   //����������ͷ��
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