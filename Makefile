# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ifran <ifran@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 13:28:03 by ifran             #+#    #+#              #
#    Updated: 2019/10/11 18:07:38 by ifran            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALL_EX =    ft_printf.c case_of_error.c func_arr.c pf_u.c pf_hex.c pf_bhex.c pf_oct.c \
            pf_flags.c pf_width.c pf_precision.c pf_modifier.c pf_type.c initialize.c \
            re_initialize.c pf_itoa.c print_precision.c pf_flag_diez.c pf_flag_zero.c \
            pf_flags_plus_and_space.c pf_flag_minus.c pf_no_flags.c pf_putvalue.c

SRCDIR = srcs/
OBJDIR = objs/

SRCS = $(addprefix $(SRCDIR), $(ALL_EX))

ALL_OBJ = $(ALL_EX:%.c=%.o)

OBJS = $(addprefix $(OBJDIR), $(ALL_OBJ))

NAME = libftprintf.a

INCLUDES = ./includes/ft_printf.h ./libft/includes/libft.h

COMP_LIB = make -C libft/

FLAGS = -Wall -Wextra -Werror

all: lib $(NAME)

$(NAME): lib $(OBJS)
	@/bin/cp ./libft/libft.a $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDES)
	@/bin/mkdir -p $(OBJDIR)
	@gcc $(FLAGS) -I./includes -I./libft/includes -c $< -o $@

lib:
	@$(COMP_LIB)

clean:
	@/bin/rm -rf $(OBJDIR)
	@$(COMP_LIB) clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@$(COMP_LIB) fclean

re: fclean all

.PHONY: lib clean fclean all re
