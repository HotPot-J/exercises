#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
/*
给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。

如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指仅由字母组成、不包含任何空格的 最大子字符串。

 

 示例:

 输入: "Hello World"
 输出: 5

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/length-of-last-word
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
int lengthOfLastWord(char * s){
	char* p = s;
	char* p2 = s;
	char* flag = NULL;
	int ret = 0;
	while (*p){
		//定位最后一个单词的前一个位置
		if (*p == ' '&& (*(p+1)!=' '&& *(p+1)!='\0')){ 
			flag = p;
		}
		p++;
	}
	if (flag != NULL){ //说明定位到直接计算即可
			flag++;
			while (*flag&& *flag!=' '){
				ret++;
				flag++;
			}
	}
	else{  //说明只有一个单词且该单词的首字母在该字符串起始位置
		while (*p2 && *p2 != ' '){
			ret++;
			p2++;
		}
	}
	return ret;
}

/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一： 多开辟一个空间
//void merge(int* nums1, int m, int* nums2,  int n){
//	int a = 0, b = 0, sum = m + n, i = 0;
//	int* n1 = nums1, *n2 = nums2, *r = NULL;
//	int* ret = (int*)malloc(sizeof(int)*sum);
//	r = ret;
//	while (sum--){
//		if (*n1 <= *n2){
//			*r = *n1;
//			r++;
//			n1++;
//			a++;
//		}
//		else{
//			*r = *n2;
//			r++;
//			n2++;
//			b++;
//		}
//		if (a == m){
//			while (b < m){
//				*r = *n2;
//				r++;
//				n2++;
//				b++;
//			}
//		}
//		if (b == n){
//			while (a < n){
//				*r = *n1;
//				r++;
//				n1++;
//				a++;
//			}
//		}
//	}
//	for (i = 0; i <= n + m-1; i++){
//		printf("%d ", ret[i]);
//	}
//	free(ret);
//	ret = NULL;
//}

//方法二： 不多开辟额外空间
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int flag = 0;
	int i = 0, j = 0, l = 0, k = 0, a = m, b = nums1Size;
	if (n > 0){
		for (i = 0; i < b; i++){
			if (l >= n){
				break;
			}
			if (nums2[j] <= nums1[i]){
				for (k = a; k>i; k--){//往后挪
					nums1[k] = nums1[k - 1];
				}
				nums1[i] = nums2[j];
				a++;
				j++;
				l++;
			}
		}
		for (j; j < n; j++){
			nums1[a++] = nums2[j];
		}
	}
	for (i = 0; i < a; i++){
		printf("%d ", nums1[i]);
	}
}
int main(){
	char* s = " Hello    World ";
	//lengthOfLastWord(s);

	int nums1[9] = { 0, 0, 3, 0, 0, 0, 0, 0, 0 };
	int nums2[6] = { -1, 1, 1, 1, 2, 3 };
	merge(nums1, 9, 3, nums2, 3, 6);
	return 0;
}