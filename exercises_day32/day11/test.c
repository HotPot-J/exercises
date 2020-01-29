#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入 : "A man, a plan, a canal: Panama"
输出 : true
	 示例 2 :

 输入 : "race a car"
  输出 : false

	   来源：力扣（LeetCode）
   链接：https ://leetcode-cn.com/problems/valid-palindrome
	 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
	 */
int isPalindrome(char * s){
	char* top = s;
	char* tail = NULL;
	if (s == NULL){
		return 1;
	}
	tail = s + strlen(s) - 1;
	while (top<tail){
		if (((*top >= 'a'&&*top <= 'z') || (*top >= 'A'&&*top <= 'Z')) && ((*tail >= 'a'&&*tail <= 'z') || (*tail >= 'A'&&*tail <= 'Z'))){//top和tail都属于字母
			if ((*top == *tail) || (*top + 32 == *tail + 0) || (*top - 32 == *tail + 0) || (*top + 0 == *tail + 32) || (*top + 0 == *tail - 32)){
				top++;
				tail--;
			}
			else{
				return 0;
			}
		}
		else if ((*top >= '0'&&*top <= '9') && (*tail >= '0'&&*tail <= '9')){//都是数字
			if (*top == *tail){
				top++;
				tail--;
			}
			else{
				return 0;
			}
		}
		else if ((*top >= 'a'&&*top <= 'z') || (*top >= 'A'&&*top <= 'Z')){//top和tail只有一个是字母
			if (*tail >= '0'&&*tail <= '9'){
				return 0;
			}
			else{
				tail--;
			}
		}
		else if ((*tail >= 'a'&&*tail <= 'z') || (*tail >= 'A'&&*tail <= 'Z')){
			if ((*top >= '0'&&*top <= '9')){
				return 0;
			}
			else{
				top++;
			}
		}
		else if ((*top >= '0'&&*top <= '9')){  //只有一个是数字
			if ((*tail >= 'a'&&*tail <= 'z') || (*tail >= 'A'&&*tail <= 'Z')){
				return 0;
			}
			else{
				tail--;
			}
		}
		else if ((*tail >= '0'&&*tail <= '9')){
			if ((*top >= 'a'&&*top <= 'z') || (*top >= 'A'&&*top <= 'Z')){
				return 1;
			}
			else{
				top++;
			}
		}
		else{ //都不是字母
			top++;
			tail--;
		}
	}
	return 1;
}

/*
给定一组字符，使用原地算法将其压缩。

压缩后的长度必须始终小于或等于原数组长度。

数组的每个元素应该是长度为1?的字符（不是 int 整数类型）。

在完成原地修改输入数组后，返回数组的新长度。

?

 进阶：
 你能否仅使用O(1) 空间解决问题？

 ?

  示例 1：

  输入：
  ["a","a","b","b","c","c","c"]

  输出：
  返回6，输入数组的前6个字符应该是：["a","2","b","2","c","3"]

  说明：
  "aa"被"a2"替代。"bb"被"b2"替代。"ccc"被"c3"替代。

  来源：力扣（LeetCode）
  链接：https://leetcode-cn.com/problems/string-compression
  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int compress(char* chars, int charsSize){
	char*top = chars;
	char*tail = chars;
	char* change = chars;
	int changeRet = 0;
	int flag = 0;
	while (*top){
		flag = 0;
		while (*top == *tail){
			tail++;
			flag++;
			if (!(*tail)){
				break;
			}
		}
		if (flag>1){
			*(change+1) = flag+'0';
			top = tail;
			change+=2;
			changeRet += 2;
		}
		else{
			change++;
			changeRet++;
		}
	}
	return changeRet;
}
int main(){
	char a[] = "aabbccc";
	//isPalindrome(a);
	compress(a, 7);
	return 0;
}