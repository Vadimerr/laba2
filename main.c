#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h>
#include <time.h>

void bSort(unsigned char* mas, int n)
{
  int i = 0, j = 0;
  unsigned char temp = 0;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n - i - 1; j++)
    {
      if (mas[j] > mas[j + 1])
      {
        temp = mas[j];
        mas[j] = mas[j + 1];
        mas[j + 1] = temp;
      }
    }
  }
}

void qSort(unsigned char* mas, int n)
{
  int i = 0;
  int j = n - 1;
  int tmp = 0;
  int c = mas[n / 2];

  do
  {
    while (mas[i] < c) i++;
    while (mas[j] > c) j--;

    if (i <= j)
    {
      tmp = mas[i];
      mas[i] = mas[j];
      mas[j] = tmp;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > 0) qSort(mas, j + 1);
  if (i < n) qSort(&mas[i], n - i);
}

void iSort(unsigned char* mas, int n)
{
  unsigned char temp = 0;
  for (int i = 0; i < n; i++)
  {
    temp = mas[i];
    int j = i;
    while ((j > 0) && (mas[j - 1] > temp))
    {
      mas[j] = mas[j - 1];
      j--;
    }
    mas[j] = temp;
  }
}

int main()
{
  setlocale(LC_ALL, "Russian");
  int n = 0;
  int i = 0;
  unsigned char* mas;
  int num = 0;
  FILE* file;
  file = fopen("C:/Users/Vadim/source/repos/labaratornaya/labaratornaya/numbers.txt", "r+");
  fscanf_s(file, "%d", &n);
  mas = (unsigned char*)malloc(n * sizeof(unsigned int));
  for (i = 1; i < n + 1; i++)
  {
    fscanf_s(file, "%u\n", &mas[i - 1]);
  }

  printf("Меню:\n");
  printf("\n");
  printf("Печать [1]\n");
  printf("Сортировка пузырьком [2]\n");
  printf("Быстрая сортировка [3]\n");
  printf("Сортировка вставкой [4]\n");
  printf("Выход [5]\n\n");
  printf("Введите номер: ");
  scanf_s("%d", &num);
  while (num != 5)
  {
    switch (num)
    {
    case 1:
      printf("\n");
      for (i = 0; i < n; i++)
      {
        printf("%u\n", mas[i]);
      }
      break;
    case 2:
      printf("\n");
      unsigned int start1 = clock();
      bSort(mas, n);
      for (i = 0; i < n; i++)
      {
        printf("%u\n", mas[i]);
      }
      unsigned int end1 = clock();
      unsigned int time1 = end1 - start1;
      printf("\nвремя работы: %u мс\n", time1);
      break;
    case 3:
      printf("\n");
      unsigned int start2 = clock();
      qSort(mas, n);
      for (i = 0; i < n; i++)
      {
        printf("%u\n", mas[i]);
      }
      unsigned int end2 = clock();
      unsigned int time2 = end2 - start2;
      printf("\n\nвремя работы: %u мс\n", time2);
      break;
    case 4:
      printf("\n");
      unsigned int start3 = clock();
      iSort(mas, n);
      for (i = 0; i < n; i++)
      {
        printf("%u\n", mas[i]);
      }
      unsigned int end3 = clock();
      unsigned int time3 = end3 - start3;
      printf("\n\nвремя работы: %u мс\n", time3);
      break;
    }
    fclose(file);
    file = fopen("C:/Users/Vadim/source/repos/labaratornaya/labaratornaya/numbers.txt", "r+");
    fscanf_s(file, "%d", &n);
    for (i = 1; i < n + 1; i++)
    {
      fscanf_s(file, "%u\n", &mas[i - 1]);
    }
    printf("Меню:\n");
    printf("\n");
    printf("Печать [1]\n");
    printf("Сортировка пузырьком [2]\n");
    printf("Быстрая сортировка [3]\n");
    printf("Сортировка вставкой [4]\n");
    printf("Выход [5]\n\n");
    printf("Введите номер: ");
    scanf_s("%d", &num);
  }
  free(mas);
  fclose(file);
  return 0;
}
