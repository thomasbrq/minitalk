SRCS_CLIENT	= 	srcs/client.c
OBJS_CLIENT	=	$(SRCS_CLIENT:.c=.o)

SRCS_SERVER	= 	srcs/server.c
OBJS_SERVER	=	$(SRCS_SERVER:.c=.o)

GCC			=	gcc

RM			=	rm -f

FLAGS		=	-Wall -Wextra -Werror

NAME_CLIENT	= client
NAME	= server

PRINTF		=  libftprintf.a

.c.o:
		@$(GCC) $(FLAGS) -c -I./includes $< -o ${<:.c=.o}

$(NAME):	$(OBJS_SERVER) $(OBJS_CLIENT)
				@$(MAKE) -C ./printf
				@cp printf/libftprintf.a .
				@$(GCC) $(FLAGS) $(OBJS_SERVER) $(PRINTF) -o $(NAME)
				@echo '\033[1;35mServer created! 🥳';
				@$(GCC) $(FLAGS) $(OBJS_CLIENT) $(PRINTF) -o $(NAME_CLIENT)
				@echo '\033[1;35mClient created! 🥳';

all:		$(NAME)

clean:
			@$(RM) $(OBJS_SERVER)
			@$(RM) $(OBJS_CLIENT)
			@$(MAKE) clean -C ./printf

fclean:		clean
			@$(RM) $(NAME_CLIENT) $(NAME)
			@$(RM) $(PRINTF)
			@$(MAKE) fclean -C ./printf

re:			fclean all

.PHONY:		all clean fclean re
