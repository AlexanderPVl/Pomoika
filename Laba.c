#include <stdio.h>
#include <malloc.h>

void scan(int *k){
	signed short int sign = 1;
	int r = 0;
	char c;
	while ((((c = getchar()) == ' ') || (c - '0' < 0) || (c - '0' > 9)) && (c != '-'));
	if (c == '-')
		sign = -1;
	if ((c - '0' >= 0) && (c - '0' <= 9))
		r += c - '0';
	while ((c = getchar()) != '\n' && (c!=' ')){
		if ((c - '0' >= 0) && (c - '0' <= 9)){
			r = r * 10 + sign*(c - '0');
		}
	}
	*k = r;
}

int InputArray(int *adres, int count){
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return (-1);
	}
	printf("\nEnter Array: ");
	int k, i = 0;
	for (i = 0; i < count; i++){
		scan(&k);
		*(adres + i) = k;
	}
	return (0);
}

int PrintArray(int *adres, int count){
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return (-1);
	}
	int i;
	printf("\nYour Array: ");
	for (i = 0; i < count; i++)
		printf("%d ", *(adres + i));
	printf("\n");
	return (0);
}

int Solution1(int *adres, int count, int X){
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return (-1);
	}
	int i = 0, min, c;
	while (*(adres + i) <= X && i < count)
		i++;
	if (i == count){
		printf("No solution\n");
		return (0);
	}
	else
		min = *(adres + i);
	for (; i < count; i++)
		if (((c = *(adres + i))> X) && c < min)
			min = c;
	if (min > X)
		printf("Min = %d\n", min);
	else
		printf("No solution");
	return (0);
}

int main(){
	int *adres, X;
	int k = 0;
	printf("Enter number of elements: ");
	do{
		scan(&k);
		if (k > 0)
			break;
	}
	while (k <= 0 , printf("Enter positive number: ", k));
	printf("k = %d\n", k);
	adres = (int*)malloc(k*sizeof(int));

	InputArray(adres, k);
	PrintArray(adres, k);

	printf("Enter X: ");
	scan(&X);

	Solution1(adres, k, X);

	free(adres);
	return 0;
}
