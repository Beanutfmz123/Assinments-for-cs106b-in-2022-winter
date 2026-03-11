#include "HumanPyramids.h"
#include"error.h"
#include"Vector.h"
using namespace std;

int pounds = 160;

/* TODO: Refer to HumanPyramids.h for more information about what this function should do.
 * Then, delete this comment.
 */

double weightonbackofrec(int row,int col,int height,Vector<Vector<double>>& memo)
{

    if(memo[row][col] != -1.0)
    {
        return memo[row][col];
    }

    double weight = 0;

    if(col > 0)
    {
        weight += weightonbackofrec(row-1,col-1,height,memo)/2 + pounds/2;
    }
    if(col < row)
    {
        weight += weightonbackofrec(row-1,col,height,memo)/2 + pounds/2;
    }
    memo[row][col] = weight;
    return weight;
}

double weightOnBackOf(int row, int col, int pyramidHeight) {
    if(row< 0 || col < 0 || col > row||row >= pyramidHeight)
    {
        error("Out of doundary");
    }
    
    Vector<Vector<double>> memo(pyramidHeight,Vector<double>(pyramidHeight,-1.0));//一定要有行列数信息初始化
    for(int i = 0;i <= row;i++)
    {
        for(int j = 0;j <= col;j++)
        {
            memo[i][j] = -1.0;
        }
    }
    memo[0][0] = 0;
    return weightonbackofrec(row,col,pyramidHeight,memo);
}






/* * * * * * Test Cases * * * * * */
#include "GUI/SimpleTest.h"
PROVIDED_TEST("My Test Case")
{
    EXPECT_EQUAL(weightOnBackOf(0,0,1),0);
}













/* * * * * * Test cases from the starter files below this point. * * * * * */

PROVIDED_TEST("Check Person E from the handout.") {
    /* Person E is located at row 2, column 1. */
    EXPECT_EQUAL(weightOnBackOf(2, 1, 5), 240);
}

PROVIDED_TEST("Function reports errors in invalid cases.") {
    EXPECT_ERROR(weightOnBackOf(-1, 0, 10));
    EXPECT_ERROR(weightOnBackOf(10, 10, 5));
    EXPECT_ERROR(weightOnBackOf(-1, 10, 20));
}

PROVIDED_TEST("Stress test: Memoization is implemented (should take under a second)") {

    /* Do not delete anything below this point. :-) */

    /* This will take a LONG time to complete if memoization isn't implemented.
     * We're talking "heat death of the universe" amounts of time. :-)
     *
     * If you did implement memoization but this test case is still hanging, make
     * sure that in your recursive function (not the wrapper) that your recursive
     * calls are to your new recursive function and not back to the wrapper. If you
     * call the wrapper again, you'll get a fresh new memoization table rather than
     * preserving the one you're building up in your recursive exploration, and the
     * effect will be as if you hadn't implemented memoization at all.
     */
    EXPECT(weightOnBackOf(100, 50, 200) >= 10000);
}

/* TODO: Add your own tests here. You know the drill - look for edge cases, think about
 * very small and very large cases, etc.
 */
