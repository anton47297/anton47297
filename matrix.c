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
    scanf("%d %d %d", &**(m->values), &m->nRows, &m->nRows);
}

// ввод массива из
// nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

// вывод матрицы m
void outputMatrix(matrix m) {
    printf("%d %d %d", **(m.values), m.nRows, m.nRows);
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
    int rowsCriteria[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        rowsCriteria[i] = criteria(m.values[i], m.nRows);
    for (int i = 1; i < m.nRows; i++) {
        for (int j = i; j > 0 && rowsCriteria[j - 1] > rowsCriteria[j]; j--) {
            swap(&rowsCriteria[j - 1], &rowsCriteria[j]);
            swapRows(m, j, j - 1);
        }
    }
}

// выполняет сортировку вставками
// столбцов матрицы m по не убыванию значения функции criteria
// применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
    int colsCriteria[m.nCols];
    for (int i = 0; i < m.nCols; i++) {
        int colsElements[m.nRows];
        for (int j = 1; j < m.nRows; j++)
            colsElements[j] = m.values[j][i];
        colsCriteria[i] = criteria(colsElements, m.nRows);
    }
    for (int i = 1; i < m.nCols; i++) {
        for (int j = i; j > 0 && colsCriteria[j - 1] > colsCriteria[j]; j--) {
            swap(&colsCriteria[j - 1], &colsCriteria[j]);
            swapRows(m, j, j - 1);
        }
    }
}

// возвращает значение ’истина’, если
// матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix m) {
    if (m.nRows == m.nCols)
        return true;
    else
        return false;
}

// возвращает значение
// ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.values == m2.values)
        return true;
    else
        return false;
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
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            m.values[j][i] = m.values[i][j];
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
