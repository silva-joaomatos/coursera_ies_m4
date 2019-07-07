#include "data.h"
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base) {
  
  uint8_t cnt = 0;
  int8_t sign = 1; /*1-positive 0-negative*/
  int32_t res;

  if (data == 0) {
    *ptr = '0';
    ptr++;
    *ptr = '\0';
    --ptr;
    return 1;
  }

  *ptr = '\0';
  ptr++;
  cnt++;

  if (data < 0) {
    sign = 0;
    data = -data;
  }

  while (data != 0) {
    res = data % (int32_t)base;
	if (res >9){
		*ptr = (res-10) + 'a';
	}
	else{
		*ptr = res + '0';
	}
    data /= base;
    ptr++;
    cnt++;
  }

  if (sign == 0) {
    *ptr = '-';
    ptr++;
    cnt++;
  }

  my_reverse(ptr - cnt, cnt);

  return cnt;
}

int32_t my_atoi(uint8_t * ptr,  uint8_t digits, uint32_t base) {
  int32_t result = 0;
  uint8_t i;
  int8_t sign = 1;/*1-positive 0-negative*/

  if (*ptr == '-') {
    sign = 0;
    ptr++;
    digits--;
  }

  for (i = 0; i < digits-1; ++i) {
    result = result * base + (*ptr - '0');
    ptr++;
  }
  if (sign == 1) return result;
  else return (-1*result);
}
