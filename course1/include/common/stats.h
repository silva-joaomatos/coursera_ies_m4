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
 * @date 02.06.2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 
void print_statistics(int min, int max, int mean, int median);
void print_array(unsigned char *test, int size);
int find_median(unsigned char *test, int size);
int find_mean(unsigned char *test, int size);
int find_maximum(unsigned char *test, int size);
int find_minimum(unsigned char *test, int size);
void sort_array(unsigned char test[], int size);
/**
 * @brief <Add Brief Description of Function Here>
 *
 * <Add Extended Description Here>
 *
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 * @param <Add InputName> <add description here>
 *
 * @return <Add Return Informaiton here>
 */


#endif /* __STATS_H__ */
