#include "matrix.h"

// размещает в динамической памяти матрицу размером nRows на nCols
// возвращает матрицу
matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

// размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols
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
    getMemMatrix(0, 0);
}

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices) {
    getMemArrayOfMatrices(ms, 0, 0);
    free(ms);
}

// ввод матрицы m
void inputMatrix(matrix *m) {
    scanf("%d %d %d", &**(m->values), &m->nCols, &m->nRows);
}

// ввод массива из
// nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(&ms[i]);
}

// вывод матрицы m
void outputMatrix(matrix m) {
    printf("%d %d %d", **(m.values), m.nRows, m.nCols);
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
}

// обмен колонок с порядковыми номерами j1 и j2 в матрице m
void swapColumns(matrix m, int j1, int j2) {
}

// выполняет сортировку вставками строк
// матрицы m по не убыванию значения функции criteria
// применяемой для строк
void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int *, int)) {
}

// выполняет сортировку вставками
// столбцов матрицы m по не убыванию значения функции criteria
// применяемой для столбцов
void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int *, int)) {
}

// возвращает значение ’истина’, если
// матрица m является квадратной, ложь – в противном случае
bool isSquareMatrix(matrix m) {
}

// возвращает значение
// ’истина’, если матрицы m1 и m2 равны, ложь – в противном случае.
bool twoMatricesEqual(matrix m1, matrix m2) {
    if (m1.values == m2.values)
        return true;
    else
        return false;
}

// возвращает значение ’истина’, если матрица
// m является единичной, ложь – в противном случае
bool isEMatrix(matrix m) {
}

// возвращает значение ’истина’, если
// матрица m является симметричной, ложь – в противном случае
bool isSymmetricMatrix(matrix m) {
}

// транспонирует квадратную матрицу m
void transposeSquareMatrix(matrix m) {
}

// возвращает позицию минимального элемента матрицы m
position getMinValuePos(matrix m) {
}

// возвращает позицию максимального элемента матрицы m
position getMaxValuePos(matrix m) {
}

// возвращает матрицу, размера nRows на nCols,
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
