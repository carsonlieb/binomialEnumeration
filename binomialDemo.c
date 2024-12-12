/**
 * Authors: Carson Liebentritt and Ethan Clodfelter
 *
 * Date: 2024-12-02
 *
 * main test driver program for binomial.h and binomial.c
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "binomial.h"

int main(int argc, char **argv) {
    if(argc != 3) {
        printf("ERROR: code requires argument count of 3\n");
        return -1;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    if(n == 0 || n == k) {
        return 1;
    }

    if(k > n) {
        printf("Invalid input, k cannot be greater than one.\n");
        return -1;
    }

    clock_t start = 0;
    clock_t end = 0;
    long result = 0;
    double executionTime = 0;

    //start = clock();
    //result = choose(n, k);
    //end = clock();
    //executionTime = (double) (end - start) / CLOCKS_PER_SEC * 1000;
    //printf("Regular recursive function result: %ld\n", result);
    //printf("Regular recursive function time to execute: %f\n", executionTime);

    long** table = initTable(n, k);
    start = clock();
    result = chooseMemoization(n, k, table);
    end = clock();
    executionTime = (double) (end - start) / CLOCKS_PER_SEC * 1000;
    printf("Regular recursive function result: %ld\n", result);
    printf("Regular recursive function time to execute: %f\n", executionTime);

    freeTable(n, table);

    return 0;
}
