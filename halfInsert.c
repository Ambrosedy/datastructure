#include<stdio.h>

/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: 折半插入排序,arr是int型数组，len是数组长度
 * */
void ShowArr(int* arr){
    int *cur = arr+1;
    while(*cur){
        printf("%d\n",*cur);
        cur++;
    }
}
void InsertSort(int*arr,int len){
    int low,high,mid,i,j;
    for(i=2;i<len;i++){
       arr[0] = arr[i];          //arr[i]放到0
       //折半查找arr[i]的位置
        low = 1,high = i-1;
        while(low<=high){
            mid = (low+high)/2;
            if(arr[0]>arr[mid])low = mid+1;
            else high = mid-1;
        }
        //最终得到mid，是i的位置，一起移动
        for(j = i-1;j>=high+1;j--){
            arr[j+1]=arr[j];
        }
        // printf("m=%d  h=%d l=%d\n",mid,high,low);
        arr[high+1] = arr[0];
    }
}

int main(int argc, char const *argv[])
{
    int arr[6] = {0,2,1,4,3,5};
    // ShowArr(&arr[0]);
    InsertSort(&arr[0],6);
    ShowArr(&arr[0]);
    return 0;
}