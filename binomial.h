/**
 *
 * Authors: Carson Liebentritt and Ethan Clodfelter
 *
 * Date: 2024-11-20
 *
 * Binomial recursive functions used to find "n choose k"
 * using Paschal's Rule.
 *
 */

/**
 * takes n and k and produces n over k using Paschal's Rule
 */
long choose(int n, int k);

/**
 * initializes a memoization table
 */
long** initTable(int n,int k);

/**
 * frees memory allocated for the memoization table
 */
void freeTable(int n, long** table);

/**
 * takes n and k and produces n over k using Paschal's Rule
 * using memoization (caching) to avoid unnecessary repeated
 * recursive calls
 */
long chooseMemoization(int n, int k, long** table);
