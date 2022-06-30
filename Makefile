NAME = push_swap 
cgre="\033[0;32m
cblu="\033[0;36m
cora="\033[1;33m
c=\033[0m"
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = main.c \
	check_arg.c \
	init.c \
	moves.c \
	move_r.c \
	move_p.c \
	move_s.c \
	print.c \
	refresh.c \
	sort_bubble.c \
	sort_quick.c \
	sort_two_three.c \
	sort_test.c \
	math.c

OBJ= $(SRC:.c=.o)

all: $(NAME) clean
$(NAME): $(OBJ)
	$(CC) $(OBJ) -L libft/. -lft -g -o $(NAME)
	@echo $(cora)     ____     ____ 	$(c)
	@echo $(cora)    '===\ \ / /===' 		$(c)
	@echo $(cora)    ,\\\\\ | /////, 		$(c)
	@echo $(cora) __  \ .--. .--. /  __	    $(c)
	@echo $(cora)___\/ '    |    ' \/___	$(c)
	@echo $(cora)-- _, !    |    ! ,_ --	$(c)
	@echo $(cora)   / '!    |    !' \ 	    $(c)
	@echo $(cora)  /'/ !    |    ! \'\  	$(c)
	@echo $(cora) 1= ! \   0|0   / ! =1 	$(c)
	@echo $(cora) != \   --; ;--   / =!		$(c)
	@echo $(cora)     \    ,-,    /     	$(c)
	@echo $(cora)  \ 0  --~   ~--  0 / 	    $(c)
	@echo $(cora)   \ -___________- /		$(c)
	@echo $(cora)       MAKE DONE$(c)

%.o : %.c
	$(MAKE) -s all -C libft
	$(CC) $(CFLAG) -c $^
clean:
	$(MAKE) -s fclean -C libft
	rm -f $(OBJ)
	@echo $(cblu)MAKE CLEAN$(c)

fclean: clean
	rm -f $(NAME)
	@echo $(cblu)MAKE FCLEAN$(c)

re: fclean all

.PHONY: all build bonus clean fclean re

.SILENT:
