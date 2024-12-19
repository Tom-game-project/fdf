#include "../src/data/i32u32.h"
#include "../src/data/u32x2.h"
#include "../src/data/i32x2.h"
#include "../src/data/vec2d_64.h"

// fdf loader
#include "../src/fdf_loader/loader.h"

#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define TESTLENGTH 8

// 文字色
#define REDSTR "\x1b[31m"
#define GREENSTR "\x1b[32m"
#define CYANSTR "\x1b[34m"
#define RESETSTR "\x1b[39m"

// 表示のための関数郡
int print_u32x2(t_u32x2 data)
{
	return printf("(%u, %u) ", decode_uint_x(data) ,decode_uint_y(data));
}

int print_i32x2(t_i32x2 data)
{
	return printf("(%d, %d) ", decode_int_x(data) ,decode_int_y(data));
}

int print_i32u32(t_i32u32 data)
{
	return printf("(%d, %u) ", decode_iu_x(data), decode_iu_y(data));
}

// #[test]
int test00()
{
	// DOC
	printf(
			CYANSTR
			"正しくencodeされているかどうかを確かめるテスト\n"
			"SIMD的な動作についても確認\n"
			RESETSTR
	);

	t_u32x2 u_a = encode_u32x2(10, 20);
	t_u32x2 u_b = encode_u32x2(30, 40);
	t_u32x2 u_c;

	printf("u_a(%u, %u)\n", decode_uint_x(u_a), decode_uint_y(u_a));
	printf("u_b(%u, %u)\n", decode_uint_x(u_b), decode_uint_y(u_b));

	u_c = u_b - u_a;
	printf("u_c(%u, %u) = b - a\n", decode_uint_x(u_c), decode_uint_y(u_c));

	u_c = u_a + u_b;
	printf("u_c(%u, %u) = a + b\n", decode_uint_x(u_c), decode_uint_y(u_c));

	u_c = u_a * 3;
	printf("u_c(%u, %u) = a * 3\n", decode_uint_x(u_c), decode_uint_y(u_c));

	t_u32x2 u_l = encode_u32x2(UINT_MAX, 0);
	t_u32x2 u_ll = encode_u32x2(0, UINT_MAX);
	printf("u_l(%u, %u)\n", decode_uint_x(u_l), decode_uint_y(u_l));
	printf("u_ll(%u, %u)\n", decode_uint_x(u_ll), decode_uint_y(u_ll));

	t_i32x2 i_a = encode_i32x2(0, -20);
	t_i32x2 i_b = encode_i32x2(-12, -42);
	t_i32x2 i_c;

	printf("i_a(%d, %d)\n", decode_int_x(i_a), decode_int_y(i_a));
	printf("i_b(%d, %d)\n", decode_int_x(i_b), decode_int_y(i_b));
	// 期待通りに動かない例
	i_c = i_a + i_b;
	printf("i_c(%d, %d) = i_a + i_b\n", decode_int_x(i_c), decode_int_y(i_c));

	i_c = i_a - i_b;
	printf("i_c(%d, %d) = i_a - i_b\n", decode_int_x(i_c), decode_int_y(i_c));

	i_c = i_a * -3;
	printf("i_c(%d, %d) = i_a * -3\n", decode_int_x(i_c), decode_int_y(i_c));

	return (0);
}


// #[test]
int test01()
{
	uint8_t width = 10;
	uint8_t height = 10;

	printf(
			CYANSTR
			"vec2d_64の動作をチェック\n"
			RESETSTR
	);
	t_64_elem r;
	vec2d_64 a = init_vec2d_64(width, height);
	for (uint32_t y = 0; y < height;y++)
	{
		for (uint32_t x = 0; x < width;x++)
		{
			r.u32x2 = encode_u32x2(x, y);
			set_vec2d_elem(a, x, y, r);
		}
	}
	t_64_elem tmp;
	for (uint32_t y = 0; y < height;y++)
	{
		for (uint32_t x = 0; x < width;x++)
		{
			tmp = get_vec2d_elem(a, x, y);
			print_i32x2(tmp.i32x2);
			// printf("(%d %d) ", decode_uint_x(tmp.u32x2), decode_uint_y(tmp.u32x2));
		}
		printf("\n");
	}
	return (0);
}

// #[test]
int test02()
{
	printf(
			CYANSTR
			"t_u32x2の演算の動作チェック\n"
			RESETSTR
	);
	t_u32x2 a = encode_u32x2(2, 3);
	t_u32x2 b = encode_u32x2(5, 7);

	if (t_u32x2_add(a, b) != encode_u32x2(7, 10)) // assert
		return (1);
	if (t_u32x2_sub(b, a) != encode_u32x2(3, 4)) // assert
		return (1);
	if (t_u32x2_mul(a, b) != encode_u32x2(10, 21)) //assert
		return (1);
	return (0);
}

// #[test]
int test03()
{
	printf(
			CYANSTR
			"t_i32x2の演算の動作チェック\n"
			RESETSTR
	);
	t_i32x2 a = encode_i32x2(-2, 3);
	t_i32x2 b = encode_i32x2(5, -7);

	if (t_i32x2_add(a, b) != encode_i32x2(3, -4)) // assert
		return (1);
	if (t_i32x2_sub(a, b) != encode_i32x2(-7, 10)) // assert
		return (1);
	if (t_i32x2_mul(a, b) != encode_i32x2(-10, -21)) // assert
		return (1);
	return (0);
}

int test04()
{
	printf(
			CYANSTR
			"t_64_elemnのサイズ確認\n"
			RESETSTR
	);
	printf("sizeof t_64_elem union: %lu bit\n", sizeof(t_64_elem) * 8);
	return (0);
}

int test05()
{
	printf(
			CYANSTR
			"t_i32u32の演算の動作チェック\n"
			RESETSTR
	);
	t_i32u32 a = encode_i32u32(-10, 0xFFFFFFFF);
	t_i32u32 b = encode_i32u32(42, 0);

	print_i32u32(a);
	print_i32u32(b);
	printf("\n");

	return (0);
}

int test06()
{
	uint8_t width = 10;
	uint8_t height = 10;

	printf(
			CYANSTR
			"vec2d_64(t_i32u32)の動作をチェック\n"
			RESETSTR
	);
	t_64_elem r;
	vec2d_64 a = init_vec2d_64(width, height);
	for (uint32_t y = 0; y < height;y++)
	{
		for (uint32_t x = 0; x < width;x++)
		{
			r.i32u32 = encode_i32u32(0 - x, 0xFFFFFFFF);
			set_vec2d_elem(a, x, y, r);
		}
	}
	t_64_elem tmp;
	for (uint32_t y = 0; y < height;y++)
	{
		for (uint32_t x = 0; x < width;x++)
		{
			tmp = get_vec2d_elem(a, x, y);
			print_i32u32(tmp.i32u32);
		}
		printf("\n");
	}
	return (0);
}



static bool is_space(char c)
{
	return (c == ' ');
}

int test07()
{
	char *testcase00 = "hello world";
	char *testcase01 = "hello world     ";
	char *testcase02 = " hello  world     ";
	char *testcase03 = "  s  hello world    ";
	char *testcase04 = "     ";


	if (count_word(testcase00, is_space) != 2)
		return (1);
	if (count_word(testcase01, is_space) != 2)
		return (1);
	if (count_word(testcase02, is_space) != 2)
		return (1);
	if (count_word(testcase03, is_space) != 3)
		return (1);
	if (count_word(testcase04, is_space) != 0)
		return (1);
	return (0);
}

int main()
{
	int (*test[TESTLENGTH])() = {
		test00,
		test01,
		test02,
		test03,
		test04,
		test05,
		test06,
		test07,
	};
	for (int i = 0; i < TESTLENGTH; i++)
	{
		printf("=========== start test %d ===========\n", i);
		if (test[i]())
			printf(
				REDSTR
				"^^^^^^^^^^^ test %d done  ^^^^^^^^^^^\n"
				RESETSTR
				, i
			);
		else
			printf(
				GREENSTR
				"^^^^^^^^^^^ test %d done  ^^^^^^^^^^^\n"
				RESETSTR
				, i
			);
	}
	return (0);
}
