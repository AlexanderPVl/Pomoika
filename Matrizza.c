#include <stdio.h>
#define LINESOFMATRIX 5
#define COLUMNSOFMATRIX 5

void EqualArrays(float* arr1, float* arr2, int Lines, int Columns)
{
	for (int i = 0; i < Lines; i++)
		for (int j = 0; j < Columns; j++)
		{
			*(arr1 + Columns*i + j) = *(arr2 + Columns*i + j);
		}
}

float* AdresOfElement(float* arr, int Line, int Column, int CountOfColumns)
{
	return(arr + CountOfColumns*(Line - 1) + Column-1);
}

float DeletColumn(float* arr, int Column, int NumberOfLines, int NumberOfColumns)
{
	if (Column>0 && Column <= NumberOfColumns)
	{
		for (int i = 1; i <= NumberOfLines; i++)
		{
			*AdresOfElement(arr, i, Column, NumberOfColumns) = -1;

		}
	}
}

float DeletLine(float* arr, int Line, int NumberOfLines, int NumberOfColumns)
{
	if (Line>0 && Line <= NumberOfLines)
	{
		for (int i = 1; i < NumberOfColumns; i++)
		{
			*AdresOfElement(arr, Line, i, NumberOfColumns) = -1;

		}
	}
}

float ChangeColumns(float* arr, int Column1, int Column2, int NumberOfLines, int NumberOfColumns)
{
	float bufer;
	if (Column1>0 && Column2>0 && Column1<=NumberOfColumns && Column2<=NumberOfColumns)
	{
		for (int i = 1; i <= NumberOfLines; i++)
		{
			bufer = *AdresOfElement(arr, i, Column1, NumberOfColumns);
			*AdresOfElement(arr, i, Column1, NumberOfColumns) = *AdresOfElement(arr, i, Column2, NumberOfColumns);
			*AdresOfElement(arr, i, Column2, NumberOfColumns) = bufer;
		}
	}
}

float ChangeLines(float* arr, int Line1, int Line2, int NumberOfLines, int NumberOfColumns)
{
	float bufer;
	if (Line1>0 && Line2>0 && Line1 <= NumberOfLines && Line2 <= NumberOfLines)
	{
		for (int i = 1; i <= NumberOfColumns; i++)
		{
			bufer = *AdresOfElement(arr, Line1, i, NumberOfColumns);
			*AdresOfElement(arr, Line1, i, NumberOfColumns) = *AdresOfElement(arr, Line2, i, NumberOfColumns);
			*AdresOfElement(arr, Line2, i, NumberOfColumns) = bufer;
		}
	}
}

void PrintArr(float* arr, int Lines, int Columns)
{
	for (int i = 0; i < Lines; i++)
	{
		for (int j = 0; j < Columns; j++)
			printf("%.2f\t", *(arr + i*(Columns)+j));
		printf("\n");
	}

}

float* MakeDopMatrix(int Line, int Column, int NumberOfLines, int NumberOfColumns, float* arr)
{
	int i = 0, j = Column;
	float Arr[LINESOFMATRIX][COLUMNSOFMATRIX];
	EqualArrays(Arr, arr, NumberOfLines, NumberOfColumns);

	while (j <= NumberOfColumns && *AdresOfElement(Arr, 1, j, NumberOfColumns) != -1)
	{
		ChangeColumns(Arr, j - 1, j, NumberOfLines, NumberOfColumns);
		j++;
	}
	DeletColumn(Arr, j - 1, NumberOfLines, NumberOfColumns);

	j = Line;
	while (j <= NumberOfLines && *AdresOfElement(Arr, j, 1, NumberOfColumns) != -1)
	{
		ChangeLines(Arr, j - 1, j, NumberOfLines, NumberOfColumns);
		j++;
	}
	DeletLine(Arr, j - 1, NumberOfLines, NumberOfColumns);


	PrintArr(Arr, NumberOfLines, NumberOfColumns);
	return(Arr);
}

void main()
{
	float Matrix[LINESOFMATRIX][COLUMNSOFMATRIX];

	for (int i = 0; i < LINESOFMATRIX; i++)
		for (int j = 0; j < COLUMNSOFMATRIX; j++)
		{
			//scanf("%d", &Matrix[i][j]);
			Matrix[i][j] = 10*(i+1)+j+1;
		}

	printf("\n");

	PrintArr(Matrix, LINESOFMATRIX, COLUMNSOFMATRIX);

	printf("\n");

	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
	PrintArr(MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix) , LINESOFMATRIX, COLUMNSOFMATRIX);

}
