#include "../../include/vec.h"

/// 
void set_vec(t_2dvec *v,int x, int y)
{
	v->x = x;
	v->y = y;
}

/// if this function return NULL
/// allocation failed
t_2dvec *create_vec(int x, int y)
{
	t_2dvec *a;

	a = (t_2dvec *) malloc(sizeof(t_2dvec));
	if (a == NULL)
		return (NULL);
	set_vec(a, x, y);
	return (a);
}

/// selfにotherを足す
void add_vec(t_2dvec *vec_self, t_2dvec *vec_other)
{
	vec_self->x = vec_self->x + vec_other->x;
	vec_self->y = vec_self->y + vec_other->y;
}

/// selfにscを掛ける
void mul_int_vec(t_2dvec *vec_self, int sc)
{
	vec_self->x = vec_self->x * sc;
	vec_self->y = vec_self->y * sc;
}
