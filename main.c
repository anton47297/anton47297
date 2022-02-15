#include "matrix.h"
#include <assert.h>

void test_getMemMatrix() {
    int n = 3;
    int testMatrix[][2] = {
            {3, 5},
            {8, 2},
            {0, 1}};

    for (int i = 0; i < n; ++i) {
        int nRows = testMatrix[i][0];
        int nCols = testMatrix[i][1];
        matrix m = getMemMatrix(nRows, nCols);

        assert(m.nRows == nRows);
        assert(m.nCols == nCols);

        freeMemMatrix(m);
    }
}

void test_swapRows1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    1, 9, 0,
                    3, 5, 7,
                    45, 6, 13},
            3, 3);
    swapRows(testMatrix, 0, 1);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_swapRows2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    45, 6, 13,
                    1, 9, 0},
            3, 3);

    swapRows(testMatrix, 1, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_swapRows3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    45,
                    6,
                    13,
                    1,
                    9,
                    0,
                    3,
                    5,
                    7,
            },
            3, 3);
    swapRows(testMatrix, 0, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_swapRows() {
    test_swapRows1();
    test_swapRows2();
    test_swapRows3();
}

void test_swapColumns1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    7, 5, 3,
                    0, 9, 1,
                    13, 6, 45},
            3, 3);
    swapColumns(testMatrix, 0, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_swapColumns2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    3, 7, 5,
                    1, 0, 9,
                    45, 13, 6},
            3, 3);
    swapColumns(testMatrix, 1, 2);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_swapColumns3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    5, 3, 7,
                    9, 1, 0,
                    6, 45, 13},
            3, 3);
    swapColumns(testMatrix, 0, 1);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_swapColumns() {
    test_swapColumns1();
    test_swapColumns2();
    test_swapColumns3();
}


void test_isSquareMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3,
                    5,
                    7,
                    1,
                    9,
                    0,
                    45,
                    6,
                    13,
            },
            3, 3);
    assert(isSquareMatrix(testMatrix));
}

void test_isSquareMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 4, 5, 6,
                    1, 4, 7, 8,
                    9, 0, 1, 3,
                    4, 6, 8, 9},
            4, 4);
    assert(isSquareMatrix(testMatrix));
}

void test_isSquareMatrix() {
    test_isSquareMatrix1();
    test_isSquareMatrix2();
}

void test_twoMatricesEqual1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    3, 5, 7,
                    1, 9, 0,
                    45, 6, 13},
            3, 3);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_twoMatricesEqual2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 5, 8, 9,
                    2, 5, 7, 5},
            2, 4);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    1, 5, 8, 9,
                    2, 5, 7, 5},
            2, 4);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_twoMatricesEqual() {
    test_twoMatricesEqual1();
    test_twoMatricesEqual2();
}

void test_isEMatrix() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1},
            3, 3);
    assert(isEMatrix(testMatrix));
}

void test_isSymmetricMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    2, 1, 2,
                    1, 3, 0,
                    2, 0, 3},
            3, 3);

    assert(isSymmetricMatrix(testMatrix));
}


void test_isSymmetricMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    2},
            1, 1);

    assert(isSymmetricMatrix(testMatrix));
}

void test_isSymmetricMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 5,
                    5, 7},
            2, 2);

    assert(isSymmetricMatrix(testMatrix));
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix1();
    test_isSymmetricMatrix2();
    test_isSymmetricMatrix3();
}

void test_transposeSquareMatrix1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    1, 4, 88,
                    7, 85, 7,
                    5, 7, 5},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    1, 7, 5,
                    4, 85, 7,
                    88, 7, 5},
            3, 3);
    transposeSquareMatrix(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_transposeSquareMatrix2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 0,
                    9, -2},
            2, 2);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    3, 9,
                    0, -2},
            2, 2);
    transposeSquareMatrix(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}

void test_transposeSquareMatrix3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, -8,
                    -6, 0, 6,
                    79, 5, 93},
            3, 3);
    matrix endMatrix = createMatrixFromArray(
            (int[]){
                    3, -6, 79,
                    6, 0, 5,
                    -8, 6, 93},
            3, 3);
    transposeSquareMatrix(testMatrix);

    assert(areTwoMatricesEqual(testMatrix, endMatrix));
}


void test_transposeSquareMatrix() {
    test_transposeSquareMatrix1();
    test_transposeSquareMatrix2();
    test_transposeSquareMatrix3();
}

void test_getMinValuePos1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, -8,
                    -6, 0, 6,
                    79, 5, 93},
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {0, 2};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);
}

void test_getMinValuePos2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, 0,
                    -6, -8, 6,
                    79, 5, 93},
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {1, 1};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);
}

void test_getMinValuePos3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, 0,
                    -6, 8, 6,
                    79, 5, -93},
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {2, 2};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);
}

void test_getMinValuePos4() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, 0,
                    -6, 8, 6,
                    -79, 5, 93},
            3, 3);
    position pos = getMinValuePos(testMatrix);
    position minVauePos = {2, 0};

    assert(pos.rowIndex == minVauePos.rowIndex && pos.colIndex == minVauePos.colIndex);
}

void test_getMinValuePos() {
    test_getMinValuePos1();
    test_getMinValuePos2();
    test_getMinValuePos3();
    test_getMinValuePos4();
}

void test_getMaxValuePos1() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, 0,
                    -6, 8, 6,
                    -79, 5, 93},
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {2, 2};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);
}

void test_getMaxValuePos2() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 666, 0,
                    -6, 8, 6,
                    -79, 5, 93},
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {0, 1};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);
}

void test_getMaxValuePos3() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, 0,
                    -6, 8, 6,
                    79, 5, -93},
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {2, 0};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);
}

void test_getMaxValuePos4() {
    matrix testMatrix = createMatrixFromArray(
            (int[]){
                    3, 6, 0,
                    -6, 8, 876,
                    -79, 5, 93},
            3, 3);
    position pos = getMaxValuePos(testMatrix);
    position maxVauePos = {1, 2};

    assert(pos.rowIndex == maxVauePos.rowIndex && pos.colIndex == maxVauePos.colIndex);
}

void test_getMaxValuePos() {
    test_getMaxValuePos1();
    test_getMaxValuePos2();
    test_getMaxValuePos3();
    test_getMaxValuePos4();
}

void test_matrix() {
    test_getMemMatrix();
    test_swapRows();
    test_swapColumns();
    test_isSquareMatrix();
    test_twoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {

    test_matrix();

    return 0;
}
