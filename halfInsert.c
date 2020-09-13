#include<stdio.h>

/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: �۰��������,arr��int�����飬len�����鳤��
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
       arr[0] = arr[i];          //arr[i]�ŵ�0
       //�۰����arr[i]��λ��
        low = 1,high = i-1;
        while(low<=high){
            mid = (low+high)/2;
            if(arr[0]>arr[mid])low = mid+1;
            else high = mid-1;
        }
        //���յõ�mid����i��λ�ã�һ���ƶ�
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