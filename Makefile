# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:03:49 by gbetting          #+#    #+#              #
#    Updated: 2024/04/21 07:44:28 by gbetting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DNAME = $(NAME:.a=_debug.a)
RNAME = $(NAME:.a=_release.a)
SRC =	ft_isalpha.c		\
		ft_isdigit.c		\
		ft_isalnum.c		\
		ft_isascii.c		\
		ft_isprint.c		\
		ft_strlen.c			\
		ft_memset.c			\
		ft_bzero.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_strlcpy.c		\
		ft_strlcat.c		\
		ft_toupper.c		\
		ft_tolower.c		\
		ft_strchr.c			\
		ft_strrchr.c		\
		ft_strncmp.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_strnstr.c		\
		ft_atoi.c			\
		ft_calloc.c			\
		ft_strdup.c			\
		ft_substr.c			\
		ft_strjoin.c		\
		ft_strtrim.c		\
		ft_split.c			\
		ft_itoa.c			\
		ft_strmapi.c		\
		ft_putchar_fd.c		\
		ft_putstr_fd.c		\
		ft_putendl_fd.c		\
		ft_putnbr_fd.c		\
		ft_lstnew.c			\
		ft_lstadd_front.c	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c
BONUS =
HEADERS = $(NAME:.a=.h)

ifdef DO_BONUS
	SRC += $(BONUS)
	HEADERS += $(wildcard $(NAME:.a=_bonus.h))
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

normal: $(OBJ_DIR) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(DEBUG_DIR) $(DEBUG_OBJ)
	$(AR) $(ARFLAGS) $(DNAME) $(DEBUG_OBJ)

release: CFLAGS += $(RELEASEFLAGS)
release: $(RELEASE_DIR) $(RELEASE_OBJ)
	norminette $(HEADERS_FILES)
	$(AR) $(ARFLAGS) $(RNAME) $(RELEASE_OBJ)

$(NAME): normal

bonus:
	@$(MAKE) --no-print-directory DO_BONUS=1 normal

all:
	@$(MAKE) --no-print-directory DO_BONUS=1 -j normal
	@$(MAKE) --no-print-directory DO_BONUS=1 -j debug
	@$(MAKE) --no-print-directory DO_BONUS=1 -j release

$(RELEASE_DIR)/%.o $(DEBUG_DIR)/%.o $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	norminette $<
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR)
	[ -d `dirname $(OBJ_DIR)` ] && rmdir -p `dirname $(OBJ_DIR)` || true

fclean: clean
	rm -f $(NAME) $(DNAME) $(RNAME)

re: fclean all

.PHONY: all clean fclean re debug release bonus
