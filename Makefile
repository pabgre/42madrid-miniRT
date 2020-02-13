NAME = test
SRCS = raytracer.c 
VECTOR_SRCS = Vector/vector_utils_1.c -lm Vector/vector_utils_2.c -lm

CC = gcc
CFLAGS = -Wall -Wextra -Werror
all : $(NAME)
$(NAME): 
	gcc $(CFLAGS) $(LIBS)-o test.out $(SRCS) $(VECTOR_SRCS)

clean:
	rm test.out

run:
	./test.out