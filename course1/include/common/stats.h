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
 * @file stats.h	 
 * @brief Statistical information of a given array
 *
 * <Add Extended Description Here>
 *
 * @author Joao Silva
 * @date 08.07.2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief <void print_statistics(int min, int max, int mean, int median);>
 *
 * <Print computed statistics>
 *
 * @param <min> <minimum value of array>
 * @param <max> <maximum value of array>
 * @param <mean> <mean value of array>
 * @param <median> <median value of arr>
 *
 * @return <void>
 */
void print_statistics(int min, int max, int mean, int median);
/**
 * @brief <void print_array(unsigned char *test, int size)>
 *
 * <Print Array>
 *
 * @param <test> <array to be printed>
 * @param <size> <number of elements of array>

 * @return <void>
 */
void print_array(unsigned char *test, int size);
/**
 * @brief <int find_median(unsigned char *test, int size)>
 *
 * <Find median value of array>
 *
 * @param <test> <array to be printed>
 * @param <size> <number of elements of array>
 
 * @return <median>
 */
int find_median(unsigned char *test, int size);
/**
 * @brief <int find_mean(unsigned char *test, int size)>
 *
 * <Find mean value of array>
 *
 * @param <test> <array to be printed>
 * @param <size> <number of elements of array>
 
 * @return <mean>
 */
int find_mean(unsigned char *test, int size);
/**
 * @brief <int find_maximum(unsigned char *test, int size)>
 *
 * <Find maximum value of array>
 *
 * @param <test> <array to be printed>
 * @param <size> <number of elements of array>
 
 * @return <max>
 */
int find_maximum(unsigned char *test, int size);
/**
 * @brief <int find_minimum(unsigned char *test, int size)>
 *
 * <Find minimum value of array>
 *
 * @param <test> <array to be printed>
 * @param <size> <number of elements of array>
 
 * @return <min>
 */
int find_minimum(unsigned char *test, int size);
/**
 * @brief <sort_array(unsigned char test[], int size)>
 *
 * <Sort array elements in descending order>
 *
 * @param <test> <array to be printed>
 * @param <size> <number of elements of array>
 
 * @return <array sorted>
 */
void sort_array(unsigned char test[], int size);


#endif /* __STATS_H__ */
