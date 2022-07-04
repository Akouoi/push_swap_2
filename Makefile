NAME = push_swap 
cg="\033[0;32m
cb="\033[0;36m
cO="\033[1;33m
c=\033[0m"
CC =gcc
CFLAG = -Wall -Werror -Wextra
SRC = main.c \
	check_arg.c \
	init.c \
	moves.c \
	move_r.c \
	move_p.c \
	move_s.c \
	print.c \
	sort_bubble.c \
	sort_quick.c \
	sort_two_three.c \
	sort_test.c \
	math.c \
	math_2.c

OBJ= $(SRC:.c=.o)

all: $(NAME) clean
$(NAME): $(OBJ)
	$(CC) $(OBJ) -L libft/. -lft -g -o $(NAME)
	@echo $(cO)           __ __			$(c)
	@echo $(cO)         ,;::\::\		$(c)
	@echo $(cO)       ,^ / ^ /^/		$(c)
	@echo $(cO)   _\,: ^.,-^.-^:.		$(c)
	@echo $(cO)  -./^   :    :  :\,		$(c)
	@echo $(cO)   ::.  ,:____;__; :-	$(c)
	@echo $(cO)   :   (  .^*^o*^, );	$(c)
	@echo $(cO)    \..  - ^--^-^ /		$(c)
	@echo $(cO)     -:._..-   _.^		$(c)
	@echo $(cO)     ,;  .     -.		$(c)
	@echo $(cO)    / ^| |       \		$(c)
	@echo $(cO)   ::. J :        :		$(c)
	@echo $(cO)   |   C  \       |		$(c)
	@echo $(cO)   :. C_, :       ;		$(c)
	@echo $(cO)    \^/^_/       /		$(c)
	@echo $(cO)     -...   , _,^		$(c)
	@echo $(cO)      |,|  : |		 	$(c)
	@echo $(cO)      |-|  | |			$(c)
	@echo $(cO)      |,|  | |			$(c)
	@echo $(cO)  ,--.;-|  | ^..--.		$(c)
	@echo $(cO) /;^  ^ ;  ^..--. JJ		$(c)
	@echo $(cO) \:.___(___   ) JJ^		$(c)
	@echo $(cg)MAKE PUSH_SWAP OK		$(c)

%.o : %.c
	$(MAKE) -s all -C libft
	$(CC) $(CFLAG) -c $^
clean:
	$(MAKE) -s fclean -C libft
	rm -f $(OBJ)
	@echo $(cb)MAKE CLEAN$(c)

fclean: clean
	rm -f $(NAME)
	@echo $(cb)MAKE FCLEAN$(c)

re: fclean all

.PHONY: all build bonus clean fclean re

.SILENT:
