/* 
 * \file dynamic.cpp
 * \author Allison Smith 
 * \brief file that prompts the user for an integer, dynamically allocates a 1D array of doubles that size, and th en reads in that many doubles (from the keyboard), return max, min, and average 
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
 * \brief main method code to fill array with user input and return min, max, and average of values 
 * \returns an int, 0
 * \param int argc, char* argv[] 
 */

int main(int argc, char* argv[]) {
  int n; //size of array 
  printf("Enter a positive integer to set size of array.\n");
  scanf("%d", &n);
  assert(n > 0); //check to make sure array size is not less than or equal to 0

  double *d_array = (double*) malloc(n * sizeof(double));  //create 1D array of doubles with dynamic memory allocation 
  assert(d_array != NULL);  //check to make sure array pointer != NULL

  double sum = 0;
  double* temp = d_array; //temporary pointer to fill array
  //fill array using keyboard input
  for (int i = 0; i < n; i++) {
    printf("Enter a number(double)\n");
    scanf("%lf", &*temp);
    sum = sum + *temp;
    temp++;
  }
  //find min and max values of array 
  double* temp2 = d_array;
  double min = *d_array;
  double max = *d_array;
  for (int i = 0; i < n; i++) {
    if (*temp2 > max) {
      max = *temp2;
    }
    if (*temp2 < min) {
      min = *temp2;
    }
    temp2++;
  }

  float avg = (float)sum/n;

  printf ("the min is %lf, the max is %lf, and the average is %f.\n", min, max, avg);
 
  free(d_array);
  d_array = NULL;
  
  return 0;

}
  
