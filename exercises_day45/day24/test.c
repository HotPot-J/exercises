#define _CRT_SECURE_NO_WARNINGS 1
/*
给定一个字符串，请你找出其中不含有重复字符的?最长子串?的长度。

示例?1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是?"wke"，所以其长度为 3。
?    请注意，你的答案必须是 子串 的长度，"pwke"?是一个子序列，不是子串。

	 来源：力扣（LeetCode）
	 链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//双指针暴力法 遍历每一个字串 时间复杂度较高
#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring1(char * s){
	char *head = s;
	char *temp = NULL;//遍历head-tail之间的值
	char *tail = NULL;//新的尾
	int flag = 1;//记录每次的长度 
	int max = 0;//记录最长的长度，作为返回值
	//为空的情况
	if (*head == '\0'){
		return 0;
	}
	//只有一个字符的情况
	if (*(head + 1) == '\0'){
		return 1;
	}
	//普通情况
	while (*head){//head走
		temp = head;
		tail = head + 1;
		while (*tail){//尾巴走
			if (*temp != *tail){ //当*temp和*tail不相等
				temp++;
				if (temp == tail){
					tail++;
					temp = head;
					flag++;
				}
			}
			else{
				break;
			}
		}
		if (flag>max){
			max = flag;
		}
		flag = 1;
		head++;
	}
	return max;
}

//双指针  用哈希表来作为滑动窗口来判断的方法 时间复杂度O（n）
char HashMap[256] ;//设置哈希表对应ascii表  例如：HashMap[a] 即a的ascii码为97即代表HashMap[97]
int Hash(char a){
	if (HashMap[a]){
		return 1;//说明该字符存在于窗口中
	}
	return 0; //不存在于窗口中
}
int lengthOfLongestSubstring(char * s){
	char *top = s, *tail = s;
	int  ret = 0,flag = 0;
	memset(HashMap, 0, sizeof(HashMap));
	if (s == NULL){
		return 0;
	}
	if (s[0] == '\0'){
		return 0;
	}
	while (*tail){
		if (Hash(*tail)){ // 说明存在于当前窗口
			flag = tail - top;
			if (flag >= ret){
				ret = flag;
			}
			while (*top != *tail){
				HashMap[*top] = '\0';
				top++;
			}
			HashMap[*tail] = '\0';
			top++;
		}
		else{//不存在于当前窗口
			HashMap[*tail] = *tail;//将其放入哈希表中
			tail++;
		}
	}
	flag = tail - top;
	if (flag > ret){
		ret = flag;
	}
	return ret;
}
int main(){
	char* s = " ";
	printf("%d", lengthOfLongestSubstring(s));
	return 0;
}