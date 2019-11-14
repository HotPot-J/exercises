#define _CRT_SECURE_NO_WARNINGS 1
//关于线性表的两个函数实现  线性表的冒泡排序和线性表的相同数据删除
void SeqListBubbleSort(SeqList* psl){
	assert(psl != NULL);
	int size = psl->size - 1; //2 1 3 4 0
	// 5 4 3 2 1
	//4 3 2 1 5
	//3 2 1 4 5
	//2 1 3 4 5
	//1 2 3 4 5



	int i = 0;
	int j = 0;
	SLDataType temp = 0;
	for (i = 0; i < (int)psl->size; i++){
		for (j = 0; j < size; j++){
			if (psl->arry[j] > psl->arry[j + 1]){
				temp = psl->arry[j + 1];
				psl->arry[j + 1] = psl->arry[j];
				psl->arry[j] = temp;
			}
		}
		size--;
	}
}
void SeqListRemoveAll(SeqList* psl, SLDataType x){
	/*
	推到过程：

	①不考虑空间复杂度   定义一个新数组 遍历整个旧数组 遇见不是x的数组则保存在新数组中 是x则接着往后遍历
	②空间复杂度为o（1）：
	定义i和j 开始时均为顺序表首元素的下表同时往后++ 在遇见x时j不动 i++
	直到遇见arr[i]!=x  把arr[i]的值赋给arr[j]  即覆盖掉x   当遍历完成
	将j的值赋给psl->size  (即从j处截断该顺序表)达到删除表中所有x发的目的

	上述推导的两种方式时间复杂度均为O（N）
	*/
	//用方法②实现：
	int i = 0;
	int j = 0;
	while (i < (int)psl->size){
		if (i == j){
			if (psl->arry[i] != x){
				i++;
				j++;
			}
			else{
				i++;
			}
		}
		else{
			if (psl->arry[i] != x){
				psl->arry[j] = psl->arry[i];
				i++;
				j++;
			}
			else{
				i++;
			}
		}
	}
	psl->size = j;
}