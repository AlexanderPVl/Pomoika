#include <stdio.h>
#define LINESOFMATRIX 6
#define COLUMNSOFMATRIX 7

int* AdresOfElement(int* arr, int Line, int Column, int CountOfColumns)
{
	return(arr + CountOfColumns*(Line - 1) + Column);
}

int NullColumn(int* arr, int Column, int NumberOfLines, int NumberOfColumns)
{
	if (Column>0 && Column <= NumberOfColumns)
	{
		for (int i = 1; i <= NumberOfLines; i++)
		{
			*AdresOfElement(arr, i, Column - 1, NumberOfColumns) = -1;

		}
	}
}

int NullLine(int* arr, int Line, int NumberOfLines, int NumberOfColumns)
{
	if (Line>0 && Line <= NumberOfLines)
	{
		for (int i = 1; i < NumberOfColumns; i++)
		{
			*AdresOfElement(arr, Line, i-1, NumberOfColumns) = -1;

		}
	}
}

int ChangeColumns(int* arr, int Column1, int Column2, int NumberOfLines, int NumberOfColumns)
{
	int bufer;
	if (Column1>0 && Column2>0 && Column1<=NumberOfColumns && Column2<=NumberOfColumns)
	{
		for (int i = 1; i <= NumberOfLines; i++)
		{
			bufer = *AdresOfElement(arr, i, Column1-1, NumberOfColumns);
			*AdresOfElement(arr, i, Column1-1, NumberOfColumns) = *AdresOfElement(arr, i, Column2-1, NumberOfColumns);
			*AdresOfElement(arr, i, Column2-1, NumberOfColumns) = bufer;
		}
	}
}

int ChangeLines(int* arr, int Line1, int Line2, int NumberOfLines, int NumberOfColumns)
{
	int bufer;
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

void PrintArr(int* arr, int Lines, int Columns)
{
	for (int i = 0; i < Lines; i++)
	{
		for (int j = 0; j < Columns; j++)
			printf("%d\t", *(arr + i*(Columns)+j));
		printf("\n");
	}

}

int* MakeDopMatrix(int Line, int Column, int NumberOfLines, int NumberOfColumns, int* arr)
{
	int i = 0, j = Column;

	while (j <= NumberOfColumns && *AdresOfElement(arr, NumberOfLines, j, NumberOfColumns) != -1)
	{
		ChangeColumns(arr, j-1, j, NumberOfLines, NumberOfColumns);
		j++;
	}
	NullColumn(arr, j-1, NumberOfLines, NumberOfColumns);

	j = Line;
	while (j < NumberOfLines && *AdresOfElement(arr, j, NumberOfColumns, NumberOfColumns) != -1)
	{
		ChangeLines(arr, j-1, j, NumberOfLines, NumberOfColumns);
		j++;
	}
	NullLine(arr, j, NumberOfLines, NumberOfColumns);


	PrintArr(arr, NumberOfLines, NumberOfColumns);
	return(arr);
}

void main()
{
	int Matrix[LINESOFMATRIX][COLUMNSOFMATRIX];

	for (int i = 0; i < LINESOFMATRIX; i++)
		for (int j = 0; j < COLUMNSOFMATRIX; j++)
		{
			//scanf("%d", &Matrix[i][j]);
			Matrix[i][j] = j+1;
		}

	printf("\n");

	PrintArr(Matrix, LINESOFMATRIX, COLUMNSOFMATRIX);

	printf("\n");

	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
	MakeDopMatrix(1, 1, LINESOFMATRIX, COLUMNSOFMATRIX, Matrix);
	printf("\n");
}
