#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

/*
1.��12С��������������С�����������Լ��
2.˼·��������Ϊa,b ������Լ����շת������ݹ����  ��С������ = a*b/���Լ��
3.α���룺
   int Gyueshu(max,min){
     if(max%min=0) return min;else return Gyueshu(min,max%min);
   }

   void Gbeishu(){
      input(a,b);
	  max = a b�ϴ�min = a b��С��
	  Gys = Gyueshu(max,min);
	  Gbs = a*b/Gys;
	  print(���Լ��ΪGys ��С������ΪGbs)��
   }
*/
int Gyueshu(int max,int min){  //շת����������Լ��
	if (max%min == 0){
		return min;
	}
	else{
	   return Gyueshu(min, max%min); 
	}
}
void Gbeishu(){
	int a = 0, b = 0;
	int Gys = 0, Gbs = 0;//�ֱ�Ϊ���Լ������С������
	int max = 0, min = 0;//�ֱ𱣴�a��b�нϴ�ͽ�С����
	scanf("%d%d", &a, &b);
	max = a > b ? a : b;
	min = a > b ? b : a;
	Gys = Gyueshu(max,min);
	Gbs = a*b / Gys;
	printf("���Լ��Ϊ��%d\n��󹫱���Ϊ��%d\n",Gys,Gbs);
}

/*
1.��11С�� �ж������n�������Ƿ񻥲����
2.˼·������n�����ֽ�������  �����ʵ����ϣ���������� Ȼ�����һ������õ������ж������������Ƿ���� 
3.α����
void Sort(arr){
  while(distance����1) do 
  {
     distance = distance/3+1;
     for i = 0 to n-distance do{
	    end = i;
		tmp = arr[i+distance];
		while(end���ڵ���0) do
		{
		   if(arr[end]����tmp) arr[end+distance] = arr[end]; end-=distance;
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
    if(arr[i] = arr[i+1]) do print(a[i]���ظ�);
  }
}
*/
void Sort(int* a, int size){
	int distance = size, tmp = 0, end = 0, i = 0;
	while (distance > 1){   //��distance�ļ�����1��ʱ��ͽ��в�����С���Ĳ�������
		distance = distance / 3 + 1;  //+1����������еĽ�����ն�������Ϊ1 ʹ������������
		for (i = 0; i<size - distance; i++){ //i++�������ͬʱ�÷����������
			end = i;
			tmp = a[i + distance];
			while (end >= 0){ //���˷����������
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
	printf("����n��");
	scanf("%d", &n);
	printf("����n���������֣� ");
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	Sort(arr, n);
	for (i = 0; i < n; i++){
		if (arr[i] == arr[i + 1]){
			printf("%d���ظ�", arr[i]);
			while (arr[i] == arr[i + 1]){
				i++;
			}
		}
	}
}
//����
int main(){
	int a[5] = { 5 ,4, 3, 1, 2 };
	Gbeishu1();
	return 0;
}

