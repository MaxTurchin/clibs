#include "dynamic_array.h"
#include "arrays.h"
#include "2d_array.h"

int main(){
    // DynamicArray darray;
    // darray_init(&darray, sizeof(int));

    // int value = 1;
    // darray_append(&darray, &value);
    // value = 2;
    // darray_append(&darray, &value);
    // value = 3;
    // darray_append(&darray, &value);

    // printf("%d\n", *(int *)darray_get_cell(&darray, 0));
    // printf("%d\n", *(int *)darray_get_cell(&darray, 1));
    // printf("%d\n", *(int *)darray_get_cell(&darray, 2));

    // darray_remove_index(&darray, 1);

    // printf("%d\n", *(int *)darray_get_cell(&darray, 0));
    // printf("%d\n", *(int *)darray_get_cell(&darray, 1));
    // printf("%d\n", *(int *)darray_get_cell(&darray, 2));




    // int arr[10];
    // for (int i = 0; i < 10; i++) {
    //     arr[i] = i;
    // }
    
    // Array array = {10, sizeof(int), &arr};
    // printf("%d\n",*(int *)array_get_cell(&array, 8));




    int arr[10][10];
    for(int i=0; i<10; i++) {
        for (int j=0; j<10; j++){
            arr[i][j] = j;
        }
    }

    twoDArray array = {10, 10, sizeof(int), &arr};
    for(int i=0; i<10; i++) {
        for (int j=0; j<10; j++){
            printf("(%d, %d)  ,  ", *(int *)tdarray_get_cell(&array, i, j), arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    char str_arr[3][3];
    str_arr[0][0] = 'a';
    str_arr[0][1] = 'b';
    str_arr[0][2] = 'c';
    str_arr[1][0] = 'd';
    str_arr[1][1] = 'e';
    str_arr[1][2] = 'f';
    str_arr[2][0] = 'g';
    str_arr[2][1] = 'h';
    str_arr[2][2] = 'i';

    twoDArray str_array = {3, 3, sizeof(char), &str_arr};
    for(int i=0; i<3; i++) {
        for (int j=0; j<3; j++){
            printf("(%c, %c)  ,  ", *(char *)tdarray_get_cell(&str_array, i, j), str_arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    char *str_arr2[3][3];
    str_arr2[0][0] = "word1";
    str_arr2[0][1] = "word2";
    str_arr2[0][2] = "word3";
    str_arr2[1][0] = "word11";
    str_arr2[1][1] = "word12";
    str_arr2[1][2] = "word13";
    str_arr2[2][0] = "word21";
    str_arr2[2][1] = "word22";
    str_arr2[2][2] = "word23";

    twoDArray str_array2 = {3, 3, sizeof(char *), &str_arr2};
    for(int i=0; i<3; i++) {
        for (int j=0; j<3; j++){
            printf("(%s, %s)  ,  ", *(char **)tdarray_get_cell(&str_array2, i, j), str_arr2[i][j]);
        }
        printf("\n");
    }

    // for(int i=1; i<10; i++) {
    //     printf("%d\n", &arr[i]);
    // }

    // printf("(%d, %d)\n", (int *)tdarray_get_cell(&array, 1, 0), &arr[1]);
}