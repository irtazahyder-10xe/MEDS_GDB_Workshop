#include <stdio.h>
#include <stddef.h>
#include <string.h>

void print_img(size_t n, size_t m, double img[n][m])
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%5.2f ", img[i][j]);
    }
    printf("\b\n");
  }
}

double gauss_filter[3][3] = {
  {0    , 0.125 , 0},
  {0.125, 0.5   , 0.125}, 
  {0    , 0.125 , 0}
};

double conv_3x3(const double img[3][3])
{
  double conv_sum = 0;
  for (int j = 0; j < 3; j++)
    for (int i = 0; i < 3; i++)
      conv_sum += gauss_filter[i][j] * img[i][j];
  return conv_sum;
}

void apply_guass(size_t n, size_t m, double img[n][m], double new_img[n][m])
{
  double sub_arr[3][3] = {0};
  for (int j = 0; j < m; j++) {
    for(int i = 0; i < n; i++) {
      if (!i || !j) {
        new_img[i][j] = img[i][j];
        continue;
      } else if (i == n - 1 || j == m - 1) {
        new_img[i][j] = img[i][j];
        continue;
      }
      memcpy(sub_arr[0], img[i-1] + (j - 1), 3 * sizeof(double));
      memcpy(sub_arr[1], img[i]   + (j - 1), 3 * sizeof(double));
      memcpy(sub_arr[2], img[i+1] + (j - 1), 3 * sizeof(double));
      new_img[i][j] = conv_3x3(sub_arr);
    }
  }
}

int main()
{
  double img[9][9] = {
    { 20, 10, 20, 30, 40, 50, 0 , 70, 90},
    { 1 , 21, 41, 6 , 7 , 5 , 7 , 7 , 10},
    { 1 , 39, 60, 0 , 20, 5 , 8 , 0 , 21},
    { 1 , 46, 88, 60, 33, 5 , 9 , 7 , 32},
    { 1 , 5 , 20, 60, 46, 5 , 10, 7 , 43},
    { 1 , 6 , 32, 0 , 0 , 5 , 11, 0 , 54},
    { 1 , 7 , 44, 64, 32, 5 , 12, 7 , 65},
    { 1 , 8 , 56, 6 , 35, 5 , 13, 7 , 76},
    { 1 , 9 , 68, 0 , 38, 5 , 14, 7 , 87},
  };

  double new_img[9][9];
  print_img(9, 9, img);
  apply_guass(9, 9, img, new_img);
  printf("\n------------------------------------------------\n");
  print_img(9, 9, new_img);
}
