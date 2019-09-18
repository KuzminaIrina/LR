#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
const int nmax = 100;
int Minimum(double x[],  int m) ;
int Zeros (double x[][nmax], int m, int n);
int vivod (double z[], int m, FILE* file) ;
int ArrayInput (int& n, int& m, double x[][nmax], char* fname);
int ArrayOutput (int n, int m, double x[][nmax], FILE* file);

int Minimum(double x[],  int m)  {
   int i, j;
   double z;
   z=x[0];
   for (i = 0; i < m; i++) {
         if (x[i] <  z )
            z = x[i];
   }
   return z;
  }

int Zeros (double x[][nmax], int m, int n) {
    int k, i,j;
    k=0;
    for (i=0; i<m; i++)
        for (j=0; j<n; j++)
         if (x[i][j]==0)
          k++;
    return k;
}
int vivod (double z[], int m, FILE* file) {
  for (int i=0; i<m; i++) {
   fprintf(file, " Наименьший элемент в %d строке:", i+1);
   fprintf(file,"%lf ", z[i]);
   fprintf(file,"\n");
  }
   return 0;
}



int ArrayInput (int& n, int& m, double x[][nmax], char* fname) {
FILE *file;
   if ((file = fopen(fname, "r")) == NULL)
     printf("Невозможно открыть файл '%s'\n", fname);

  else if (fscanf(file, "%d%d", &m, &n) < 2)
    { printf ("Ошибка чтения из файла '%s'\n", fname);
      fclose(file);
     }
  else if (m < 0 || m > nmax || n < 0 || n > nmax)
    printf("Количество строк и столбцов матрицы должны быть от 1 до %d!\n", nmax);
  else
    for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
     if (fscanf(file, "%lf", &x[i][j]) < 1)
      { printf ("Ошибка чтения из файла '%s'\n", fname);
        fclose(file);
        return 0;
       }
   fclose(file);
   return 1;
}

int ArrayOutput (int n, int m, double x[][nmax], FILE* file) {
    fprintf(file, "Полученная матрица:\n");
  for (int i=0; i<m; i++) {
    for (int j=0; j<n; j++)
    fprintf(file, "%lf ", x[i][j]);
    fprintf(file,"\n");
    }
    fprintf(file,"\n");
   return 1;
 }

int main(int argc, char *argv[]) {
   double a[nmax][nmax], b[nmax][nmax], z[nmax];
   int m1, n1, m2, n2,  K1, K2;
   setlocale(LC_ALL, "rus");
   if (argc < 2)
    printf("Недостаточно параметров!\n");

   else if (ArrayInput(n1, m1, a, argv[1]))
     {
  if (ArrayInput(n2, m2, b, argv[2]))
     {
  FILE* file;
    if ((file=fopen(argv[3], "w")) == NULL)
     printf("Невозможно открыть файл '%s'\n", file);
    else {
  ArrayOutput(n1, m1, a, file);
  ArrayOutput(n2, m2, b, file);
  K1=Zeros(a, m1, n1);
    fprintf(file,"Количество нулевых элементов 1: %d\n", K1);
  K2=Zeros(b, m2, n2);
    fprintf(file,"Количество нулевых элементов 2: %d\n", K2);
    if (K1<K2) {
    for (int i=0; i<m1; i++)
      z[i]=Minimum (a[i], m1);
       vivod(z, m1, file);
    }
    else if (K1>K2) {
    for (int i=0; i<m2; i++)
      z[i]=Minimum (b[i], m2);
       vivod(z, m2, file);
    }

    else
        fprintf(file, "В двух матрицах количество нулевых элементов одинаково\n");
     return 0;
  } } } }
