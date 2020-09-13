#include<stdio.h>

/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: ֱ�Ӳ�������
 * */

void ShowArr(int* arr){
    int *cur = arr;
    while(*cur){
        printf("%d\n",*cur);
        cur++;
    }
}
void Swap(int* arr,int i,int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}
void BubbleSort(int* arr,int len){
    int flag=0,i,j;
    //�ӵײ�����ð�ݣ���ð��len-1��
    for(i=0;i<len-1;i++){
        //�Ѿ�ð�ݹ��Ĳ�����Ƚ�
        for(j=len-1;j>i;j--){
            if(arr[j]<arr[j-1]){
                Swap(arr,j,j-1);
                flag = 1;
            }
        }
        if(!flag){
            return;
        }
    }
}


int main(int argc, char const *argv[])
{
    int arr[6] = {-1,2,1,4,3,5};
    // printf("%d",arr[0]);
    // ShowArr(&arr[0]);
    BubbleSort(&arr[0],6);
    ShowArr(&arr[0]);
    return 0;
}