#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：


左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。


注意空字符串可被认为是有效字符串。

示例 1:

输入: "()"
输出: true


示例 2:

输入: "()[]{}"
输出: true


示例 3:

输入: "(]"
输出: false


示例 4:

输入: "([)]"
输出: false


示例 5:

输入: "{[]}"
输出: true

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
	ps->top = 0; //表示栈为空
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
			if (StackEmpty(&ps) == 1){  //如果此时栈为空 说明没有匹配的  例如 s = （）） 或 s = ）的情况
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

