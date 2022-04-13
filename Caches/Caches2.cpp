#include <intrin.h>

// __nop() to do no-op instruction <intrin.h>

int numRows = 2048;
int numColumns = 2048;
int numRuns = 1000;

int** array = NULL;

int sum;

void allocate_array() {
    array = (int**)malloc(numRows * sizeof(int *));
    for (int i = 0; i < numRows; i++) {
        array[i] = (int*)malloc(numColumns * sizeof(int));
    }
}

void fill_array() {
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numColumns; j++) {
            array[i][j] = i + j;
        }
    }
}


void free_array() {
    for (int i = 0; i < numRows; i++) {
        free(array[i]);
    }
    free(array);

}

void row_major_access() {
    // row major traversal
    for (int runs = 0; runs < numRuns; runs++) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                sum += array[i][j]; // row major: [i][j]
            }
        }
    }
}

void column_major_access() {
    // column major traversal
    for (int runs = 0; runs < numRuns; runs++) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                sum += array[j][i]; // column major: [j][i]
            }
        }
    }
}

void row_column_major_access() {
    // alternating row and column major traversal
    bool flag = true;
    for (int runs = 0; runs < numRuns; runs++) {
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numColumns; ++j) {
                if (flag == true)
                    sum += array[i][j]; // row major: [i][j]
                else
                    sum += array[j][i]; // column major: [j][i]
                flag = !flag;
            }
        }
    }

}

// caches test method 2 (run VTune to measure cache hits and misses)
void caches2(void) {
    // allocate the array
    allocate_array();

    // fill the array
    fill_array();

    // row-column-major access
    column_major_access();

    // free the array
    free_array();
}