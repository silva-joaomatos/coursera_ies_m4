/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c	 
 * @brief Statistical information of a given array
 *
 * <Add Extended Description Here>
 *
 * @author Joao Silva
 * @date 02.06.2019
 *
 */
#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  int min =0;int max =0; int mean=0; int median=0;
  /* Statistics and Printing Functions Go Here */
	print_array(test, SIZE); //print unsorted
	sort_array(test, SIZE); 
	print_array(test, SIZE); //print sorted for debug
	mean= find_mean(test, SIZE);
	median=find_median(test, SIZE);
	max=find_maximum(test, SIZE);
	min=find_minimum(test, SIZE);
	print_statistics(min,max,mean,median);
}

/* Add other Implementation File Code Here */
void print_statistics(int min, int max, int mean, int median){
	printf("Minimum=%d\n", min);
	printf("Maximum=%d\n", max);
	printf("Mean=%d\n", mean);
	printf("Median=%d\n",median);
}
void print_array(unsigned char *test, int size){
	int i=0;
	for(i;i<size;i++) {
		printf("test[%d]=%d\n",i,test[i]);
	}
}
void sort_array(unsigned char test[], int size){
	int i=0; int j=0; unsigned char tmp=0; 
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			if (test[j] > test[i]) {
				tmp = test[i];         
				test[i] = test[j];           
				test[j] = tmp;
			}		 
		}
	}
}
int find_median(unsigned char *sorted, int size){
	if (size%2 == 1) 
		return sorted[(size/2)];
	else{
		return (sorted[size/2 -1] + sorted[size/2])/2;
	}	
}
int find_mean(unsigned char *test, int size){
	int i=0;int sum=0;
	for(i; i<size; i++){
		sum+=test[i];
	}
	return (sum/size);
}
int find_maximum(unsigned char *test, int size){
	  int i=0; int max=0;
	  max = test[0];
	  for (i = 1; i < size; i++){
		if (test[i] > max){
			max  = test[i];
		}
	}
	return max;
}
int find_minimum(unsigned char *test, int size){
	int i=0; int min=0;
	  min= test[0];
	  for (i = 1; i < size; i++){	
		if (test[i] < min){
			min  = test[i];
		}
	}
	return min;
}

