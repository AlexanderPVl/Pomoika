#include <stdio.h>
#include <malloc.h>

int pow(int x, int a){
	int result = 1;
	while (0 < a--)
		result *= x;
	return result;
}

int scan(void *k, char type){	/*forms numeric from standart input*/
	signed int sign = 1;
	int r = 0, i = 1;
	double r1 = 0;
	char c;
	while ((((c = getchar()) == ' ') || (c - '0' < 0) || (c - '0' > 9)) && (c != '-'));
	if (c == '-')
		sign = -1;
	if ((c - '0' >= 0) && (c - '0' <= 9))
		r += c - '0';
	if (type == 'd'){			/*integer numeric*/
		while (((c = getchar()) != '\n') && (c != ' ') && (c != ',') && (c != '.')){
			if ((c - '0' >= 0) && (c - '0' <= 9)){
				r = r * 10 + sign*(c - '0');
			}
		}
		if (c == ',' || c == '.')
			while ((c = getchar()) != '\n');
		*((int*)k) = r;
		return 0;
	}
	else if (type == 'l'){			/*double numeric*/
		while (((c = getchar()) != '\n') && (c != ' ') && (c != ',' && c != '.')){
			if ((c - '0' >= 0) && (c - '0' <= 9)){
				r = r * 10 + sign*(c - '0');
			}
		}
		*((double*)k) = (double)r;
		if (c == ',' || c == '.'){
			while (((c = getchar()) != '\n') && (c != ' ')){
				if ((c - '0' >= 0) && (c - '0' <= 9))
					r1 = r1 + (double)sign*(c - '0') / (double)(pow(10, i++));
			}
		}
		*((double*)k) += r1;
	}
	else
		printf("enter correct type");
	return 0;
}

int InverseString(int *adr, int count1, int count2){		/*invertiruet count2 last elementov v array iz count1 elementov*/
	char a;
	int i;
	if (adr == NULL){
		printf("ADRES = NULL\n");
		return -1;
	}
	else if (count2 > count1)
		count2 = count1;
	for (i = 0; i < count2 / 2; i++){
		a = *(adr + count1 - count2 + i);
		*(adr + count1 - count2 + i) = *(adr + count1 - i - 1);
		*(adr + count1 - i - 1) = a;
	}
	return 0;
}

int InputArray(void *adres, int count, char type){
	int k, i = 0;
	double k1;
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return -1;
	}
	if (type == 'd'){	/*integer numeric*/
		for (i = 0; i < count; i++){
			scan(&k, 'd');
			*((int*)adres + i) = k;
		}
	}
	if (type == 'l'){	/*double numeric*/
		for (i = 0; i < count; i++){
			scan(&k1, 'l');
			*((double*)adres + i) = k1;
		}
	}
	return 0;
}

int PrintArray(void *adres, int count, char type){
	int i;
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return -1;
	}
	printf("\nArray: ");
	if (type == 'd'){	/*integer numeric*/
		for (i = 0; i < count; i++)
			printf("%d ", *((int*)adres + i));
	}
	if (type == 'l'){	/*double numeric*/
		for (i = 0; i < count; i++)
			printf("%lf ", *((double*)adres + i));
	}
	printf("\n");
	return 0;
}

int Solution1(int *adres, int count, int count2){
	int max, i = 0, ind = 0, c;
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return -1;
	}
	float average = 0;
	for (max = *adres; i < count; i++){
		if ((c = *(adres + i)) > max){
			ind = i;
			max = c;
		}
	}
	for (i = 0; i <= ind; i++){	/*finds average of all numerics before first maximum inclusively*/
		average += (float)*(adres + i);
	}
	average /= (float)(ind + 1);
	printf("Average = %f", average);
	InverseString(adres, count, count2);
	PrintArray(adres, count, 'd');
	return 0;
}

int Solution2(double** adres, int count){	/*summ of elements under glavnaya diagonal' incluziff*/
	int i, j;
	double summ = 0;
	if (adres == NULL){
		printf("\nADRES = NULL\n");
		return -1;
	}
	for (i = 0; i < count; i++)
		for (j = i; j < count; j++)
			summ += *(*(adres + j) + i);
	printf("\nSumm = %lf\n", summ);
	return 0;
}

int main(){
	int *adres;
	int k, N, i;
	double **adres1;

	printf("Solution 1: \n");
	printf("Enter number of elements: ");
	while (1){
		scan(&k, 'd');
		if (k > 0)
			break;
		else
			printf("Enter positive number: ");
	}
	printf("k = %d\n", k);
	printf("Enter N: ");
	while (1){
		scan(&N, 'd');
		if (N > 0)
			break;
		else
			printf("Enter positive number: ");
	}
	adres = (int*)malloc(k*sizeof(int));

	printf("Enter Array: ");
	InputArray((void*)adres, k, 'd'); /*makes one-dimensional integer array*/
	PrintArray(adres, k, 'd');
	Solution1(adres, k, N);
	free(adres);

	printf("\nSolution 2: \n");

	printf("Enter number of lines : ");
	while (1){
		scan(&k, 'd');
		if (k > 0)
			break;
		else
			printf("Enter positive number: ");
	}
	adres1 = (double**)malloc(k*sizeof(double*));
	for (i = 0; i < k; i++){
		*(adres1 + i) = (double*)malloc((k)*sizeof(double));
	}
	printf("Enter Matrix: ");
	for (i = 0; i < k; i++){	/*makes two-dimensional double array (square matrix)*/
		printf("line %d: \n", i+1);
		InputArray((void*)*(adres1 + i), k, 'l');
	}
	printf("%lf", *(adres1 + 1) + 1);

	Solution2(adres1, k);

	for (i = 0; i < k; i++){
		free(*(adres1 + i));
	}
	free(adres1);
}
