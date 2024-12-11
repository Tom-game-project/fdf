#ifndef VEC_H
#define VEC_H
#include <stdlib.h>

typedef struct s_2dvec t_2dvec;

typedef struct s_2dvec {
	int x;
	int y;
} t_2dvec;

void set_vec(t_2dvec *v,int x, int y);
t_2dvec *create_vec(int x, int y);
void add_vec(t_2dvec *vec_self, t_2dvec *vec_other);
void mul_int_vec(t_2dvec *vec_self, int sc);

#endif
