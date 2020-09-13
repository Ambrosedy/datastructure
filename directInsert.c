#include<stdio.h>

/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: 直接插入排序
 * */
void ShowArr(int* arr){
    int *cur = arr+1;
    while(*cur){
        printf("%d\n",*cur);
        cur++;
    }
}

void InsertSort(int* arr,int len){

    int i,j;
    //arr[0]是哨兵位，arr[1]是初始默认有序部分，外部循环从2开始
    for(i=2;i<len;i++){
        //小的放前边
        if(arr[i]<arr[i-1]){
            arr[0] = arr[i];
            //从后往前遍历，找到合适位置插入
            for(j=i-1;arr[0]<arr[j];j--){
                    //后移
                arr[j+1] = arr[j];
            }
            arr[j+1] = arr[0];
        }

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
