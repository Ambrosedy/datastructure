#include<stdio.h>

/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: 简单选择排序
 * */

void ShowArr(int* arr){
    int *cur = arr;
    while(*cur){
        printf("%d\n",*cur);
        cur++;
    }
}

void Swap(int *arr,int min,int i);
void SelectSort(int *arr,int n)
{
    int i,j;
    //循环n-2次
    for(i=0;i<n-2;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])min = j;
        }
        if(min!=i)Swap(arr,min,i);
    }
}

void Swap(int*arr,int min,int i)
{
    int tmp = arr[min];
    arr[min] = arr[i];
    arr[i] = tmp;
}

int main(int argc, char const *argv[])
{
    int arr[6] = {-1,2,1,4,3,5};
    // ShowArr(&arr[0]);
    SelectSort(&arr[0],6);
    ShowArr(&arr[0]);
    return 0;
}