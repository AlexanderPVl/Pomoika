#include <stdio.h>
#include <malloc.h>

void scan(int *k){
	signed int sign = 1;
	int r = 0;
	char c;
	while ((((c = getchar()) == ' ') || (c - '0' < 0) || (c - '0' > 9)) && (c != '-'));
	if (c == '-')
		sign = -1;
	if ((c - '0' >= 0) && (c - '0' <= 9))
		r += c - '0';
	while ((c = getchar()) != '\n' && (c != ' ')){
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
	printf("\nArray: ");
	for (i = 0; i < count; i++)
		printf("%d ", *(adres + i));
	printf("\n");
	return (0);
}

int Solution(int *adres, int *count){
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return (-1);
	}
	int max, i = 0, ind = 0, c, j, excess = 0;
	for (max = *adres; i < *count; i++){
		if ((c = *(adres + i)) >= max){
			ind = i;
			max = c;
		}
	}

	for (i = ind; i >= 0; i--)
		if (*(adres + i) % 2 == 0){
			for (j = i + 1; j < *count; j++)
				*(adres + j - 1) = *(adres + j);
			*count -= 1;
		}
	printf("count = %d", *count);
}

int main(){
	int *adres, X;
	int k = 0;
	printf("Enter number of elements: ");
	do{
		scan(&k);
		if (k > 0 && k <= 20)
			break;
	} while (k <= 0, printf("Enter positive number under 20 (you entered %d): ", k));
	printf("k = %d\n", k);
	adres = (int*)malloc(k*sizeof(int));

	InputArray(adres, k);
	PrintArray(adres, k);

	Solution(adres, &k);
	PrintArray(adres, k);

	free(adres);
	return 0;
}
