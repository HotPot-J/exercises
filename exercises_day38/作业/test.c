#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
2.�ýṹ���ָ�룬��ɵ�����Ĵ�����˳�������ķ��ʵ������ÿ��Ԫ�� ���赥�����е���������λint
*/
typedef struct SListNode{
	int data; //data�������
	struct SListNode *next;//nextָ����һ���ڵ�
}SListNode;

//��������Ľӿ�
SListNode* BuySListNode(int x){   //����һ���µĽڵ� 
	SListNode *Node = (SListNode*)malloc(sizeof(SListNode));//ʹ��malloc��������һ���ڵ��С�Ŀռ�  
	//�����Ƿ���ֵ����    //����������ռ��С
	Node->data = x;     //��x��ֵ���½ڵ��data
	Node->next = NULL; //�µĽڵ� ����nextָ��� �����next��ֵΪʲô ��������Ҫ�Ĳ��� �������ӿ�ʵ��
	return Node;  //��������½ڵ�
}
void SListPushFront(SListNode** pplist, int x){  //ͷ��
	SListNode *NewNode = BuySListNode(x);  //���������BuySListNode���� ����һ���µĽڵ�
	if (*pplist == NULL){   //*pplist==NULL  ��ʾ��ʱ������ǵ�һ���ڵ� ֱ����*pplistָ���һ���ڵ㼴��
		*pplist = NewNode;
	}
	else{//���� �ýڵ㲻�ǵ�һ���ڵ�Ĵ������
		NewNode->next = *pplist;  //���½ڵ��nextָ��*pplist  ��ͷ���Ч��
		*pplist = NewNode; //��*pplistָ���½ڵ� ������һ��ͷ��
	}
}

void SListprintP(SListNode **pplist){ //��ǰ������ʲ����  Ĭ��pplist��ָ��λ��Ϊǰ
	SListNode *cur = *pplist;
	while (cur){
		printf(" -> %d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SListprintR(SListNode **pplist){ //�Ӻ���ǰ���ʲ����
	SListNode *f = *pplist;     //��Զ��r��ǰһ��λ��
	SListNode *r = (*pplist)->next;//��Զ��f�ĺ�һ��λ�� 
	while ((*pplist)->next){ 
		while (r->next) //��cur��next��Ϊ�� ˵���������һ������ cur��һֱ������ ֱ���ҵ����һ������ ѭ������
		{    
			r = r->next;
			f = f->next;
		}
		printf("%d <- ", r->data);
		f->next = NULL; //�������ڶ����� �����Ϊ���һ������
		f = *pplist;
		r = (*pplist)->next;
	}
	printf("%d", (*pplist)->data);
}

//����
int main(){
	SListNode *plist = NULL;
	//����һ�� Ϊ1 2 3 4 5�ĵ����� ��Ϊ����ʵ�ֵ���ͷ�� �����ڴ�������ʱ�򷴹�����
	SListPushFront(&plist, 5); 
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	//��ǰ������ʲ����
	SListprintP(&plist);
	//�Ӻ���ǰ���ʲ����
	SListprintR(&plist);
	return 0;
}
/*
3.ʹ��ѭ���͵ݹ����ַ�ʽʵ��1+2+...+n
*/
//ѭ��
int Sum1(int n){
	int i = 0;
	int sum = 0;
	for (i = 1; i <= n; i++){
		sum += i;
	}
	return sum;
}
//�ݹ�
int Sum2(int n){
	if (n == 1){
		return 1;
	}
	else{
		return n + Sum2(n - 1);
	}
}
//����
//int main(){
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d,%d", Sum1(n), Sum2(n));
//	return 0;
//}

/*
6.�θ�һ��ʮ������ �ӵ͵������ �Ӹߵ��� 
*/
void PrintNum(int n){
	int tmp = n; //��n��ֵ��tmp ��ֹ�ڴ�������и���n��ֵ
	printf("�Ӹߵ��ͣ�");
	while (tmp){
		printf("%d",tmp%10 );//������һ������
		tmp /= 10; //ÿ�μ������һ������
	}
	printf("\n�Ӹߵ��ͣ�%d\n", n);
}
//����
//int main(){
//	int n = 0;
//	scanf("%d", &n);
//	PrintNum(n);
//	return 0;
//}

/*
8.ѧУ��֯ʵ���ǼǾ�ÿ�˾��ֻ����10Ԫ��20��30��40��50��60��70��80��90��100Ԫ֮һ ͳ����Ӧ����������ռ���
�������İٷֱ�
*/
void fun(int *a,int len){ //a��Ϊ������������ �����鱣��������Ǯ����ֵ 
	int ret[10] = { 0 };// ֻ�轫10 - 100Ԫ��ֵ�ĸ��������Լ������ret������
	int i = 0;
	for (i = 0; i < len; i++){ //�ҳ�ÿ����ֵ�ĸ����ж���
		if (a[i] == 10){
			ret[0] += 1;
		}
		else if (a[i] == 20){
			ret[1] += 1;
		}
		else if (a[i] == 30){
			ret[2] += 1;
		}
		else if (a[i] == 40){
			ret[3] += 1;
		}
		else if (a[i] == 50){
			ret[4] += 1;
		}
		else if (a[i] == 60){
			ret[5] += 1;
		}
		else if (a[i] == 70){
			ret[6] += 1;
		}
		else if (a[i] == 80){
			ret[7] += 1;
		}
		else if (a[i] == 90){
			ret[8] += 1;
		}
		else {
			ret[9] += 1;
		}
	}
	for (i = 1; i <= 10;i++){//���
		printf("��ֵΪ%d�������У�%d,��ռ�ٷ�֮%f\n", i * 10, ret[i],((double)ret[i] / (double)len) * 100.0);
	}
}
//����
//int main(){
//	int a[12] = { 10,30,20,50,40,60,70,80,30,90,100,40 };
//	fun(a, 12);
//	return 0;
//}
