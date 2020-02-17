#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*
1.第12小题求两个数的最小公倍数和最大公约数
2.思路：设两数为a,b 求解最大公约数用辗转相除法递归求解  最小公倍数 = a*b/最大公约数
3.伪代码：
   int Gyueshu(max,min){
     if(max%min=0) return min;else return Gyueshu(min,max%min);
   }

   void Gbeishu(){
      input(a,b);
	  max = a b较大；min = a b较小；
	  Gys = Gyueshu(max,min);
	  Gbs = a*b/Gys;
	  print(最大公约数为Gys 最小公倍数为Gbs)；
   }
*/
int Gyueshu(int max,int min){  //辗转相除法求最大公约数
	if (max%min == 0){
		return min;
	}
	else{
	   return Gyueshu(min, max%min); 
	}
}
void Gbeishu(){
	int a = 0, b = 0;
	int Gys = 0, Gbs = 0;//分别为最大公约数和最小公倍数
	int max = 0, min = 0;//分别保存a，b中较大和较小的数
	scanf("%d%d", &a, &b);
	max = a > b ? a : b;
	min = a > b ? b : a;
	Gys = Gyueshu(max,min);
	Gbs = a*b / Gys;
	printf("最大公约数为：%d\n最大公倍数为：%d\n",Gys,Gbs);
}

/*
1.第11小题 判断输入的n个数字是否互不相等
2.思路：将这n个数字进行排序  排序的实现用希尔排序排序 然后遍历一遍排序好的数组判断其相邻数据是否相等 
3.伪代码
void Sort(arr){
  while(distance大于1) do 
  {
     distance = distance/3+1;
     for i = 0 to n-distance do{
	    end = i;
		tmp = arr[i+distance];
		while(end大于等于0) do
		{
		   if(arr[end]大于tmp) arr[end+distance] = arr[end]; end-=distance;
		   else break;
		}
		arr[end+distance] = tmp; 
	 }
  }
}
void func(){
  for i = 0 to n do{
    scanf(arr[i]);
  }
  Sort(arr);
  for i = 0 to n do{
    if(arr[i] = arr[i+1]) do print(a[i]有重复);
  }
}
*/
void Sort(int* a, int size){
	int distance = size, tmp = 0, end = 0, i = 0;
	while (distance > 1){   //当distance的间距大于1的时候就进行不断缩小间距的插入排序
		distance = distance / 3 + 1;  //+1巧妙的让所有的结果最终都满足间距为1 使整个序列有序
		for (i = 0; i<size - distance; i++){ //i++很巧妙的同时让分组进行排序
			end = i;
			tmp = a[i + distance];
			while (end >= 0){ //单趟分组插入排序
				if (a[end] > tmp){
					a[end + distance] = a[end];
					end -= distance;
				}
				else{
					break;
				}
			}
			a[end + distance] = tmp;
		}
	}
}
void Gbeishu1(){
	int arr[10000] = { 0 };
	int n = 0, i = 0;
	printf("输入n：");
	scanf("%d", &n);
	printf("输入n个任意数字： ");
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	Sort(arr, n);
	for (i = 0; i < n; i++){
		if (arr[i] == arr[i + 1]){
			printf("%d有重复", arr[i]);
			while (arr[i] == arr[i + 1]){
				i++;
			}
		}
	}
}
//测试
int main(){
	int a[5] = { 5 ,4, 3, 1, 2 };
	Gbeishu1();
	return 0;
}

