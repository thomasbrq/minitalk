SRCS	=	ft_printf.c srcs/ft_base10.c srcs/ft_hex.c srcs/ft_put.c

OBJS	=	$(SRCS:.c=.o)

GCC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror

INCLUDES = -I./includes

NAME	=	libftprintf.a

.c.o:
		@$(GCC) $(FLAGS) -c -I./ $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			@$(MAKE) -C ./libft
			@cp libft/libft.a $(NAME)
			@ar rcs $@ $^
			@echo '\033[1;35mPrintf created! 🥳';

all:		$(NAME)

clean:	
			@$(RM) $(OBJS)
			@$(MAKE) clean -C ./libft
			@echo '\033[1;37mCleaning!... 🧹';

fclean:		clean
			@$(MAKE) fclean -C ./libft
			@$(RM) $(NAME)
			@echo '\033[1;37mAll is clean!... 🧹';

re:			fclean all

.PHONY:		all clean fclean re