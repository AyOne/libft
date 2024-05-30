# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:03:49 by gbetting          #+#    #+#              #
#    Updated: 2024/05/30 17:13:32 by gbetting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DNAME = $(NAME:.a=_debug.a)
RNAME = $(NAME:.a=_release.a)
SRC =	ft_isalpha.c			\
		ft_isdigit.c			\
		ft_isalnum.c			\
		ft_isascii.c			\
		ft_isprint.c			\
		ft_strlen.c				\
		ft_memset.c				\
		ft_bzero.c				\
		ft_memcpy.c				\
		ft_memmove.c			\
		ft_strlcpy.c			\
		ft_strlcat.c			\
		ft_toupper.c			\
		ft_tolower.c			\
		ft_strchr.c				\
		ft_strrchr.c			\
		ft_strncmp.c			\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_strnstr.c			\
		ft_atoi.c				\
		ft_calloc.c				\
		ft_strdup.c				\
		ft_striteri.c			\
		ft_substr.c				\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_strmapi.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c
BONUS =	ft_lstnew_bonus.c		\
		ft_lstadd_front_bonus.c	\
		ft_lstsize_bonus.c		\
		ft_lstlast_bonus.c		\
		ft_lstadd_back_bonus.c	\
		ft_lstdelone_bonus.c	\
		ft_lstclear_bonus.c		\
		ft_lstiter_bonus.c		\
		ft_lstmap_bonus.c

HEADERS = $(NAME:.a=.h)

ifdef DO_BONUS
	SRC += $(BONUS)
endif

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
HEADERS_DIR = .
HEADERS_FILES = $(addprefix $(HEADERS_DIR)/, $(HEADERS))
SRC_DIR = .
OBJ_DIR = build/normal
DEBUG_DIR = build/debug
RELEASE_DIR = build/release
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(SRC_FILES))
RELEASE_OBJ = $(patsubst $(SRC_DIR)/%.c,$(RELEASE_DIR)/%.o,$(SRC_FILES))
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs
DEBUGFLAGS = -g3 -fsanitize=address
RELEASEFLAGS = -O3 -fno-builtin

normal: norminette.log $(NAME)

debug: CFLAGS += $(DEBUGFLAGS)
debug: norminette.log $(DNAME)

release: CFLAGS += $(RELEASEFLAGS)
release: norminette.log $(RNAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	-norminette $(HEADERS_FILES) >> norminette.log
	$(AR) $(ARFLAGS) $@ $(filter-out $(OBJ_DIR), $?)
	-cat norminette.log | grep -E "Error|Warning"

$(DNAME): $(DEBUG_DIR) $(DEBUG_OBJ)
	-norminette $(HEADERS_FILES) >> norminette.log
	$(AR) $(ARFLAGS) $@ $(filter-out $(DEBUG_DIR), $?)
	-cat norminette.log | grep -E "Error|Warning"

$(RNAME): $(RELEASE_DIR) $(RELEASE_OBJ)
	-norminette $(HEADERS_FILES) >> norminette.log
	$(AR) $(ARFLAGS) $@ $(filter-out $(RELEASE_DIR), $?)
	-cat norminette.log | grep -E "Error|Warning"

so: $(OBJ_DIR) $(OBJ)
	$(CC) -nostartfiles -shared -o $(NAME:.a=.so) $(filter-out $(OBJ_DIR), $?)

bonus:
	@$(MAKE) --no-print-directory DO_BONUS=$(DO_BONUS) normal

all:
	@$(MAKE) --no-print-directory DO_BONUS=$(DO_BONUS) -j normal
	@$(MAKE) --no-print-directory DO_BONUS=$(DO_BONUS) -j debug
	@$(MAKE) --no-print-directory DO_BONUS=$(DO_BONUS) -j release

$(RELEASE_DIR)/%.o $(DEBUG_DIR)/%.o $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	-norminette $< >> norminette.log
	[ -d `dirname $@` ] || mkdir -p `dirname $@`
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR)
	[ -d `dirname $(OBJ_DIR)` ] && rmdir -p `dirname $(OBJ_DIR)` || true
	rm -f norminette.log

fclean: clean
	rm -f $(NAME) $(DNAME) $(RNAME) test.out tests.out libft.so

re: fclean all

norminette.log:
	-@echo "" > norminette.log

.PHONY: all clean fclean re debug release bonus
