#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
392. 判断子序列
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
你可以认为 s 和 t 中仅包含英文小写字母。字符串 t 可能会很长（长度 ~= 500,000），而 s 是个短字符串（长度 <=100）。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
示例 1:
s = "abc", t = "ahbgdc"
返回 true.
示例 2:
s = "axc", t = "ahbgdc"
返回 false.
*/
int isSubsequence(char * s, char * t){
	char* sp = s;
	char* tp = t;
	while (*sp&&*tp){
		if (*sp == *tp){
			sp++;
		}
		tp++;
	}
	if (*sp){
		return -1;
	}
	else{
		return 1;
	}
}
//int main(){
//	char *s = "axc";
//	char *t = "ahbgdc";
//	isSubsequence(s, t);
//	return 0;
//}

/*
1046. 最后一块石头的重量
有一堆石头，每块石头的重量都是正整数。
每一回合，从中选出两块最重的石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
提示：
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/
int cmp(const void*a, const void*b){
	return *(int*)a > *(int*)b;
}
int lastStoneWeight(int* stones, int stonesSize){
	int tmp = 0;
	while (stonesSize > 1){
		qsort(stones, stonesSize, sizeof(int), cmp);
		if (stones[stonesSize - 1] == stones[stonesSize - 2]){
			stonesSize -= 2;
		}
		else{
			stones[stonesSize - 2] = stones[stonesSize - 1] - stones[stonesSize - 2];
			stonesSize--;
		}
	}
	if (stonesSize == 0){
		return 0;
	}
	else{
		return stones[0];
	}
}

/*
860. 柠檬水找零
在柠檬水摊上，每一杯柠檬水的售价为 5 美元。
顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。
每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。
注意，一开始你手头没有任何零钱。
如果你能给每位顾客正确找零，返回 true ，否则返回 false 。
示例 1：
输入：[5,5,5,10,20]
输出：true
解释：
前 3 位顾客那里，我们按顺序收取 3 张 5 美元的钞票。
第 4 位顾客那里，我们收取一张 10 美元的钞票，并返还 5 美元。
第 5 位顾客那里，我们找还一张 10 美元的钞票和一张 5 美元的钞票。
由于所有客户都得到了正确的找零，所以我们输出 true。
示例 2：
输入：[5,5,10]
输出：true
示例 3：
输入：[10,10]
输出：false
示例 4：
输入：[5,5,10,10,20]
输出：false
解释：
前 2 位顾客那里，我们按顺序收取 2 张 5 美元的钞票。
对于接下来的 2 位顾客，我们收取一张 10 美元的钞票，然后返还 5 美元。
对于最后一位顾客，我们无法退回 15 美元，因为我们现在只有两张 10 美元的钞票。
由于不是每位顾客都得到了正确的找零，所以答案是 false。
*/

//思路：设置1个数组用来放收到的钱 总是优先用大的钱+小的钱找给顾客 这样才会有更多的零钱
int lemonadeChange(int* bills, int billsSize){
     //a[0]表示5元面额的钱 a[1]表示10元面额的
	int i = 0, tmp = 0;
	int a[2] = { 0, 0 };
	for (i = 0; i < billsSize; i++){
		tmp = bills[i];
		while (tmp>10){
			if (!a[1]){ //没10元的面值了
				break;
			}
			tmp -= 10;
			a[1]--;
		}
		while (tmp > 5){
			if (!a[0]){
				break;
			}
			tmp -= 5;
			a[0]--;
		}
		if (tmp == 5){
			if (bills[i] == 10){
				a[1]++;
			}
			else if(bills[i]==5){
				a[0]++;
			}
		}
		else{
			return -1;
		}
	}
	return 1;
}
int main(){
	int a[] = { 5,5,5,10,5,5,10,20,20,20};
	int len = sizeof(a) / sizeof(a[0]);
	lemonadeChange(a, len);
	return 0;
}

