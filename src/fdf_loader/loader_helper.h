#ifndef LOADER_HELPER_H
#define LOADER_HELPER_H


#include <stdbool.h>
#include <stdint.h>

#include "../data/u32x2.h"


// 受け付ける単語を格納するために最小限必要なサイズ,型
// "-2147483648,0x00000000" '\0'
#define Z_COLOR_WORD_MAX_LENGTH 23
typedef char t_z_color_word[Z_COLOR_WORD_MAX_LENGTH];

// 簡単な文字列の操作
bool is_space(char c);
bool is_comma(char c);
int32_t count_word(char *str, bool (*is_delimiter)(char));
bool is_hexchar(char c);
bool is_decimalchar(char c);

// 文字列から数字への変換
uint32_t get_hex_index(char c);
t_u32x2 colorcode2uint32(char *str);
int32_t str2int(char *str);

#endif
