# 3.14

25. K 个一组翻转链表【困难】<https://leetcode-cn.com/problems/reverse-nodes-in-k-group/>

15. 三数之和【中等】<https://leetcode-cn.com/problems/3sum/>

912. 排序数组（此题请至少尝试2种及以上的排序算法）【中等】<https://leetcode-cn.com/problems/sort-an-array/>

## 25

这道题比想象的复杂，本来还想说“就这还能困难的”，但实际上在debug的时候花了比较多的时间。

我使用了时间复杂度为O(n)，空间复杂度为O(1)的算法。每次都要维护一个“开始翻转”的节点。然后从这个节点开始后的k个节点按照算法来依次翻转。这边比较容易出bug的点是，在翻转完后下一个节点的位置。在顶层遍历链表的循环中，需要把翻转完后的新的最后一个节点连接到下一个节点上。

## 15

这道题我使用了时间复杂度为O(n^2)的算法。首先先对所有元素排序，接着使用三个指针：最左 a，最左+1 b，最右 c，以此来标记对应的三个数的元素。

总的思路是a在最外层大循环向左移动，在此期间，b向右移，c向左移。如果a+b+c<0,则说明阴盛阳衰，此时需要增加b。如果a+b+c>0，则减小c。bc相遇时，则a元素的所有三数和找到。由于b和c在a+1~最右区间共同向中间移动，因此每固定一次a，两者加起来都仅移动n距离，a最大移动n次，因此时间复杂度为O(n^2)。

## 912

我想实现快排。这题有个坑点，有个特殊用例需要随机化，否则会让快排效果为最差。

因为我的partition函数是直接使用第一个元素作为pivot，所以需要把第一个元素与其他元素随机交换一下：

```c

int partition(int*base,int numSize){
    int sw=rand()%numSize;
    int t=base[sw];
    base[sw]=base[0];
    base[0]=t;

    int *left=base;
    int *right=base+numSize-1;
    int pivot=*left;
    while(left<right){
        if(*left>*right)
        {
            int t=*left;
            *left=*right;
            *right=t;
        }
        if(*left==pivot)
        {
            right--;   
        }
        else
        {
            left++;
        }
    }
    return left-base;
}

```