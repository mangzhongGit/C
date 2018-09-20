#include<iostream>
using namespace std;
void qSort(int *a,int left,int right);
void Merge(int *a,int left,int right);
void MergeSort(int *a,int left,int right);
void newHeap(int *a,int left,int right);
void HeapSort(int *a,int left,int right);

/*
* 快速排序算法,递减
* 不占用额外的空间，时间复杂度为0(nlog(n))
*/
void qSort(int *a,int left,int right)
{
    if(left<right)
    {
        int i=left,j=right;
        int key=a[i];
        while(i<j)
        {
            while(a[j]<=key && i<j) j--;
            if(i<j) a[i++]=a[j];
            while(a[i]>=key && i<j) i++;
            if(i<j) a[j--]=a[i];
        }
        a[i]=key;
        qSort(a,left,i-1);
        qSort(a,i+1,right);
    }
}

/*
* 归并排序算法 递增
* 占用额外的地址空间n
* 时间复杂度为 0(nlog(n))
*/
int *b=(int *)malloc(sizeof(int)*10);
void MergeSort(int *a,int left,int right) // 分
{
    if(left<right)
    {
        int mid = (left+right)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        Merge(a,left,right);
    }
}
void Merge(int *a, int left, int right) // 合
{
    int mid = (left+right)/2;
    int i,j,k;
    for(i=left;i<=right;i++)
    {
        b[i]=a[i];
    }
    for(i=left,k=left,j=mid+1;i<=mid && j<=right;k++)
    {
        if(b[i]<b[j]) a[k]=b[i++];
        else a[k]=b[j++];
    }
    while(i<=mid) a[k++]=b[i++];
    while(j<=right) a[k++]=b[j++];
}

/*
 * 堆排序
*/
void HeapSort(int *a,int left,int right)
{
    int n=right-left+1;
    int i;
    for(i=(n/2)-1;i>0;i--)
        newHeap(a,i,n-1);
    for(i=n-1;i>0;i--)
    {
        swap(a[0],a[i]);
        newHeap(a,0,i-1);
    }
}
void newHeap(int *a,int left,int right)
{
    int c=left;
    int root=a[c];
    int l=left*2+1;
    for(;l<=right;c=l,l=l*2+1)
    {
        if(l<right && a[l]<a[l+1]) l++;
        if(root<a[l])
        {
            a[c]=a[l];
            a[l]=root;
        }
        else break;
    }
}


int main(){
    int a[]={9,8,7,6,5,4,3,2,1,0};
    //qSort(a,0,9);
    //MergeSort(a,0,9);
    HeapSort(a,0,9);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
}
