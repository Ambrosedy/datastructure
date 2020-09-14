#include<stdio.h>

/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: ����
 * */

void ShowArr(int* arr){
    int *cur = arr;
    while(*cur){
        printf("%d\n",*cur);
        cur++;
    }
}

int Partition(int *arr,int low,int high);
void QuickSort(int* arr,int low,int high){
    if(low<high){
        //����
        int provit = Partition(arr,low,high);
        //��
        QuickSort(arr,low,provit-1);
            //��
        QuickSort(arr,provit+1,high);
    }
}

int Partition(int *arr,int low,int high){
    int provit = arr[low];
    while(low<high){
        //��ָ������
        while(low<high&&arr[high]>=provit)--high;
        //����
        arr[low] = arr[high];
        while (low<high&&arr[low]<=provit)++low;
        arr[high] = arr[low];
    }
    arr[low] = provit;
    return low;
}

int main(int argc, char const *argv[])
{
    int arr[6] = {-1,2,1,4,3,5};
    // ShowArr(&arr[0]);
    QuickSort(&arr[0],0,5);
    ShowArr(&arr[0]);
    return 0;
}