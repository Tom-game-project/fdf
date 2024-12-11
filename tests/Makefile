# それぞれの関数が期待通りに動作するかをテストします

FLAGS=-Wextra -Werror -Wall -g
SRC=\
     vec_test.c\
     ../src/vec/2dvec.c
OBJ=$(SRC:.c=.o)

MAIN_TARGET=test_tmp

all:$(MAIN_TARGET)

$(MAIN_TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

test: all
	./test_tmp

clean:
	rm -rf $(MAIN_TARGET)

.PHONY:	test
