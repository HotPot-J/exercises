#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//�ݹ�
/*
СA �� СB ��������֡�СB ÿ�δ� 1, 2, 3 �����ѡ��һ����СA ÿ��Ҳ�� 1, 2, 3 ��ѡ��һ���¡�����һ���������������Ϸ���뷵�� СA �¶��˼��Σ�
�����guess����Ϊ СA ÿ�εĲ²⣬answer����Ϊ СB ÿ�ε�ѡ��guess��answer�ĳ��ȶ�����3
���룺guess = [1,2,3], answer = [1,2,3]
�����3
���ͣ�СA ÿ�ζ��¶��ˡ�

ʾ�� 2��
���룺guess = [2,2,3], answer = [3,2,1]
�����1
���ͣ�СA ֻ�¶��˵ڶ��Ρ�
*/
int game(int* guess, int guessSize, int* answer, int answerSize){
	if (guessSize == 0){
		return 0;
	}
	if (guess[guessSize-1] == answer[answerSize-1]){
		return game(guess, --guessSize, answer, --answerSize) + 1;
	}
	else{
		return game(guess, --guessSize, answer, --answerSize);
	}
}


