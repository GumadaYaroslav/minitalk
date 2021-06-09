SRCS_C :=	client.c error.c

SRCS_S := server.c 

LIBFT	= ./libft/libft.a

GCC = gcc

FLAGS = -c -Wall -Werror -Wextra

NAME = client_server

OBJS_C = $(SRCS_C:.c=.o)

OBJS_S = $(SRCS_S:.c=.o)


%.o: %.c	minitalk.h
	$(GCC) $(FLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS_C) $(OBJS_S)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(GCC) $(FLAGS) $(SRCS_C) $(SRCS_S)
	gcc -Wall -Wextra -Werror $(OBJS_C) libft.a -o client
	gcc -Wall -Wextra -Werror $(OBJS_S) libft.a -o server

server: $(OBJS_S)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(GCC) $(FLAGS) $(SRCS_S)
	gcc -Wall -Wextra -Werror $(OBJS_S) libft.a -o server

client: $(OBJS_C)
	$(MAKE) -C ./libft
	cp libft/libft.a .
	$(GCC) $(FLAGS) $(SRCS_C)
	gcc -Wall -Wextra -Werror $(OBJS_C) libft.a -o server	

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS_C) $(OBJS_S)
	rm -rf libft.a

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf server client

re: fclean all

.PHONY : all clean fclean re