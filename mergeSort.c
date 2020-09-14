#include<stdio.h>
#include <stdlib.h>
/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: 合并两个有序表
 * */

void ShowArr(int* arr){
    int *cur = arr;
    while(*cur){
        printf("%d == ",*cur);
        cur++;
    }
    printf("\n");
}

void Merge(int* arr,int low,int mid,int high)
{
    //辅助数组
    int* help = (int*)malloc((high+1)*sizeof(int));
    //将arr复制到help
    for(int i=0;i<=high;i++){
        help[i] = arr[i];
    }
    ShowArr(help);
    int i=0,j=0,k=0;
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(help[i]<=help[j]){
            arr[k] = help[i++];
        }
        else {
            arr[k] = help[j++];
        }
    }
    //左右两数组长度不一样是上述代码会出现剩余部分，此时选择剩余部分，复制给arr即可
    while(i<=mid)arr[k++] = help[i++];
    while(j<=high)arr[k++] = help[j++];
}

void MergeSort(int *arr,int low,int high)
{
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(arr,low,mid);
        MergeSort(arr,mid+1,high);
        Merge(arr,low,mid,high);
    }
}


int main(int argc, char const *argv[])
{
    int arr[10] = {2,1,9,3,8,11,24,13,29,7};
    // int arr[4] = {1,5,2,6};
    // printf("%d",arr[0]);
    ShowArr(&arr[0]);
    MergeSort(&arr[0],0,9);
    ShowArr(&arr[0]);
    return 0;
}