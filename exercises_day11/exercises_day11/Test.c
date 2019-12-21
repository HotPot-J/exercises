#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ������ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺


�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�


ע����ַ����ɱ���Ϊ����Ч�ַ�����

ʾ�� 1:

����: "()"
���: true


ʾ�� 2:

����: "()[]{}"
���: true


ʾ�� 3:

����: "(]"
���: false


ʾ�� 4:

����: "([)]"
���: false


ʾ�� 5:

����: "{[]}"
���: true

*/
typedef char STDataType;
typedef struct Stack{
	STDataType *a;
	int top;
	int capacity;
}Stack;
void StackInit(Stack* ps){
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0; //��ʾջΪ��
}
void printStack(Stack *ps){
	int i = 0;
	for (i = 0; i <ps->top; i++){
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
void StackPush(Stack* ps, STDataType x){
	assert(ps);
	if (ps->top == ps->capacity){
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (STDataType*)realloc(ps->a, sizeof(STDataType)*newcapacity);
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void Stackpop(Stack *ps){
	assert(ps);
	if (ps->top > 0){
		ps->top--;
	}
}
STDataType StackTop(Stack* ps){
	assert(ps);
	return ps->a[ps->top - 1];
}
int StackEmpty(Stack* ps){
	assert(ps);
	return ps->top == 0 ? 1 : 0;
}
void StackDestory(Stack* ps){

	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = 0;
}

int isValid(char * s){
	char* S = s;
	Stack ps;
	StackInit(&ps);
	while (*S){
		if (*S == '(' || *S == '{' || *S == '['){
			StackPush(&ps, *S);
		}
		else{
			if (StackEmpty(&ps) == 1){  //�����ʱջΪ�� ˵��û��ƥ���  ���� s = ������ �� s = �������
				return 0;
			}
			char top = StackTop(&ps);
			Stackpop(&ps);
			if (*S == ']' && top == '['){
				S++;
				continue;
			}
			else if (*S == ')' && top == '('){
				S++;
				continue;
			}
			else if (*S == '}' && top == '{'){
				S++;
				continue;
			}
			else{
				return 0;
			}

		}
		S++;
	}
	int ret = StackEmpty(&ps) == 1;
	StackDestory(&ps);
	return ret;
}

