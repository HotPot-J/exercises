#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>       
#include<math.h>
#include<stdlib.h>
#include<string.h>


/*
给定两个二进制字符串，返回他们的和（用二进制表示）。

输入为非空字符串且只包含数字?1?和?0。

示例?1:

输入: a = "11", b = "1"
输出: "100"
示例?2:

输入: a = "1010", b = "1011"
输出: "10101"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//思路 从个位开始相加 所以先将两个字符串翻转  进行运算后将结果翻转则得到结果
void rev(char* a){
	char* top = a;
	char* tail = a + strlen(a) - 1;
	char tmp = '0';
	while (top<tail){
		tmp = *top;
		*top = *tail;
		*tail = tmp;
		top++;
		tail--;
	}
}

char * addBinary(char * a, char * b){
	int flag = 0;
	char* pa = a;
	char* pb = b;
	char* ret = (char*)malloc(1000);
	int t = 0;
	rev(a);
	rev(b);
	while (*pa&&*pb){
		ret[t++] = (flag + (*pa - '0') + (*pb - '0')) % 2 + '0';//给结果赋值
		flag = (flag + (*pa - '0') + (*pb - '0')) / 2;//给进制位赋值
		pa++;
		pb++;
	}
	while (*pa){
		ret[t++] = (flag + (*pa - '0')) % 2 + '0';
		flag = (flag + (*pa - '0')) / 2;
		pa++;
	}
	while (*pb){
		ret[t++] = (flag + (*pb - '0')) % 2 + '0';
		flag = (flag + (*pb - '0')) / 2;
		pb++;
	}
	if (flag == 1){
		ret[t++] = '1';
	}
	ret[t] = '\0';
	rev(ret);
	return ret;
}

/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。
示例?1:

输入: "42"
输出: 42
示例?2:

输入: "   -42"
输出: -42
解释: 第一个非空白字符为 '-', 它是一个负号。
?    我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
	 示例?3:

	 输入: "4193 with words"
	 输出: 4193
	 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
	 示例?4:

	 输入: "words and 987"
	 输出: 0
	 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。
	 因此无法执行有效的转换。
	 示例?5:

	 输入: "-91283472332"
	 输出: -2147483648
	 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。
	 ?    因此返回 INT_MIN (?231) 。

		  来源：力扣（LeetCode）
		  链接：https://leetcode-cn.com/problems/string-to-integer-atoi
		  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//判断是不是数字 并返回
int Judge(char a){
	switch (a)
	{
	case '-':
		return 10;
	case '+':
		return 11;
	case '0':
		return -1;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		break;
	}
	return 0;
}
int myAtoi(char * str){
	int ret = 0, tmp = 0, t = 0, y = 0;//t判断符号为是否设置过,y判断0是不是有效数字 如果0在第一个非0数字之前则无效
	char* p = str;
	char flag = '\0';//判断正负
	while (*p){
		if ((*p == '-' || *p == '+') && t){
			break;
		}
		if (ret > INT_MAX / 10 || ret == INT_MAX / 10){
			return flag == '-' ? INT_MIN : INT_MAX;
		}
		tmp = Judge(*p);
		if ((*p == ' '||(*p=='0')&&!y)){
			p++;
		}
		else if (tmp){//第一个字符是数字或'-'
			if (!flag&&tmp == 10){
				if (t){
					break;
				}
				flag = '-';
				p++;
				t = 1;
			}
			else if (!flag&&tmp == 11){
				if (t){
					break;
				}
				flag = '+';
				p++;
				t = 1;
			}
			else{
				y = 1;
				if (tmp == -1){
					ret = ret * 10;
					p++;
				}
				else{
					ret = ret * 10 + tmp;
					p++;
				}
			}
		}
		else{//字符不是'-'或数字的情况
				break;
		}
	}
	if (flag == '-'){
		ret = -ret;
	}
	return ret;
}

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

你的算法时间复杂度必须是?O(log n) 级别。

如果数组中不存在目标值，返回?[-1, -1]。

示例 1:

输入: nums = [5,7,7,8,8,10], target = 8
输出: [3,4]
示例?2:

输入: nums = [5,7,7,8,8,10], target = 6
输出: [-1,-1]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
	int *ret = (int*)malloc(sizeof(int)* 2);
	ret[0] = -1; ret[1] = -1;
	int i = 0, t = 0;
	*returnSize = 2;
	for (i = 0; i<numsSize; i++){
		if (t>0){
			t = 1;
		}
		if (nums[i] == target){
			ret[t] = i;
			t++;
		}
	}
	if (ret[0] != -1 && ret[1] == -1){//说明只有一个
		ret[1] = ret[0];
	}
	return ret;
}
int main(){
	int a[6] = { 5, 7, 7, 8, 8, 10 };
	int b = 0;
	//int ret = myAtoi(a);
	int* ret = searchRange(a, 6, 8, &b);
	free(ret);
	ret = NULL;
	//char *ret = addBinary(a, b);
	//free(ret);
	return 0;
}