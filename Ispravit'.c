#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <math.h> 
#include <malloc.h> 
 
double* inputArray(int *n); 
{ 
 int size; 
 double *a; 
 while (1) 
 
 { 
  printf("введите количество элементов массива = "); 
  scanf_s("%d", &size); 
  if ((size <= 0) || (size >= 20)) continue; 
  a = (double *)malloc(size * sizeof(double)); 
  if (a) break; 
 } 
 
 double *task(double *a, int *n) 
 { 
  for (j = 0; j < size; j++) 
  { 
   printf("%d элемент массива = ", j + 1); 
   scanf_s("%lf", a + j); 
  } 
  *n = size; 
  return a; 
 } 
} 
 void main() 
{ 
 
 setlocale(LC_ALL, "RUS"); 
 double *a, max, max2; 
 int e, t, n, i, j, k, o, p, r, index, index2; 
 
 
 t = 0; 
 index = 0; 
 index2 = 0; 
 a = inputArray(&n); 
 a = task(a, &n); 
 
} 
 
for (i = 0; i < n; i++) 
{ 
 printf("\na[%d]= %lf", i, a[i]); 
} 
 
 
max = 0; 
for (k = 0; k < n; k++) 
{ 
 if (a[k] > max) 
 { 
  max = a[k]; 
  index = k; 
 } 
} 
max2 = 0; 
for (p = 0; p < index; p++) 
{ 
 if (a[p]>max2) 
 { 
  if (max2 != max) 
  { 
   max2 = a[p]; 
   index2 = p; 
  } 
 } 
} 
for (o = (index + 1); o < n; o++) 
{ 
 if (a[o]>max2) 
 { 
  if (max2 != max) 
  { 
   max2 = a[o]; 
   index2 = o; 
  } 
 } 
} 
printf("\n%d", index2); 
printf("\n%lf", max2); 
printf("\n%lf", max); 
for (e = 0; e < index2; e++) 
 if (a[e] < 0) 
 { 
  a[e] = 0; 
 } 
for (r = 0; r < n; r++) 
{ 
 if (a[r] != 0) 
 { 
  printf("\n a[%d]=%lf", r, a[r]); 
 } 
} 
free(a); 
system("pause"); 
 
}
