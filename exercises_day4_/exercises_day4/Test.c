#define _CRT_SECURE_NO_WARNINGS 1
//�������Ա����������ʵ��  ���Ա��ð����������Ա����ͬ����ɾ��
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
	�Ƶ����̣�

	�ٲ����ǿռ临�Ӷ�   ����һ�������� �������������� ��������x�������򱣴����������� ��x������������
	�ڿռ临�Ӷ�Ϊo��1����
	����i��j ��ʼʱ��Ϊ˳�����Ԫ�ص��±�ͬʱ����++ ������xʱj���� i++
	ֱ������arr[i]!=x  ��arr[i]��ֵ����arr[j]  �����ǵ�x   ���������
	��j��ֵ����psl->size  (����j���ضϸ�˳���)�ﵽɾ����������x����Ŀ��

	�����Ƶ������ַ�ʽʱ�临�ӶȾ�ΪO��N��
	*/
	//�÷�����ʵ�֣�
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