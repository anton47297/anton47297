#include "matrix.h"
#include <assert.h>

void test_swapRowsWithMinValuesAndMaxValues() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 2, 3,
                    4, 66, 6,
                    7, 8, 99},
            3, 3);

    swapRowsWithMinValuesAndMaxValues(testMatrix);
    outputMatrix(testMatrix);
}


void test_sortRowsByMinElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    7,
                    8,
                    99,
                    4,
                    66,
                    6,
                    1,
                    2,
                    3,
            },
            3, 3);

    sortRowsByMinElement(testMatrix);

    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    1,
                    2,
                    3,
                    4,
                    66,
                    6,
                    7,
                    8,
                    99,
            },
            3, 3);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void test_sortColsByMinElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    5, 8, 0, 9,
                    2, 3, 7, 5},
            2, 4);

    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    0, 5, 8, 9,
                    7, 2, 3, 5},
            2, 4);

    sortColsByMinElement(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void test_getSquareOfMatrixIfSymmetric() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 4, 3,
                    4, 5, 6,
                    3, 6, 2},
            3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    26, 42, 33,
                    42, 77, 54,
                    33, 54, 49},
            3, 3);

    getSquareOfMatrixIfSymmetric(&testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void test_transposeIfMatrixHasNotEqualSumOfRows() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 4, 3,
                    8, 5, 6,
                    3, 0, 2},
            3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    1, 8, 3,
                    4, 5, 0,
                    3, 6, 2

            },
            3, 3);

    transposeIfMatrixHasNotEqualSumOfRows(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void test_isMutuallyInverseMatrices() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 3, -5,
                    0, 1, 2,
                    0, 0, 1},
            3, 3);

    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    1, -3, 11,
                    0, 1, -2,
                    0, 0, 1

            },
            3, 3);

    assert(isMutuallyInverseMatrices(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2},
            3, 4);

    int res = 20;

    assert(res == findSumOfMaxesOfPseudoDiagonal(testMatrix));

    freeMemMatrix(testMatrix);
}

void test_getMinInArea() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 3, -5, 8,
                    4, 11, 2, 7,
                    0, 9, 5, 55},
            3, 4);

    int res = -5;

    assert(res == getMinInArea(testMatrix));

    freeMemMatrix(testMatrix);
}

void test_sortByDistances() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 3, 0, 8,
                    4, 1, 2, 7,
                    0, 9, 5, 3},
            3, 4);

    sortByDistances(testMatrix);

    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    4, 1, 2, 7,
                    1, 3, 0, 8,
                    0, 9, 5, 3},
            3, 4);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void test_countEqClassesByRowsSum() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 4,
                    5, 6,
                    9, 0,
                    7, 4,
                    2, 3,
                    7, 2},
            6, 2);

    int res = 3;

    assert(res == countEqClassesByRowsSum(testMatrix));

    freeMemMatrix(testMatrix);
}

void test_getNSpecialElement() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2},
            3, 4);

    int res = 2;

    assert(res == getNSpecialElement(testMatrix));

    freeMemMatrix(testMatrix);
}

void test_swapPenultimateRow() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1},
            3, 3);

    swapPenultimateRow(testMatrix);

    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1},
            3, 3);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));

    freeMemMatrix(testMatrix);
    freeMemMatrix(endMatrix);
}

void test_countNonDescendingRowsMatrices() {
    matrix *testMatrixs = createArrayOfMatrixFromArray(
            (int[]){
                    1, 2, 3,
                    4, 5, 6,

                    7, 8, 1,
                    8, 9, 0,

                    1, 1, 1,
                    3, 4, 6

            },
            3, 2, 3);

    int count = 2;

    assert(countNonDescendingRowsMatrices(testMatrixs, 3) == count);

    freeMemMatrices(testMatrixs, 2);
}

void test_countZeroRows() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 2, 3,
                    0, 0, 0,
                    0, 0, 0},
            3, 3);

    int res = 2;

    assert(res == countZeroRows(testMatrix));

    freeMemMatrix(testMatrix);
}

void tests(){
    test_swapRowsWithMinValuesAndMaxValues();
    test_sortRowsByMinElement();
    test_sortColsByMinElement();
    test_getSquareOfMatrixIfSymmetric();
    test_transposeIfMatrixHasNotEqualSumOfRows();
    test_isMutuallyInverseMatrices();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement();
    test_swapPenultimateRow();
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
}

int main() {

    tests();

    return 0;
}
