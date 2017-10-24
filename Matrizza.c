#include <stdio.h>
#define LINESOFMATRIX 4
#define COLUMNSOFMATRIX 4
float max = -1;

int Sgn(int n)
{
	return((n % 2 == 1) ? 1 : -1);
}

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
	return(arr + CountOfColumns*(Line - 1) + Column - 1);
}

float DeletColumn(float* arr, int Column, int NumberOfLines, int NumberOfColumns)
{
	if (Column>0 && Column <= NumberOfColumns)
	{
		for (int i = 1; i <= NumberOfLines; i++)
		{
			*AdresOfElement(arr, i, Column, NumberOfColumns) = max;
		}
	}
}

float DeletLine(float* arr, int Line, int NumberOfLines, int NumberOfColumns)
{
	if (Line>0 && Line <= NumberOfLines)
	{
		for (int i = 1; i < NumberOfColumns; i++)
		{
			*AdresOfElement(arr, Line, i, NumberOfColumns) = max;
		}
	}
}

float ChangeColumns(float* arr, int Column1, int Column2, int NumberOfLines, int NumberOfColumns)
{
	float bufer;
	if (Column1>0 && Column2>0 && Column1 <= NumberOfColumns && Column2 <= NumberOfColumns)
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
	printf("\n");
}

float* MakeDopMatrix(int Line, int Column, int NumberOfLines, int NumberOfColumns, float* arr)
{
	int i = 0, j = Column + 1;

	while (j <= NumberOfColumns && *AdresOfElement(arr, 1, j, NumberOfColumns) != max)
	{
		ChangeColumns(arr, j - 1, j, NumberOfLines, NumberOfColumns);
		j++;
	}
	DeletColumn(arr, j - 1, NumberOfLines, NumberOfColumns);

	j = Line + 1;
	while (j <= NumberOfLines && *AdresOfElement(arr, j, 1, NumberOfColumns) != max)
	{
		ChangeLines(arr, j - 1, j, NumberOfLines, NumberOfColumns);
		j++;
	}
	DeletLine(arr, j - 1, NumberOfLines, NumberOfColumns);

	return(arr);
}

void SizeOfArray(float* arr, int* Lines, int* Columns, int CountOfLines, int CountOfColumns)
{

	int i = 0, j = 0;
	while (*(arr + i) != max && i<CountOfLines)
		i++;
	*Columns = i;
	while (*(arr + CountOfLines*j) != max && j < CountOfColumns)
		j++;
	*Lines = j;
}

float Opr2x2(float* arr, int Columns)
{
	if (*(AdresOfElement(arr, 1, 1, Columns)) != max && *(AdresOfElement(arr, 1, 2, Columns)) != max && *(AdresOfElement(arr, 2, 1, Columns)) != max && *(AdresOfElement(arr, 2, 2, Columns)) != max)
		return (*(AdresOfElement(arr, 1, 1, Columns))*(*AdresOfElement(arr, 2, 2, Columns)) - *(AdresOfElement(arr, 1, 2, Columns))*(*AdresOfElement(arr, 2, 1, Columns)));

}

float Det(float* arr, int Lines, int Columns)
{
	float Arr[LINESOFMATRIX][COLUMNSOFMATRIX];
	float DopArr[LINESOFMATRIX][COLUMNSOFMATRIX];
	EqualArrays(Arr, arr, Lines, Columns);

	int lines = 0, columns = 0;
	float s = 0;
	SizeOfArray(Arr, &lines, &columns, LINESOFMATRIX, COLUMNSOFMATRIX);

	for (int i = 1; i <= columns; i++)
	{

		if (lines > 2 && columns > 2)
		{
			EqualArrays(DopArr, Arr, Lines, Columns);
			s += Sgn(i)*(*AdresOfElement(Arr, 1, i, COLUMNSOFMATRIX))*Det(MakeDopMatrix(1, i, lines, Columns, DopArr), Lines, Columns);
		}
		else if (lines == 2 && columns == 2)
		{
			s += (Opr2x2(Arr, COLUMNSOFMATRIX));
			break;
		}

	}
	return(s);
}

void main()
{
	float Matrix[LINESOFMATRIX][COLUMNSOFMATRIX];

	for (int i = 0; i < LINESOFMATRIX; i++)
		for (int j = 0; j < COLUMNSOFMATRIX; j++)
		{
			scanf("%f", &Matrix[i][j]);
			if (Matrix[i][j]>max)
			{
				max = Matrix[i][j];
			}
		}
	max++;

	printf("\n");

	PrintArr(Matrix, LINESOFMATRIX, COLUMNSOFMATRIX); //pechataet massiv

	printf("\n");
	printf("%f\n", Det(Matrix, LINESOFMATRIX, COLUMNSOFMATRIX));

}
