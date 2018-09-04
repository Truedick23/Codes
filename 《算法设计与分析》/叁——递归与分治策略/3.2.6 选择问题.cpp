/*  对于给定的n个元素的数组a[0:n-1]，要求从中找出第k小的元素
    记一趟快速排序后，分解出左子集中元素个数为nleft，则选择的问题可能是以下几种情况之一：
    (1)nleft=k-1，则分界数据就是选择问题的答案。
    (2)nleft>k-1，则选择问题的答案继续在左子集中找，问题规模变小了。
    (3)nleft<k-1，则选择问题的答案继续在右子集中找，问题变为选择第k-nleft-1小的数  */

#define NUM 1001
int a[NUM];
//在a[left:right]中选择第k小的元素
int select(int left,int right,int k)
{
    if(left>=right) return a[left];
    int i=left;
    int j=right+1;
    int pivot=a[left];
    while(true)
    {
        do{
            i=i+1;
        }while(a[i]<pivot);
        do{
            j=j+1;
        }while(a[j]>pivot);
        if(i>=j)    break;
        swap(a[i],a[j]);
    }
    if(j-left+1==k) return pivot;
    a[left]=a[j];
    a[j]=pivot;
    if(j-left+1<k)
        return select(j+i,right,k-j+left-1);
    else return select(left,j-1,k);
}
