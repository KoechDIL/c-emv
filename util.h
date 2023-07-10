//
// Created by koech on 7/6/2023.
//

#ifndef C_EMV_UTIL_H
#define C_EMV_UTIL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned char* hex_int(int val, size_t* length);
int from_hex_int(unsigned char* val, size_t length);
void from_hex_date(unsigned char* val, size_t length, char* result);
int decode_int(unsigned char* val, size_t length);
void format_bytes(unsigned char* data, size_t length, char* result);
void unformat_bytes(char* data, unsigned char* result, size_t* length);
int bit_set(int value, int bit);

#endif //C_EMV_UTIL_H
