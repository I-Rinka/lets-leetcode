

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int partition(int *base, int numSize)
{
    int sw = rand() % numSize;
    int t = base[sw];
    base[sw] = base[0];
    base[0] = t;

    int *left = base;
    int *right = base + numSize - 1;
    int pivot = *left;
    while (left < right)
    {
        if (*left > *right)
        {
            int t = *left;
            *left = *right;
            *right = t;
        }
        if (*left == pivot)
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return left - base;
}

int insertSort(int *nums, int numsSize)
{
    for (int i = 0; i < numsSize - 1; i++)
    {
        int min = 0x3f3f3f3f;
        int p = i;
        for (int j = i; j < numsSize; j++)
        {
            if (nums[j] < min)
            {
                min = nums[j];
                p = j;
            }
        }
        nums[p] = nums[i];
        nums[i] = min;
    }
    return nums;
}

int *sortArray(int *nums, int numsSize, int *returnSize)
{
    int cutoff = 5;
    *returnSize = numsSize;
    if (numsSize > 5)
    {
        int p = partition(nums, numsSize);
        int placeHolder;
        sortArray(nums, p, &placeHolder);
        sortArray(nums + p + 1, numsSize - p - 1, &placeHolder);
    }
    else
    {
        insertSort(nums, numsSize);
    }
    return nums;
}
