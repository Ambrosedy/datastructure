#include<stdio.h>
/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: ϣ������
 * */
void ShowArr(int* arr){
    int *cur = arr+1;
    while(*cur){
        printf("%d\n",*cur);
        cur++;
    }
}
void ShellSort(int* arr,int len){
    int i,j,dk;
    //�����仯
    for(dk=len/2;dk>=1;dk=dk/2){
        // printf("%d \n",dk);
        //��ÿ���ֱ���һ��Ԫ�أ����ֱ�ĩβֵ��Ϊ��Ԫ��ֵ��ֱ�Ӳ�������
        for(i=dk+1;i<len;++i){
            
            if(arr[i]<arr[i-dk]){
                arr[0] = arr[i];
                for(j=i-dk;j>0&&arr[j]>arr[0];j-=dk){
                    arr[j+dk] = arr[j];
                }
                arr[j+dk] = arr[0];
            }
            // printf("%d  ",i);
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[6] = {0,2,1,4,3,5};
    ShowArr(&arr[0]);
    ShellSort(&arr[0],6);
  
    ShowArr(&arr[0]);
    return 0;
}
