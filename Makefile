#  ************************************************************************** #
#                                                           LE - /            #
#                                                               /             #
#    Makefile                                         .::    .:/ .      .::   #
#                                                  +:+:+   +:    +:  +:+:+    #
#    By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     #
#                                                  #+#   #+    #+    #+#      #
#    Created: 2018/08/26 10:41:53 by asiaux       #+#   ##    ##    #+#       #
#    Updated: 2018/08/26 10:41:53 by asiaux      ###    #+. /#+    ###.fr     #
#                                                          /                  #
#                                                         /                   #
#  ************************************************************************** #

.PHONY = all clean fclean re

# **************************************************************************** #
#																			   #																		   #
#									DIRECTORIES		    					   #
#																			   #																			 #
# **************************************************************************** #

SRCDIR = ./src/
OBJDIR = ./obj/
HEADERDIR = ./includes/
LIBFTDIR = ./libft/

# **************************************************************************** #
#																			   #
#		           			    	FILES		    						   #
#																			   #
# **************************************************************************** #

NAME = asiaux.filler
CC = gcc
CFLAGS = -Werror -Wall -Wextra
HEADERS = $(addprefix $(HEADERDIR), filler.h define.h)

FILESFILLER = 	main.c ft_parser ft_points ft_put_token

SRCPFILLER = $(addprefix $(SRCDIR), $(addsuffix .c, $(FILESFILLER)))
OBJFILLER = $(addprefix $(OBJDIR), $(addsuffix .o, $(FILESFILLER)))

SRCS = $(SRCFILLER)
OBJS = $(OBJFILLER)

# **************************************************************************** #
#																			   #
#									COMMANDS								   #
#																			   #
# **************************************************************************** #

all : $(NAME)

$(NAME): $(OBJALL) $(OBJS)
#	@printf "Compiling $(NAME)..."
	@$gcc -o asiaux.filler objs/*.o libft/libft.a
#	@printf "\033[32m[OK]\033[0m\n"

$(OBJALL):
	@mkdir $@

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADERS)
#	@printf "%b" "Compiling $< in $@..."
	@$(CC) $(CFLAGS) -o $@ -c $< -I $(HEADERDIR)
#	@printf "\033[32m[OK]\033[0m\n"

libft:
    @make -C libft/

test:
	@gcc main.c libftprintf.a
	@./a.out

clean:
			@rm -rf $(OBJDIR)
			@make clean -C libft/

fclean: clean
			@rm -f $(NAME)
			@make fclean -C libft/

re: fclean all