#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
/*
给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。

(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。)

注意：

你可以假设两个字符串均只含有小写字母。

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
//思路 ：哈希表 将magazine中的字母用哈希表建立索引 遍历ransomNote判断其字母个数是否小于等于magazine中的字母个数
int canConstruct(char * ransomNote, char * magazine){
	char* PR = ransomNote;
	char* PM = magazine;
	int Hash[128] = { 0 };
	if (strlen(ransomNote) > strlen(magazine)){
		return 0;
	}
	while (*PM){
		Hash[*PM]++;
		PM++;
	}
	PM = magazine;
	while (*PR){
		if (Hash[*PR]){
			Hash[*PR]--;
		}
		else{
			break;
		}
		PR++;
	}
	if (!*PR){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	char *a = "aa";
	char *b = "aab";
	canConstruct(a, b);
	return 0;
}