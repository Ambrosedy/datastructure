#include<stdio.h>

/**
 * @Time:
 * @Date:
 * @Author:
 * @Description: 堆排序
 * */

void ShowArr(int* arr){
    int *cur = arr+1;
    while(*cur){
        printf("%d == ",*cur);
        cur++;
    }
    printf("\n");
}

void Swap(int*arr,int min,int i)
{
    int tmp = arr[min];
    arr[min] = arr[i];
    arr[i] = tmp;
    // printf("%d",tmp);
}

//对根为k的子树进行调整
void Headadjust(int*arr,int k,int n)
{
    arr[0] = arr[k];
    int i;
    for(i=k*2;i<=n;i*=2){
        //取子结点中较大者
        if(i<n&&arr[i]<arr[i+1])i++;
        //与根节点比较
        if(arr[0]>=arr[i])break;
        else{
            //交换
            arr[k] = arr[i];
            //改变k，如果i有子树,继续调整
            k = i;
        }
    }
    arr[k] = arr[0];
}

void BuildMaxHeap(int*arr,int n){
    int i;
    //反复调整
    for(i=n/2;i>0;i--){
        Headadjust(arr,i,n);
    }
}

void HeapSort(int *arr,int n)
{
    BuildMaxHeap(arr,n);
    ShowArr(arr);
    for(int i=n;i>1;i--){
        printf("i=%d\n",i);
        Swap(arr,i,1);
        ShowArr(arr);
        //交换后调整的范围缩小，不考虑已输出的（arr[1])
        Headadjust(arr,1,i-1);
        ShowArr(arr);
    }
}

int main(int argc, char const *argv[])
{
    int arr[6] = {-1,2,1,4,3,5};
    ShowArr(&arr[0]);
    
    HeapSort(&arr[0],5);
    ShowArr(&arr[0]);
    return 0;
}