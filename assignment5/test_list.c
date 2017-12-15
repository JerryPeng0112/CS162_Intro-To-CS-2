/*********************************************************************
** Program Filename: test_list.c
** Author: Tsewei Peng
** Date: 05/30/2016
** Description: The main function does everything to test list functions
** Input: User input of integers and file to open
** Output: a lot of printing
*********************************************************************/
#include "list.h"
int main (){
    char filename[20];
    struct list l;
    l.head = NULL; // Set the head and tail to NULL to identify empty list
    l.tail = NULL;
    FILE *fileptr;
    char num[3]; // We will read positive integers 0-99
    int int_num; // for user input
    int location; // for user input
    printf("Enter filename: ");
    scanf("%s", filename);
    fileptr = fopen (filename,"r");
    //continue reading until we are at the end of the file
    while (fscanf(fileptr, "%s", num)!=EOF){
        printf("number is: %d\n", atoi(num));
        push_front(&l, atoi(num));
        push_back(&l, atoi(num));
    }
    printf("The length of the list: %d\n", length(l));
    print(l);
    printf("\nSort ascending: \n");
    sort_ascending(&l);
    print(l);
    printf("\nSort descending: \n");
    sort_descending(&l);
    print(l);
    printf("Enter a value to remove from the list:\n");
    scanf("%d", &int_num);
    remove_val(&l, int_num);
    print(l);
    printf("Enter a value to add to the list: \n");
    scanf("%d", &int_num);
    printf("Enter the location to enter the list:\n");
    scanf("%d", &location);
    insert(&l, int_num, location);
    print(l);
    clear(&l);
    fclose (fileptr);
    return 0;
}
