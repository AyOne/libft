# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:03:49 by gbetting          #+#    #+#              #
#    Updated: 2024/06/26 02:58:55 by gbetting         ###   ########.fr        #
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

# colors
C_CREATINGFOLDER=\033[38;5;16;48;5;51mCreating folder\033[0m
C_COMPILATION=\033[38;5;16;48;5;51mCompiling\033[0m
C_COMPILATION2=\033[38;5;16;48;5;51mCompiling\033[0m
C_DELETING=\033[38;5;16;48;5;196mDeleting\033[0m
C_OK=\033[38;5;16;48;5;46mOK\033[0m
C_ERROR=\033[38;5;16;48;5;196mERROR\033[0m
C_NORME=\033[38;5;16;48;5;196mNORME\033[0m
C_MAXLEN := $(shell echo "$(SRC)" | tr " " "\n" | awk 'length > max_length { max_length = length; longest_line = $$0 } END { print longest_line }' | wc -c)
C_COMPILATION_ERROR=0

#$(info $(C_MAXLEN))

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
HEADERS_DIR = .
HEADERS_FILES = $(addprefix $(HEADERS_DIR)/, $(HEADERS))
SRC_DIR = .
OBJ_DIR = build/normal
DEBUG_DIR = build/debug
RELEASE_DIR = build/release
LOG_DIR = logs
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(SRC_FILES))
RELEASE_OBJ = $(patsubst $(SRC_DIR)/%.c,$(RELEASE_DIR)/%.o,$(SRC_FILES))
CC = clang
CFLAGS = -Wall -Wextra -Werror -fdiagnostics-color=always
AR = ar
ARFLAGS = -rcs
DEBUGFLAGS = -g3 -fsanitize=address
RELEASEFLAGS = -O3 -fno-builtin

normal: $(NAME)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(DNAME)

release: CFLAGS += $(RELEASEFLAGS)
release: $(RNAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	$(AR) $(ARFLAGS) $@ $(filter-out $(OBJ_DIR), $?)

$(DNAME): $(DEBUG_DIR) $(DEBUG_OBJ)
	$(AR) $(ARFLAGS) $@ $(filter-out $(DEBUG_DIR), $?)

$(RNAME): $(RELEASE_DIR) $(RELEASE_OBJ)
	$(AR) $(ARFLAGS) $@ $(filter-out $(RELEASE_DIR), $?)

bonus:
	@$(MAKE) --no-print-directory DO_BONUS=1 normal

all:
	@$(MAKE) --no-print-directory -j normal
	@$(MAKE) --no-print-directory -j debug
	@$(MAKE) --no-print-directory -j release

$(RELEASE_DIR)/%.o $(DEBUG_DIR)/%.o $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES) | $(LOG_DIR)
	@printf "$(C_COMPILATION) -> \033[38;5;33m%-*s\033[0m : " $(C_MAXLEN) "$<"
	@#norminette $< 2> /dev/null | grep -E "Error|Warning" > $(LOG_DIR)/norminette.log || true
	@[ -d `dirname $@` ] || mkdir -p `dirname $@`
	@($(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@ 2> $(LOG_DIR)/error.log || true)
	@if [ -s $(LOG_DIR)/error.log ]; then \
		printf "$(C_ERROR)\n"; \
		cat $(LOG_DIR)/error.log; \
		COMPILATION_ERROR=1; \
		false; \
	elif [ -s $(LOG_DIR)/norminette.log ]; then \
		printf "$(C_NORME)\n"; \
		cat $(LOG_DIR)/norminette.log; \
		false; \
	else \
		printf "$(C_OK)\n"; \
		true; \
	fi
	@#printf "$(C_OK)\n"

$(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR) $(LOG_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR)
	[ -d `dirname $(OBJ_DIR)` ] && rmdir -p `dirname $(OBJ_DIR)` || true
	rm -rf $(LOG_DIR)

fclean: clean
	rm -f $(NAME) $(DNAME) $(RNAME) test.out tests.out libft.so

re: fclean all

.PHONY: all clean fclean re debug release bonus
