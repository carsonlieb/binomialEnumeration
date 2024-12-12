/**
 *
 * Authors: Carson Liebentritt and Ethan Clodfelter
 *
 * Date: 2024-11-20
 *
 * Function defintions for binomial.h
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "binomial.h"

long choose(int n, int k) {
    if(k == 0 || n == k) {
        return 1;
    }
    else {
        return choose(n-1, k) + choose(n-1,k-1);
    }
}

long** initTable(int n, int k) {
    long ** table = (long **) malloc(sizeof(long *) * (n+1));
    for(int i = 0; i<=n; i++) {
        table[i] = (long *) malloc(sizeof(long) * (k+1));
        for(int j = 0; j<=k; j++) {
            table[i][j] = -1;
        }
    }
    return table;
}

void freeTable(int n, long** table) {
    for(int i = 0; i<=n;i++) {
        free(table[i]);
    }
    free(table);
}

long chooseMemoization(int n, int k, long** table) {
    if(k == 0 || n == k) {
        return 1;
    }
    else if(table[n][k] != -1) {
        return table[n][k];
    }
    else {
        long result = chooseMemoization(n-1, k, table) + chooseMemoization(n-1,k-1, table);
        table[n][k] = result;
        return result;
    }
}
