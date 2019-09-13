#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
using namespace std;
const int nmax = 100;

int vvod (float a[], int n) {
for (int i=0; i<n; i++)
    scanf("%f", &a[i]);
   return 0;
 }
 int vivod (float a[], int n) {

  for (int i=0; i<n; i++)
    printf("%f\n", a[i]);
   return 0;
 }
 float SedneeArifm (float a[], int n, int t) {
  float sum, SR;
  int k;
  sum=0;
  k=0;
  SR=0;
  for (int i=0; i<n; i++) {
    if (a[i]<t) {
     sum+=a[i];
     k++;
   }
  }
  if (k<1)  SR=t+1;
  else SR=sum/k;
    return SR;
  }

int ArrayInput(int n, float x[], char fname)
 { FILE file;

   if ((fname = fopen(fname, "r")) == NULL)
    { printf("���������� ������� ���� '%s'\n", fname);
      return 0;
     }
   if (fscanf(file, "%d", n) < 1)
    { printf ("������ ������ �� ����� '%s'\n", fname);
      fclose(file);
      return 0;
     }
  if (n < 0 || n > nmax)
    { printf("���-�� ��-��� ������� ������ ���� �� 1 �� %d! (���� '%s')\n", nmax, fname);
      return 0;
     }
   for (int i = 0; i < n; i++)
    if (fscanf(file, "%f", x[i]) < 1)
     { printf ("������ ������ �� ����� '%s'\n", fname);
       fclose(file);
       return 0;
      }
   fclose(file);
   return 1;
  }
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus");
    if (argc <3)
    { printf("������������ ����������!\n");
      return 0;
     }
    int  t, n1, n2, n3;
    float a1[nmax], a2[nmax], a3[nmax], s1, s2, s3;
    if (!ArrayInput(n1, a1, argv[1]))
     return 0;
    if (!ArrayInput(n2, a2, argv[2]))
     return 0;
      if (!ArrayInput(n3, a3, argv[3]))
     return 0;
     printf("���������� 1 ������:\n");
    vivod(a1,n1);
     printf("���������� 2 ������:\n");
    vivod(a2,n2);
     printf("���������� 3 ������:\n");
    vivod(a3,n3);

    printf("������� ����� ");
    scanf("%d", &t);
    printf("%d \n", t);
    s1=0;
    s1=SedneeArifm (a1,  n1, t);
    s2=SedneeArifm (a2,  n2, t);
    s3=SedneeArifm (a3,  n3, t);
    if (s1>t)
        printf("� ������ ������� ��� �����, ������ ���������.\n");
    else
        printf("������� �������������� �����, ������� ��������� ����� %f\n", s1);
    if (s2>t)
        printf("�� ������ ������� ��� �����, ������ ���������.\n");
    else
        printf("������� �������������� �����, ������� ��������� ����� %f\n", s2);
    if (s3>t)
        printf("� ������� ������� ��� �����, ������ ���������.\n");
    else
        printf("������� �������������� �����, ������� ��������� ����� %f\n", s3);
    if ((s1<s2) && (s1<s3))
            printf("� ������ ������� ���������� ��������\n");
    else if ((s2<s1) && (s2<s3))
            printf("�� ������ ������� ���������� ��������\n");
    else if ((s3<s2) && (s3<s1))
            printf("� ������� ������� ���������� ��������\n");
    if (((s3=s2) || (s3=s1)) ||(s2=s1))
            printf("� 2� �������� �������� �����");
    else if ((s1=s2) && (s2=s3) && (s3=s1))
            printf("� 3� �������� �������� �����");
    return 0;
}
