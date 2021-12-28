#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> 

int main()
{
  setlocale(LC_ALL, "Russian");
  int i = 0, n = 0, min = 0, max = 0;
  unsigned char* mas;
  printf("Введите количество элементов ");
  scanf_s("%d", &n);
  printf("Введите минимальное значение от 1 до 255 ");
  scanf_s("%d", &min);
  printf("Введите максимальное значение от 1 до 255 ");
  scanf_s("%d", &max);
  printf("\n");

  if ((max <= min) || (max > 255) || (min > 255) || (min <= 0) || (n <= 0) || (max <= 0))
  {
    printf("Введено неверное значение\n");
    return 0;
  }

  mas = (unsigned char*)malloc(n * sizeof(unsigned char));

  for (i = 0; i < n; i++)
  {
    mas[i] = (((((double)rand()) / RAND_MAX) * (max - min)) + min);
  }


  FILE* file;
  file = fopen("numbers.txt", "w+");

  fprintf(file, "%d\n", n);

  for (i = 0; i < n; i++)
  {
    fprintf(file, "%d\n", mas[i]);
  }

  printf("числа успешно сгенерированы\n ");

  free(mas);
  fclose(file);
  return 0;
}
