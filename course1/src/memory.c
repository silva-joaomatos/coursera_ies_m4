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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
  uint8_t i;
  bool overlap = false;
/*Overlap exist if destination happens before the end of source*/
  if ((dst < (src + length))) {
    overlap = true;
  }
/*If there is no overlap -> direct copy*/  
  if (!overlap) {
    my_memcopy (src, dst, length);
    
  } 
/*Else copy from end to start to avoid data corruption*/
  else {
    dst = dst + length -1;
    src = src + length -1; 

    for (i=length; i>0; --i) {
      *dst = *src;
      --dst;
      --src;
    } 
  }
  return dst;
}
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t i;

  for (i=0; i<length; i++) {
    *dst = *src;
    dst++;
    src++;
  }
  
  return dst;
}
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	uint8_t i;

  for (i=0; i<length; i++) {
    *src = value;
    src++;
  }

  return src;
}
uint8_t * my_memzero(uint8_t * src, size_t length) {
  uint8_t i;
  for (i=0; i<length; i++) {
    *src = 0;
    src++;
  }
  return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length) {
  
  size_t low, high;
  uint8_t temp;

  for  (low = 0, high = length - 1; high > low; low++, high--) {
    temp = *(src + low);
    *(src + low) = *(src + high);
    *(src + high) = temp;
  }
  return src;
}

int32_t * reserve_words(size_t length) {
  
int32_t * ptr = malloc(sizeof(size_t)*length);

  if (ptr == NULL) {
#ifdef VERBOSE
    PRINTF("Failed!\n");
#endif
  }

  return ptr;
}
/**/
void free_words(uint32_t * src) {
  free(src);
}


