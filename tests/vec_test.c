#include "../include/vec.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define TEST_CASE_SIZE 2

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define RESET "\x1b[39m"

/// テストのための関数
/// ベクトルの内容を表示する
void show_vec(t_2dvec *v)
{
	printf("vec(%d, %d)\n",v->x, v->y);
}

/*
 * test関数
 * テストの結果が正しければtrueを
 * そうでなければfalseを返却する
 *
*/

/// #[test]
/// テスト結果が正しい場合
bool test00()
{
	// for test 
	int f0;
	int f1;

	t_2dvec *a;
	t_2dvec *b;

	a = (t_2dvec*) malloc(sizeof(t_2dvec));
	if (a == NULL)
		return (1);
	b = (t_2dvec*) malloc(sizeof(t_2dvec));
	if (b == NULL)
	{
		free(a);
		return (1);
	}
	set_vec(a, 1, 2);
	set_vec(b ,3, 4);
	add_vec(a, b);
	f0 = a->x == 4;
	f1 = a->y == 6;
	// drop
	free(a);
	free(b);
	return (f0 && f1);
}

/// #[test]
/// テスト結果が正しい場合
/// vec_showが正しく表示できるかどうか
/// create_vecが正しく初期化、vecの生成をできるかどうか
bool test01()
{
	// for test 
	int f0;
	int f1;

	t_2dvec *a;
	t_2dvec *b;

	a = create_vec(1, 2);
	b = create_vec(3, 4);
	if (a == NULL || b == NULL)
		return (true); // もし領域を確保できなかったら
	show_vec(a);
	show_vec(b);
	add_vec(a, b);
	f0 = a->x == 4;
	f1 = a->y == 6;
	show_vec(a);
	show_vec(b);
	// drop
	free(a);
	free(b);
	return (f0 && f1);
}


/// entry point
int main(int argc, char *argv[]){
	bool (*test[TEST_CASE_SIZE])() = {
		test00,
		test01
	};

	for (int i = 0; i < TEST_CASE_SIZE; i++){
		if (test[i]())
			printf("%stest%dが成功しました%s\n",GREEN, i, RESET);
		else
			printf("%stest%dが失敗しました%s\n",RED, i, RESET);
	}
	return (0);
}
