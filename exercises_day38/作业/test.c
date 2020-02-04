#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
2.用结构体和指针，完成单链表的创建，顺序和逆序的访问单链表的每个元素 假设单链表中的数据类型位int
*/
typedef struct SListNode{
	int data; //data存放数据
	struct SListNode *next;//next指向下一个节点
}SListNode;

//创建链表的接口
SListNode* BuySListNode(int x){   //创造一个新的节点 
	SListNode *Node = (SListNode*)malloc(sizeof(SListNode));//使用malloc函数申请一个节点大小的空间  
	//这里是返回值类型    //这里是申请空间大小
	Node->data = x;     //把x赋值给新节点的data
	Node->next = NULL; //新的节点 所以next指向空 具体给next赋值为什么 基于所需要的操作 由其他接口实现
	return Node;  //返回这个新节点
}
void SListPushFront(SListNode** pplist, int x){  //头插
	SListNode *NewNode = BuySListNode(x);  //调用上面的BuySListNode函数 创造一个新的节点
	if (*pplist == NULL){   //*pplist==NULL  表示此时插入的是第一个节点 直接让*pplist指向第一个节点即可
		*pplist = NewNode;
	}
	else{//否则 该节点不是第一个节点的处理情况
		NewNode->next = *pplist;  //让新节点的next指向*pplist  起到头插的效果
		*pplist = NewNode; //让*pplist指向新节点 便于下一次头插
	}
}

void SListprintP(SListNode **pplist){ //从前往后访问并输出  默认pplist所指的位置为前
	SListNode *cur = *pplist;
	while (cur){
		printf(" -> %d", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void SListprintR(SListNode **pplist){ //从后往前访问并输出
	SListNode *f = *pplist;     //永远在r的前一个位置
	SListNode *r = (*pplist)->next;//永远在f的后一个位置 
	while ((*pplist)->next){ 
		while (r->next) //当cur的next不为空 说明不是最后一个数据 cur就一直往后找 直到找到最后一个数据 循环结束
		{    
			r = r->next;
			f = f->next;
		}
		printf("%d <- ", r->data);
		f->next = NULL; //将倒数第二个空 是其成为最后一个数据
		f = *pplist;
		r = (*pplist)->next;
	}
	printf("%d", (*pplist)->data);
}

//测试
int main(){
	SListNode *plist = NULL;
	//创建一个 为1 2 3 4 5的单链表 因为我们实现的是头插 所以在传参数的时候反过来传
	SListPushFront(&plist, 5); 
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);
	//从前往后访问并输出
	SListprintP(&plist);
	//从后往前访问并输出
	SListprintR(&plist);
	return 0;
}
/*
3.使用循环和递归两种方式实现1+2+...+n
*/
//循环
int Sum1(int n){
	int i = 0;
	int sum = 0;
	for (i = 1; i <= n; i++){
		sum += i;
	}
	return sum;
}
//递归
int Sum2(int n){
	if (n == 1){
		return 1;
	}
	else{
		return n + Sum2(n - 1);
	}
}
//测试
//int main(){
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d,%d", Sum1(n), Sum2(n));
//	return 0;
//}

/*
6.任给一个十进制数 从低到高输出 从高到低 
*/
void PrintNum(int n){
	int tmp = n; //将n赋值给tmp 防止在处理过程中更改n的值
	printf("从高到低：");
	while (tmp){
		printf("%d",tmp%10 );//输出最后一个数字
		tmp /= 10; //每次减少最后一个数字
	}
	printf("\n从高到低：%d\n", n);
}
//测试
//int main(){
//	int n = 0;
//	scanf("%d", &n);
//	PrintNum(n);
//	return 0;
//}

/*
8.学校组织实名登记捐款，每人捐款只能是10元，20，30，40，50，60，70，80，90，100元之一 统计相应捐款的人数及占捐款
总人数的百分比
*/
void fun(int *a,int len){ //a即为传过来的数组 该数组保存有所有钱的面值 
	int ret[10] = { 0 };// 只需将10 - 100元面值的个数存在自己定义的ret数组中
	int i = 0;
	for (i = 0; i < len; i++){ //找出每种面值的个数有多少
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
	for (i = 1; i <= 10;i++){//输出
		printf("面值为%d的人数有：%d,所占百分之%f\n", i * 10, ret[i],((double)ret[i] / (double)len) * 100.0);
	}
}
//测试
//int main(){
//	int a[12] = { 10,30,20,50,40,60,70,80,30,90,100,40 };
//	fun(a, 12);
//	return 0;
//}
