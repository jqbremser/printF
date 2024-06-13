# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbremser <jbremser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/30 09:53:52 by jbremser          #+#    #+#              #
#    Updated: 2024/06/13 12:04:50 by jbremser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

FILES = ft_printf.c 

CFLAGS = -Wall -Werror -Wextra

PF_H	= 	ft_printf.h
SRCDIR =	srcs
OBJDIR =	objs

LIBFT_DIR =	./libft
LIBFT =		$(LIBFT_DIR)/libft.a

SRCS =		$(addprefix $(SRCDIR)/, $(FILES))
OBJS =		$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS)) $(LIBFT)

ANSI_CYAN := \033[0;36m
ANSI_BLUE := \033[0;34m
ANSI_RED := \033[31m
ANSI_RESET := \033[0m

all: $(NAME)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(PF_H)
			@mkdir -p $(OBJDIR)
			@gcc  $(CFLAGS) -o $@ -c $< 

$(NAME):	$(OBJS) $(LIBFT)
			@ar rcs  $(NAME) $(OBJS) $(LIBFT) 
			@echo "$(ANSI_CYAN)Compilation Complete: $(NAME) $(ANSI_RESET)"

$(LIBFT):
			@make -C $(LIBFT_DIR)
			@echo "$(ANSI_CYAN)LIBFT Library Compiled$(ANSI_RESET)"

clean: 
			@rm -rf $(OBJDIR) 
			@make -C $(LIBFT_DIR) clean
			@echo "$(ANSI_RED)Objects and Libraries:$(LIBFT_DIR) cleaned$(ANSI_RESET)"

fclean: 	clean
			@rm -rf $(NAME)
			@make -C $(LIBFT_DIR) fclean
			@echo "$(ANSI_RED)Executable $(NAME) removed$(ANSI_RESET)"

re: 		fclean all

.PHONY: all clean fclean re
