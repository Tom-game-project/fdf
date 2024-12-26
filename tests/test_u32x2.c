#include "../src/data/i32u32.h"
#include "../src/data/u32x2.h"
#include "../src/data/i32x2.h"
#include "../src/data/u8x4.h"
#include "../src/data/u16x4.h"
#include "../src/data/vec2d_64.h"
#include "../src/data/print_data.h"

// fdf loader
#include "../src/fdf_loader/loader.h"

// draw
//

#include "../src/draw/draw.h"

#include <stdint.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define TESTLENGTH 13

// 文字色
#define REDSTR "\x1b[31m"
#define GREENSTR "\x1b[32m"
#define CYANSTR "\x1b[34m"
#define RESETSTR "\x1b[39m"

#define MAPFILELENGTH 21
char *map_files[MAPFILELENGTH] = 
{
	 "maps/test_maps/10-2.fdf"
	,"maps/test_maps/20-60.fdf"
	,"maps/test_maps/50-4.fdf"
	,"maps/test_maps/basictest.fdf"
	,"maps/test_maps/elem-fract.fdf"
	,"maps/test_maps/elem2.fdf"
	,"maps/test_maps/mars.fdf"
	,"maps/test_maps/plat.fdf"
	,"maps/test_maps/pylone.fdf"
	,"maps/test_maps/pyramide.fdf"
	,"maps/test_maps/t2.fdf "
	,"maps/test_maps/10-70.fdf"
	,"maps/test_maps/42.fdf"
	,"maps/test_maps/100-6.fdf"
	,"maps/test_maps/elem-col.fdf"
	,"maps/test_maps/elem.fdf"
	,"maps/test_maps/julia.fdf"
	,"maps/test_maps/pentenegpos.fdf"
	,"maps/test_maps/pnp_flat.fdf"
	,"maps/test_maps/pyra.fdf"
	,"maps/test_maps/t1.fdf"
};


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
	free(a);
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

	if (t_u32x2_add(a, b) != encode_u32x2(7, 10)) return (1);
	if (t_u32x2_sub(b, a) != encode_u32x2(3, 4)) return (1);
	if (t_u32x2_mul(a, b) != encode_u32x2(10, 21)) return (1);
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

	if (t_i32x2_add(a, b) != encode_i32x2(3, -4)) return (1);
	if (t_i32x2_sub(a, b) != encode_i32x2(-7, 10)) return (1);
	if (t_i32x2_mul(a, b) != encode_i32x2(-10, -21)) return (1);
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
	free(a);
	return (0);
}



static bool is_space(char c)
{
	return (c == ' ');
}

static bool is_comma(char c)
{
	return (c == ',');
}

int test07()
{
	printf(
			CYANSTR
			"単語数カウンターのテスト\n"
			RESETSTR
	);
	char *testcase00 = "hello world";
	char *testcase01 = "hello world     ";
	char *testcase02 = " hello  world     ";
	char *testcase03 = "  s  hello world    ";
	char *testcase04 = "     ";
	char *testcase05 = "0,0xff";
	char *testcase06 = "123";


	if (count_word(testcase00, is_space) != 2) return (1);
	if (count_word(testcase01, is_space) != 2) return (1);
	if (count_word(testcase02, is_space) != 2) return (1);
	if (count_word(testcase03, is_space) != 3) return (1);
	if (count_word(testcase04, is_space) != 0) return (1);
	if (count_word(testcase05, is_comma) != 2) return (1);
	if (count_word(testcase06, is_comma) != 1) return (1);
	return (0);
}


int test08()
{
	printf(
			CYANSTR
			"gnlのテスト＆動作確認\n"
			RESETSTR
	);
	//load_map("./maps/test_maps/42.fdf");
	printf("\n--- --- --- ---\n");
	//load_map("./maps/test_maps/10-2.fdf");
	return (0);
}


int test09()
{
	t_i32x2 map_size;
	printf(
			CYANSTR
			"get_mapsizeの確認\n"
			RESETSTR
	);
	map_size = get_mapsize("./maps/test_maps/42.fdf");
	printf("width, height = %d, %d\n", decode_int_x(map_size), decode_int_y(map_size));
	map_size = get_mapsize("./maps/test_maps/10-2.fdf");
	printf("width, height = %d, %d\n", decode_int_x(map_size), decode_int_y(map_size));
	map_size = get_mapsize("./maps/test_maps/10-70.fdf");
	printf("width, height = %d, %d\n", decode_int_x(map_size), decode_int_y(map_size));
	map_size = get_mapsize("./maps/test_maps/100-6.fdf");
	printf("width, height = %d, %d\n", decode_int_x(map_size), decode_int_y(map_size));
	map_size = get_mapsize("./maps/test_maps/20-60.fdf");
	printf("width, height = %d, %d\n", decode_int_x(map_size), decode_int_y(map_size));
	return (0);
}


int test10()
{
	printf(
			CYANSTR
			"カラーコードを整数データに変換する\n"
			RESETSTR
	);
	char str[111] = "0x00ff00ff\0";
	t_u32x2 a = colorcode2uint32(str);
	printf("%d %d\n", decode_uint_x(a) , decode_uint_y(a));
	return (0);
}


int test11()
{
	printf(
			CYANSTR
			"zとカラーコードのセットの情報を読み込めるかどうかを確かめる\n"
			RESETSTR
	);
	char str[32] = "-1234,0xffee";
	char str01[32] = "10";
	t_i32u32 a = z_color2t_i32u32(str);

	printf(
		"%d %d\n",
		decode_iu_x(a),
		decode_iu_y(a)
	);

	a = z_color2t_i32u32(str01);

	printf(
		"%d %d\n",
		decode_iu_x(a),
		decode_iu_y(a)
	);
	return (0);
}


int test12 ()
{
	printf(
			CYANSTR
			"読み込んだデータを整形して表示する\n"
			RESETSTR
	);
	vec2d_64 arr;

	arr = NULL;
	alocate_memory_for_map(&arr, "./maps/test_maps/42.fdf");
	printf("pointer %p\n", arr);
	printf("%d %d\n" ,decode_uint_y(get_shape(arr)), decode_uint_x(get_shape(arr)));

	print_vec2d_elem_i32u64(arr);
	free(arr);
	return (0);
}


int test13()
{
	printf(
		CYANSTR
		"色々なファイルに形式に対応させられているかテスト"
		RESETSTR
	);
	vec2d_64 arr;
	enum e_result err_code;

	for (int i = 0; i < MAPFILELENGTH; i++)
	{

		arr = NULL;
		printf("file name:%s\n", map_files[i]);
		err_code = alocate_memory_for_map(&arr, map_files[i]);
		printf("pointer %p\n", arr);

		if (err_code == e_result_ok)
		{
			printf("%d %d\n" ,decode_uint_y(get_shape(arr)), decode_uint_x(get_shape(arr)));
			print_vec2d_elem_i32u64(arr);
		}
		else
		{
			printf("some error occured in alocate_memory_for_map\n");
		}
		free(arr);
	}
	return (0);
}

int test14()
{
	printf(
		CYANSTR
		"スクリーン座標変換テスト\n"
		RESETSTR
	);
	vec2d_64 a;
	vec2d_64 map;

	alocate_memory_for_map(&map, "maps/test_maps/42.fdf");
	a = calc_map(map);
	print_vec2d_elem_i32x2(a);
	free(a);
	free(map);
	return (0);
}


int test15()
{
	t_u8x4 a;
	t_u8x4 b;
	t_u8x4 c;

	a = encode_u8x4(1,2,3,4);
	b = encode_u8x4(1,2,3,4);
	c = encode_u8x4(4,3,2,1);
	print_u8x4(a);
	a = t_u8x4_add(
		a,
		t_u8x4_mul(b, c)
	);
	print_u8x4(a);
	return (0);
}

int test16()
{
	t_u16x4 a;
	t_u16x4 b;
	t_u16x4 c;
	t_u8x4 a8;

	a = encode_u16x4(1,2,3,4);
	b = encode_u16x4(1,2,3,4);
	c = encode_u16x4(4,3,2,1);
	print_u16x4(a);
	a = t_u16x4_add(
		a,
		t_u16x4_mul(b, c)
	);
	print_u16x4(a);
	a = t_u16x4_mul(a, encode_u16x4(
				256,
				256,
				256,
				256));
	a8 = conv_u16x4_to_u8x4(a);
	print_u8x4(a8);
	printf("hex: %x\n", a8);
	return (0);
}

int test17()
{
	t_u8x4 a;

	//a = encode_u8x4(1,2,3,4);
	a = 0xffffff;
	print_u8x4(a);
	return (0);
}

/*
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
		test08,
		test09,
		test10,
		test11,
		test13,
	};
	int code = 0;

	for (int i = 0; i < TESTLENGTH; i++)
	{
		printf("=========== start test %d ===========\n", i);
		if (test[i]())
		{
			printf(
				REDSTR
				"^^^^^^^^^^^ test %d done  ^^^^^^^^^^^\n"
				RESETSTR
				, i
			);
			code = 1;
		}
		else
			printf(
				GREENSTR
				"^^^^^^^^^^^ test %d done  ^^^^^^^^^^^\n"
				RESETSTR
				, i
			);
	}
	return (code);
}
*/

int main()
{
	return test17();
}
