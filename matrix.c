#include "matrix.h"

// размещает в динамической памяти матрицу размером nRows на nRows
// возвращает матрицу
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nRows
// возвращает указатель на нулевую матрицу.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

// освобождает память, выделенную под
// хранение матрицы m
void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

// ввод матрицы m
void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        for (int j = 0; j < m->nCols; j++) {
            scanf("%d", &m->values[i][j]);
        }
    }
}

// ввод массива из
// nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

// вывод матрицы m
void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

//  вывод массива из nMatrices матриц, хранящейся по адресу ms
void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
    }
}

// обмен строк с порядковыми
// номерами i1 и i2 в матрице m
void swapRows(matrix m, int i1, int i2) {
    int *temp = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = temp;
}

// обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2) {
    int *t = m.values[j1];
    m.values[j1] = m.values[j2];
    m.values[j2] = t;
}

// выполняет сортировку вставками строк
// матрицы m по не убыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
    int *rows = (int *) malloc(sizeof(int) * m.nRows);
    for (int rIndex = 0; rIndex < m.nRows; ++rIndex)
        rows[rIndex] = criteria(m.values[rIndex], m.nCols);
    for (int rIndex = 1; rIndex < m.nRows; ++rIndex) {
        int curIndex = rIndex;
        while (curIndex > 0 && rows[curIndex] < rows[curIndex - 1]) {
            swapRows(m, curIndex, curIndex - 1);
            universalSwap(&rows[curIndex], &rows[curIndex - 1], sizeof(int));
            curIndex--;
        }
    }
}

// выполняет сортировку вставками
// столбцов матрицы m по не убыванию значения функции criteria
// применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int *cols = (int *) malloc(sizeof(int) * m.nCols);
    int *curCols = malloc(sizeof(int) * m.nRows);
    for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
        for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
            curCols[rIndex] = m.values[rIndex][cIndex];
        }
        cols[cIndex] = criteria(curCols, m.nRows);
    }
    for (int cIndex = 1; cIndex < m.nCols; ++cIndex) {
        int curIndex = cIndex;
        while (curIndex > 0 && cols[curIndex] < cols[curIndex - 1]) {
            swapColumns(m, curIndex, curIndex - 1);
            universalSwap(&cols[curIndex], &cols[curIndex - 1], sizeof(int));
            curIndex--;
        }
    }
}

// возвращает значение ’истина’, если
// матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

// возвращает значение
// ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;
    for (int rIndex = 0; rIndex < m1.nRows; rIndex++) {
        for (int cIndex = 0; cIndex < m1.nCols; ++cIndex) {
            if (m1.values[rIndex][cIndex] != m2.values[rIndex][cIndex])
                return false;
        }
    }
    return true;
}

// возвращает значение ’истина’, если матрица
// m является единичной, ложь – в противном случае
bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] != 1 || (i != j && m.values[i][j] != 0))
                return false;
    return true;
}

// возвращает значение ’истина’, если
// матрица m является симметричной, ложь – в противном случае
bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < i; ++j) {
            if (m.values[i][j] != m.values[j][i])
                return false;
        }
    }
    return true;
}

// транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));
    for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
        for (int cIndex = 0; cIndex < rIndex; ++cIndex) {
            if (rIndex != cIndex)
                universalSwap(&m.values[rIndex][cIndex], &m.values[cIndex][rIndex], sizeof(int));
        }
    }
}

// возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m) {
    position minPos = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position curPos = {i, j};
            if (m.values[curPos.rowIndex][curPos.colIndex] < m.values[minPos.rowIndex][minPos.colIndex])
                minPos = curPos;
        }
    }
    return minPos;
}

// возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m) {
    position maxPos = {0, 0};
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = 0; j < m.nCols; ++j) {
            position curPos = {i, j};
            if (m.values[curPos.rowIndex][curPos.colIndex] > m.values[maxPos.rowIndex][maxPos.colIndex])
                maxPos = curPos;
        }
    }
    return maxPos;
}

// возвращает матрицу, размера nRows на nRows,
// построенного из элементов массива a, размещенную в динамической
// памяти
matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);
    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];
    return m;
}

// возвращает указатель на нулевую матрицу массива из nMatrices матриц, размещенных
// в динамической памяти, построенных из элементов массива a
matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];
    return ms;
}

/* 2 часть */

/* 1 task */
void swapRowsWithMinValuesAndMaxValues(matrix m) {
    position maxPos = getMaxValuePos(m);
    position minPos = getMinValuePos(m);

    swapRows(m, maxPos.rowIndex, minPos.rowIndex);
}

/* 2 task */
int getMax(int *a, const size_t n) {
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void sortRowsByMinElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

/* 3 task */

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

/* 4 task */

matrix mulMatrices(matrix m1, matrix m2) {
    assert(m1.nCols == m2.nRows);
    matrix newMatrix = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m1.nRows; i++) {
        for (int j = 0; j < m2.nCols; j++) {
            newMatrix.values[i][j] = 0;
            for (int k = 0; k < m1.nCols; k++) {
                newMatrix.values[i][j] += m1.values[i][k] * m2.values[k][j];
            }
        }
    }
    return (matrix) newMatrix;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (!isSymmetricMatrix(*m))
        return;

    matrix squareMatrix = mulMatrices(*m, *m);

    *m = squareMatrix;
}

/* 5 task */

bool isUnique(long long *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
            return false;
    return true;
}

long long getSum(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    return sum;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    int *sum = (int *) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nRows; ++i) {
        sum[i] = getSum(m.values[i], m.nCols);
    }

    if (!isUnique(sum, m.nRows))
        return;

    transposeSquareMatrix(m);
}

/* 6 task */

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    if (m1.nRows != m2.nRows || m1.nCols != m2.nCols)
        return false;

    matrix m = mulMatrices(m1, m2);
    bool result = isEMatrix(m);

    freeMemMatrix(m);

    return result;
}

/* 7 task */

int max(int a, int b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    int nDiagonal = m.nRows + m.nCols - 1;
    int *diagonalMaxEl = malloc(sizeof(int) * nDiagonal);
    int diagonalStartIndex = m.nRows - 1;

    for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
        for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
            int dIndex = diagonalStartIndex + cIndex - rIndex;

            if (rIndex == 0 || cIndex == 0)
                diagonalMaxEl[dIndex] = m.values[rIndex][cIndex];
            else
                diagonalMaxEl[dIndex] = max(diagonalMaxEl[dIndex], m.values[rIndex][cIndex]);
        }
    }
    diagonalMaxEl[diagonalStartIndex] = 0;

    long long res = getSum(diagonalMaxEl, nDiagonal);

    free(diagonalMaxEl);

    return res;
}

/* 8 task */

int min(int a, int b) {
    return a > b ? b : a;
}

int getMinInArea(matrix m) {
    position maxPos = getMaxValuePos(m);

    int rIndex = maxPos.rowIndex;
    int leftCols = maxPos.colIndex;
    int rightCols = maxPos.colIndex;
    int minVl = m.values[maxPos.rowIndex][maxPos.colIndex];

    while (rIndex >= 0) {
        for (int i = leftCols; i < rightCols; ++i)
            minVl = min(m.values[rIndex][i], minVl);

        if (leftCols > 0)
            leftCols--;

        if (rightCols + 1 < m.nCols)
            rightCols++;

        rIndex--;
    }

    return minVl;
}

/* 9 task */

float getDistance(int *a, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i] * a[i];

    return sqrt(sum);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)) {
    float *criteriaArray = (float *) malloc(sizeof(float) * m.nRows);
    for (int i = 0; i < m.nRows; ++i) {
        criteriaArray[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 0; i < m.nRows; ++i) {
        for (int j = i; j > 0 && criteriaArray[j - 1] > criteriaArray[j]; j--) {
            universalSwap(&criteriaArray[j - 1], &criteriaArray[j], sizeof(float));
            swapRows(m, j, j - 1);
        }
    }
    free(criteriaArray);
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

/* 10 task */

int cmp_long_long(const void *pa, const void *pb) {
    long long arg1 = *(const long long *) pa;
    long long arg2 = *(const long long *) pb;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

int countNUnique(long long *a, int n) {
    qsort(a, n, sizeof(long long), cmp_long_long);
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1])
            count++;
    }
    return count;
}

int countEqClassesByRowsSum(matrix m) {
    long long *sum = malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; ++i)
        sum[i] = getSum(m.values[i], m.nCols);
    int res = countNUnique(sum, m.nRows);

    free(sum);

    return res;
}

/* 11 task */

int getNSpecialElement(matrix m) {
    int count = 0;

    for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
        for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
            bool left = false;
            if (cIndex == 0)
                left = true;

            if (!left) {
                int max = getMax(m.values[rIndex], cIndex);
                if (max < m.values[rIndex][cIndex])
                    left = true;
            }

            bool right = false;
            if (m.nCols - 1 == cIndex)
                right = true;

            if (!right) {
                int min = getMin(m.values[rIndex] + cIndex + 1, m.nCols - cIndex - 1);
                if (min > m.values[rIndex][cIndex])
                    right = true;
            }
            if (left && right)
                count++;
        }
    }
    return count;
}

/* 12 task */

position getLeftMin(matrix m) {
    position minPos = {0, 0};
    for (int rIndex = 0; rIndex < m.nRows; ++rIndex) {
        for (int cIndex = 0; cIndex < m.nCols; ++cIndex) {
            position pos = {rIndex, cIndex};
            if (m.values[rIndex][cIndex] < m.values[minPos.rowIndex][minPos.colIndex] ||
                m.values[rIndex][cIndex] == m.values[minPos.rowIndex][minPos.colIndex] && cIndex < minPos.colIndex)
                minPos = pos;
        }
    }
    return minPos;
}

void swapPenultimateRow(matrix m) {
    position minPos = getLeftMin(m);
    int *col = malloc(sizeof(int) * m.nRows);
    for (int rIndex = 0; rIndex < m.nRows; ++rIndex)
        col[rIndex] = m.values[rIndex][minPos.colIndex];

    memcpy(m.values[m.nRows - 2], col, sizeof(int) * m.nCols);

    free(col);
}

/* 13 task */

bool isNonDescendingSorted(int *a, int n) {
    for (size_t i = 1; i < n; i++) {
        if (a[i] < a[i - 1])
            return false;
    }
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (size_t i = 0; i < m.nRows; i++) {
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    }
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int nRightMatrix = 0;
    for (size_t i = 0; i < nMatrix; i++) {
        nRightMatrix += hasAllNonDescendingRows(ms[i]);
    }
    return nRightMatrix;
}

/* 14 task */

int countValues(const int *a, int n, int value) {
    int count = 0;
    for (size_t i = 0; i < n; i++) {
        if (a[i] == value)
            count++;
    }
    return count;
}

int countZeroRows(matrix m) {
    int countZeroR = 0;
    for (size_t i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            countZeroR++;
    }
    return countZeroR;
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int maxZeroMatrix[nMatrix];
    for (size_t i = 0; i < nMatrix; i++) {
        maxZeroMatrix[i] = countZeroRows(ms[i]);
    }
    int max = maxArray(maxZeroMatrix, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (maxZeroMatrix[i] == max)
            outputMatrix(ms[i]);
}

/* 15 task */

int getNormMatrix(matrix ms) {
    position minPos = getMinValuePos(ms);
    position maxPos = getMaxValuePos(ms);
    int norm = max(abs(ms.values[maxPos.rowIndex][maxPos.colIndex]),
                   abs(ms.values[minPos.rowIndex][minPos.colIndex]));

    return norm;
}

void printOfMatricesInTheMinNorm(matrix *ms, int nMatrix) {
    int *normMatrix = (int *) malloc(sizeof(int) * nMatrix);

    for (int i = 0; i < nMatrix; ++i)
        normMatrix[i] = getNormMatrix(ms[i]);

    int minNorm = getMin(normMatrix, nMatrix);

    for (int i = 0; i < nMatrix; ++i) {
        if (minNorm == normMatrix[i])
            outputMatrix(ms[i]);
    }
}
