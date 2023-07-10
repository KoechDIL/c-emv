//
// Created by koech on 7/6/2023.
//

#include "util.h"

unsigned char* hex_int(int val, size_t* length) {
    char s[16];
    snprintf(s, sizeof(s), "%d", val);
    if (*length % 2 != 0) {
        char* padded = malloc((*length + 1) * sizeof(char));
        padded[0] = '0';
        strncpy(padded + 1, s, *length);
        s[*length + 1] = '\0';
        *length += 1;
        return hex_int(atoi(padded), length);
    }
    unsigned char* result = malloc((*length / 2) * sizeof(unsigned char));
    for (size_t i = 0; i < *length; i += 2) {
        char hex[3] = {s[i], s[i + 1], '\0'};
        result[i / 2] = strtol(hex, NULL, 16);
    }
    return result;
}

int from_hex_int(unsigned char* val, size_t length) {
    char* hex = malloc((length * 2 + 1) * sizeof(char));
    for (size_t i = 0; i < length; i++) {
        snprintf(hex + (i * 2), 3, "%02X", val[i]);
    }
    int result = strtol(hex, NULL, 16);
    free(hex);
    return result;
}

void from_hex_date(unsigned char* val, size_t length, char* result) {
    snprintf(result, 9, "%02X/%02X/%02X", val[0], val[1], val[2]);
}

int decode_int(unsigned char* val, size_t length) {
    int result = val[0];
    for (size_t i = 1; i < length; i++) {
        result = (result << 8) | val[i];
    }
    return result;
}

void format_bytes(unsigned char* data, size_t length, char* result) {
    if (length == 1) {
        snprintf(result, 5, "[%02X]", data[0]);
    } else {
        int offset = 0;
        for (size_t i = 0; i < length; i++) {
            offset += snprintf(result + offset, 4, "%02X ", data[i]);
        }
        result[offset - 1] = '\0';  // Replace the trailing space with a null character
        snprintf(result + offset - 1, 2, "]");
    }
}

void unformat_bytes(char* data, unsigned char* result, size_t* length) {
    char* token = strtok(data, " :");
    size_t i = 0;
    while (token != NULL) {
        result[i] = strtol(token, NULL, 16);
        token = strtok(NULL, " :");
        i++;
    }
    *length = i;
}

int bit_set(int value, int bit) {
    int mask = 1 << bit;
    return (value & mask) == mask;
}