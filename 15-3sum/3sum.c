#include <stdlib.h>

// Comparison function for qsort (ascending order)
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    
    // Handle edge cases
    if (nums == NULL || numsSize < 3) {
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Allocate memory for result array (estimate first)
    int** result = malloc(1000 * sizeof(int*));
    *returnColumnSizes = malloc(1000 * sizeof(int));
    
    int capacity = 1000;
    
    // Step 2: Iterate through each number as the first element
    for (int i = 0; i < numsSize - 2; i++) {
        // Skip duplicate values to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        
        // Two pointers approach
        int left = i + 1;
        int right = numsSize - 1;
        
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            
            if (sum == 0) {
                // Found a valid triplet
                // Resize if needed
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = realloc(result, capacity * sizeof(int*));
                    *returnColumnSizes = realloc(*returnColumnSizes, capacity * sizeof(int));
                }
                
                // Store the triplet
                result[*returnSize] = malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                
                // Skip duplicates for left pointer
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                // Skip duplicates for right pointer
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                
                // Move both pointers inward
                left++;
                right--;
            }
            else if (sum < 0) {
                // Need larger sum, move left pointer right
                left++;
            }
            else {
                // Need smaller sum, move right pointer left
                right--;
            }
        }
    }
    
    // Check if we found anything
    if (*returnSize == 0) {
        free(result);
        free(*returnColumnSizes);
        *returnColumnSizes = NULL;
        return NULL;
    }
    
    return result;
}