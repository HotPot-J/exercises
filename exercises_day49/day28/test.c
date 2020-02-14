#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
给定 S 和 T 两个字符串，当它们分别被输入到空白的文本编辑器后，判断二者是否相等，并返回结果。 # 代表退格字符。
 示例 1：
 输入：S = "ab#c", T = "ad#c"
 输出：true
 解释：S 和 T 都会变成 “ac”。
 示例 2：
 输入：S = "ab##", T = "c#d#"
 输出：true
 解释：S 和 T 都会变成 “”。
 示例 3：
 输入：S = "a##c", T = "#a#c"
 输出：true
 解释：S 和 T 都会变成 “c”。
 示例 4：
 输入：S = "a#c", T = "b"
 输出：false
 解释：S 会变成 “c”，但 T 仍然是 “b”。
  提示：
  1 <= S.length <= 200
  1 <= T.length <= 200
  S 和 T 只含有小写字母以及字符 '#'。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/backspace-string-compare
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//思路：让两个数组的元素依次入栈 当前指针解引用若是#并且当前栈内有字母 就让字母出栈 最终判断两个栈是否相等即可
int Stackpp(char* p,char *Stack){
	int i = -1;
	while (*p){
		if (*p >= 'a'&&*p <= 'z'){
			Stack[++i] = *p;
		}
		else if (*p == '#'){
			if (i != -1){ //当前栈不为空
				i--;
			}
		}
		p++;
	}
	return i;
}
int backspaceCompare(char * S, char * T){
	char *StackS = (char*)malloc(sizeof(char)* 201);
	char *StackT = (char*)malloc(sizeof(char)* 201);
	int i = 0, j = 0;
	i = Stackpp(S, StackS);
	j = Stackpp(T, StackT);
	if (i != j){
		return -1;
	}
	else{
		for (i = 0; i <= j; i++){
			if (StackS[i] != StackT[i]){
				return -1;
			}
		}
	}
	return 1;
}

/*
在由若干?0?和?1? 组成的数组?A?中，有多少个和为 S?的非空子数组。

 示例：

 输入：A = [1,0,1,0,1], S = 2
 输出：4
 解释：
 如下面黑体所示，有 4 个满足题目要求的子数组：
 [1,0,1,0,1]
 [1,0,1,0,1]
 [1,0,1,0,1]
 [1,0,1,0,1]
 ?
  提示：
  A.length <= 30000
  0 <= S <= A.length
  A[i]?为?0?或?1

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/binary-subarrays-with-sum
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//用滑动窗口算法
int numSubarraysWithSum(int* A, int ASize, int S){
	//特判
	if (ASize == 0){
		return 0;
	}
	int* top = A, *tail = A+1;
	int sum = *top; int ret = 0;
	while (top < A + ASize){
			if (sum < S){
				if (tail >= A + ASize){
					break;
				}
				sum += *tail;
				tail++;
			}
			else if (sum >S){
				sum -= *top;
				top++;
			}
			else {
				ret++;
				if (tail < A + ASize){
					sum += *tail;
					tail++;
				}
				else{
					sum -= *top;
					top++;
				}
			}
	}
	return ret;
}
int main(){
	int a[5] = { 0, 0, 0, 0, 0 };
	numSubarraysWithSum(a, 5, 0);
	return 0;
}