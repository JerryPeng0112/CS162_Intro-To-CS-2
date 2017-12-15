/*********************************************************************
** Program Filename: sorting.c
** Author: Tsewei Peng
** Date: 06/08/2016
** Description: The sorting algorithm testing file
** Input: Textfile containing numbers to be sorted
** Output: The time it takes to sort using algorithm chosen.
*********************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct timeval time;
void print_array(int *, int);
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void selection_sort(int *, int);
void insertion_sort(int *, int);
void bubble_sort(int *, int);
void quick_sort(int *, int, int);
void swap(int *, int *);
void fill_array(int **, int *);
void add_num(int **, int *, int);

int main(){
    int *nums=NULL;
    int size=0;
    time stop, start;

    fill_array(&nums, &size);
    print_array(nums, size);

    //Time the function here
    gettimeofday(&start, NULL);

    //bubble_sort(nums, size);
    //insertion_sort(nums, size);
    //merge_sort(nums, 0, size-1);
    //selection_sort(nums, size);
    quick_sort(nums, 0, size-1);
    gettimeofday(&stop, NULL);

    printf("MicroSeconds: %d\n", stop.tv_usec-start.tv_usec);
    //printf("Seconds: %d\n", stop.tv_sec-start.tv_sec);

    print_array(nums, size);
    free(nums);

    return 0;
}

/*************************************************
 * Description: This prints the contents of an array
 * Params: array of integers and size of the array
 * Returns: none
 * Post-conditions: none
 * Pre-conditions: size is accurate number of
 *                 elements in the array >=0
 * **********************************************/
void print_array(int *nums, int size){
    int i;

    printf("The array elements are:\n");
    for(i=0; i<size; i++)
        printf("%d\t", nums[i]);
    printf("\n\n");
}

/********************************************************************************
* Description: This function merge sub-arrays while sorting them.
* Parameters: Address of array pointers to ints and
*             the left index of the sub-array and
*             the right index of the sub-array and
*             the middle of the sub-array
* Returns: N/A
* Pre-Conditions: There must be a valid number for the size of array, and the index must be within the size of array.
* Post-Conditions: The sub-arrays merged and sorted in ascending order.
*********************************************************************************/
void merge(int *nums, int left, int mid, int right){
    int i, j, lower_half, upper_half;
    int temp[(right-left)+1];

    lower_half=left;  //What is this for?
    upper_half=mid+1;  //What is this for?

    //What does this loop do?
    for(i=0; (lower_half<=mid)&&(upper_half<=right); i++){
        //What does this condition do?
        if(nums[lower_half]<=nums[upper_half]){
            temp[i]=nums[lower_half];
            lower_half++;
        }
        //What does this condition do?
        else{
            temp[i]=nums[upper_half];
            upper_half++;
        }
    }

    //What does this condition and loop do?
    if(lower_half>mid)
        for(j=upper_half;j<=right;j++, i++)
            temp[i]=nums[j];
    //What does this else and loop do?
    else
        for(j=lower_half;j<=mid;j++, i++)
            temp[i]=nums[j];

    //What does this loop do?
    for(j=0,i=left;i<=right;i++,j++)
        nums[i]=temp[j];
}

/********************************************************************************
* Description: This function sorts an array of integers using merge sort.
* Parameters: Address of array pointers to ints and
*             the left index of the sub-array and
*             the right index of the sub-array
* Returns: N/A
* Pre-Conditions: There must be a valid number for the size of array, and the index must be within the size of array.
* Post-Conditions: The array of integers are sorted in ascending orders.
*********************************************************************************/
void merge_sort(int *nums, int left, int right) {
   int mid;
   if(left<right) {
      mid=(right+left)/2;
      merge_sort(nums, left, mid);  //what does this call do?
      merge_sort(nums, mid+1, right); //what does this call do?
      merge(nums, left, mid, right);  //what does this call do?
   }
}

/********************************************************************************
* Description: This function sorts an array of integers using selection sort.
* Parameters: Address of array pointers to ints and
*             the size of the array
* Returns: N/A
* Pre-Conditions: There must be a valid number for the size of array, and the array must contain the number of elements.
* Post-Conditions: The array of integers are sorted in ascending orders.
*********************************************************************************/
void selection_sort(int *nums, int size) {
    int i, j;
    int temp, min;

    //What does this loop do?
    for(i=0; i<size-1; i++) {
        min=i;
    //What does this loop do?
    for(j=i; j<size; j++)
        if(nums[j]<nums[min])
            min=j;
        //What elements are being swaped?
        temp=nums[i];
        nums[i]=nums[min];
        nums[min]=temp;
    }
}

/********************************************************************************
* Description: This function sorts an array of integers using insertion sort.
* Parameters: Address of array pointers to ints and
*             the size of the array
* Returns: N/A
* Pre-Conditions: There must be a valid number for the size of array, and the array must contain the number of elements.
* Post-Conditions: The array of integers are sorted in ascending orders.
*********************************************************************************/
void insertion_sort(int *nums, int size) {
    int i, j;
    int temp;

    //What does this loop do?
    for(i=0; i<size; i++) {
        temp=nums[i];
    //What does this loop do?
    for(j=i; j>0 && nums[j-1]>temp; j--)
        nums[j]=nums[j-1];
        //What does this statment do?
        nums[j]=temp;
    }
}

/********************************************************************************
* Description: This function sorts an array of integers using bubble sort.
* Parameters: Address of array pointers to ints and
*             the size of the array
* Returns: N/A
* Pre-Conditions: There must be a valid number for the size of array, and the array must contain the number of elements.
* Post-Conditions: The array of integers are sorted in ascending orders.
*********************************************************************************/
void bubble_sort(int *nums, int size) {
    int i, j;
    int temp;

    //What does this loop do?
    for(i=0; i<size; i++) {
        //What does this loop do?
        for(j=0; j<size-i-1; j++) {
            if(nums[j]>nums[j+1]) {
            temp=nums[j];
            nums[j]=nums[j+1];
            nums[j+1]=temp;
            }
        }
    }
}

/********************************************************************************
* Source: http://www.zentut.com/c-tutorial/c-quicksort-algorithm/
* Description: This function sorts an array of integers using quick sort.
* Parameters: Address of array pointers to ints and
*             the starting index and
*             the ending index
* Returns: N/A
* Pre-Conditions: There must be a valid number for the size of array, and the index must be within the arrays.
* Post-Conditions: The array of integers is sorted in ascending orders.
*********************************************************************************/
void quick_sort(int *nums, int m, int n){
    int key,i,j,k;
    if(m < n)
    {
        k = (m+n)/2;
        swap(&nums[m],&nums[k]);
        key = nums[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (nums[i] <= key))
                i++;
            while((j >= m) && (nums[j] > key))
                j--;
            if(i < j)
                swap(&nums[i],&nums[j]);
        }
        /* swap two elements */
        swap(&nums[m], &nums[j]);

        /* recursively sort the lesser nums */
        quick_sort(nums,m,j-1);
        quick_sort(nums,j+1,n);
    }
}

/********************************************************************************
* Source: http://www.zentut.com/c-tutorial/c-quicksort-algorithm/
* Description: This function swap 2 integers
* Parameters: 2 address of integers
* Returns: N/A
* Pre-Conditions: both address must contain a number
* Post-Conditions: The two integers are swapped
*********************************************************************************/
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
/*************************************************
 * Description: This adds an element to the array
 * and sets the contents to num
 * Params: address of array pointer to ints and
 *         address of size of the array
 * Returns: none
 * Post-conditions: size is increased by one and
 * nums points to new array with one more element
 * where the contents are the same with num at the end
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void add_num(int **nums, int *size, int num){
    int *old_nums, i;

    *size+=1;
    old_nums=*nums;
    *nums=(int *) malloc(sizeof(int)*(*size));

    for(i=0; i<*size-1; i++)
        (*nums)[i]=old_nums[i];
    (*nums)[*size-1]=num;

    free(old_nums);
}

/*************************************************
 * Description: This fills an array with contents
 * from a file
 * Params: address of array pointer to ints and
 *         address of size of the array
 * Returns: none
 * Post-conditions: array pointer is pointing to
 * valid array of integers or NULL and size has
 * a positive integer
 * Pre-conditions: nums points to valid array or NULL
 * and size is accurate number of elements in array >=0
 * **********************************************/
void fill_array(int **nums, int *size) {
    FILE *fptr;
    char filename[20], num[10];

    printf("Enter the filename: ");
    scanf("%s",filename);
    fptr=fopen(filename,"r");

    while(fscanf(fptr,"%s", num)!=EOF){
        add_num(nums, size, atoi(num));
    }

    fclose(fptr);
}
