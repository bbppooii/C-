#define _CRT_SECURE_NO_WARNINGS 1
int thirdMax(int* nums, int numsSize) {
    long first = LONG_MIN;
    long second = LONG_MIN;
    long third = LONG_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > first) {
            third = second;
            second = first;
            first = nums[i];
        }
        else if (nums[i] > second && nums[i] < first) {
            third = second;
            second = nums[i];
        }
        else if (nums[i] > third && nums[i] < second) {
            third = nums[i];
        }
    }
    return (third == LONG_MIN) ? first : third;
}
