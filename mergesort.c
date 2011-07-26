#include <stdio.h>

int merge( int *data, int start_index, int split_index, int end_index){
    int index_left = start_index;
    int index_right = split_index + 1;

    while (index_left <= split_index && index_right <= end_index){

        if( data[index_left] <= data[index_right] ){
            // the number is at its right place already!
            index_left++;
        }else{
            int tmp = data[index_left];
            data[index_left] = data[index_right];
            index_left++;
            split_index++; // Important!
            int runner = index_right;

            while(runner > (index_left)){
                data[runner] = data[runner - 1];
                runner--;
            }
            index_right++;
            data[index_left] = tmp;
        }
    }
}

/*
Sorts the array passed in parameter using mergesort, in-place (the passed array
is then sorted)
*/
int merge_sort(int *data, int start_index, int end_index){
    // First we need to split the data in two ranges, low and high (or left and right)

    // 1 2 3 4 5 6
    // 0 1 2 3 4 5

    if (start_index < end_index){
        int split_index = (start_index + end_index) / 2;

        merge_sort(data, start_index, split_index); // That's "left"
        merge_sort(data, split_index + 1, end_index); // That's "right"
        merge(data, start_index, split_index, end_index);
    }
    return(0);
}


int main(){

    int data[] = {1, 5, 7, 8, 3, 4, 6, 121, 2};
    int start = 0;
    int end = 8;
    merge_sort(data, start, end);

    int i = 0;

    while(i <= end){
        printf("%d ,", data[i]);
        i++;
    }

    printf("\n");
}
