//the working program!!!!
#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int array[], int length)
{
    // Insertion sort logic
    for (int i = 1; i < length; i++)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void printSpiral(int rows, int cols, int matrix[rows][cols], int array[])
{
    // Clockwise spiral fill logic
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    int index = 0;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            matrix[top][i] = array[index++];
        top++;

        for (int i = top; i <= bottom; i++)
            matrix[i][right] = array[index++];
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                matrix[bottom][i] = array[index++];
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                matrix[i][left] = array[index++];
            left++;
        }
    }
}

int main()
{
    int rows, cols;
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);
    int matrix[rows][cols];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

   /* printf("\nThe entered matrix is:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }*/

    // Convert 2D matrix to 1D array
    int length = rows * cols;
    int array[length];
    int index = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[index++] = matrix[i][j];
        }
    }

    InsertionSort(array, length);

   /* printf("\nSorted 1D array using Insertion Sort:\n");
    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
        printf("\n");

   */

    printf("\nSorted 2D array using Insertion Sort (as a matrix):\n");
    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
        if ((i + 1) % cols == 0)
        printf("\n");
    }


    printSpiral(rows, cols, matrix, array);

    printf("\nMatrix in a clockwise spiral pattern:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

