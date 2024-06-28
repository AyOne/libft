# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:03:49 by gbetting          #+#    #+#              #
#    Updated: 2024/06/28 04:27:14 by gbetting         ###   ########.fr        #
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
		ft_putnbr_fd.c			\
		ft_lstnew.c				\
		ft_lstadd_front.c		\
		ft_lstsize.c			\
		ft_lstlast.c			\
		ft_lstadd_back.c		\
		ft_lstdelone.c			\
		ft_lstclear.c			\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_abs.c				\
		ft_minmax.c				\
		ft_ternary.c			\
		get_next_line.c			\
		get_next_line_utils.c
BONUS =

HEADERS = $(NAME:.a=.h) get_next_line.h

ifdef DO_BONUS
	SRC += $(BONUS)
endif

ifndef SKIP_NORME
	NORMINETTE=norminette
else
	NORMINETTE=this_program_does_not_exist
endif

SRC_DIR = srcs
HEADERS_DIR = includes
OBJ_DIR = build/normal
DEBUG_DIR = build/debug
RELEASE_DIR = build/release
LOG_DIR = logs

SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
HEADERS_FILES = $(addprefix $(HEADERS_DIR)/, $(HEADERS))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(SRC_FILES))
RELEASE_OBJ = $(patsubst $(SRC_DIR)/%.c,$(RELEASE_DIR)/%.o,$(SRC_FILES))

C_MAKEFILE=\033[38;5;16;48;5;51;1mMakefile\033[0m
C_CREATINGFOLDER=\033[38;5;16;48;5;51;1mCreating folder\033[0m
C_COMPILATION=\033[38;5;16;48;5;51;1mCompiling\033[0m
C_DELETING=\033[38;5;16;48;5;196;1mDeleting\033[0m
C_COMPILATION_OK=\033[38;5;16;48;5;46;1mCompilation\033[0m
C_COMPILATION_ERROR=\033[38;5;16;48;5;196;1mCompilation\033[0m
C_NORME_ERROR=\033[38;5;16;48;5;196;1mNorme\033[0m
C_NORME_OK=\033[38;5;16;48;5;46;1mNorme\033[0m
C_MAXLEN := $(shell echo "$(SRC_FILES)" | tr " " "\n" | awk 'length > max_length { max_length = length; longest_line = $$0 } END { print longest_line }' | wc -c)

CC = clang
CFLAGS = -Wall -Wextra -Werror -fdiagnostics-color=always
AR = ar
ARFLAGS = -rcs
DEBUGFLAGS = -g3 -fsanitize=address
RELEASEFLAGS = -O3 -fno-builtin


define print_result
	if [ -s $(LOG_DIR)/error.log ]; then \
		printf "$(C_COMPILATION_ERROR)"; \
		COMPILATION_ERROR=1; \
	else \
		printf "$(C_COMPILATION_OK)"; \
		COMPILATION_ERROR=0; \
	fi; \
	if [ $(SKIP_NORME) ]; then \
		printf "\n"; \
		NORME_ERROR=0; \
	elif [ -s $(LOG_DIR)/norminette.log ]; then \
		printf " $(C_NORME_ERROR)\n"; \
		NORME_ERROR=1; \
	else \
		printf " $(C_NORME_OK)\n"; \
		NORME_ERROR=0; \
	fi; \
	if [ $$COMPILATION_ERROR -eq 1 ]; then \
		cat $(LOG_DIR)/error.log; \
	fi; \
	if [ $$NORME_ERROR -eq 1 ]; then \
		cat $(LOG_DIR)/norminette.log; \
	fi; \
	if [ $$COMPILATION_ERROR -eq 1 ] || [ $$NORME_ERROR -eq 1 ]; then \
		false; \
	fi;
endef




normal: $(NAME)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(DNAME)

release: CFLAGS += $(RELEASEFLAGS)
release: $(RNAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@$(NORMINETTE) $(HEADERS_FILES) 2> /dev/null | grep -E "Error|Warning" > $(LOG_DIR)/norminette.log || true
	@printf "$(PREFIX)$(C_COMPILATION) -> \033[38;5;165m%-*s\033[0m : " $(C_MAXLEN) "$@"
	@$(AR) $(ARFLAGS) $@ $(filter-out $(OBJ_DIR), $?) 2> $(LOG_DIR)/error.log || true
	@$(call print_result)

$(DNAME): $(DEBUG_DIR) $(DEBUG_OBJ)
	@$(NORMINETTE) $(HEADERS_FILES) 2> /dev/null | grep -E "Error|Warning" > $(LOG_DIR)/norminette.log || true
	@printf "$(PREFIX)$(C_COMPILATION) -> \033[38;5;165m%-*s\033[0m : " $(C_MAXLEN) "$@"
	@$(AR) $(ARFLAGS) $@ $(filter-out $(DEBUG_DIR), $?) 2> $(LOG_DIR)/error.log || true
	

$(RNAME): $(RELEASE_DIR) $(RELEASE_OBJ)
	@$(NORMINETTE) $(HEADERS_FILES) 2> /dev/null | grep -E "Error|Warning" > $(LOG_DIR)/norminette.log || true
	@printf "$(PREFIX)$(C_COMPILATION) -> \033[38;5;165m%-*s\033[0m : " $(C_MAXLEN) "$@"
	@$(AR) $(ARFLAGS) $@ $(filter-out $(RELEASE_DIR), $?) 2> $(LOG_DIR)/error.log || true
	@$(call print_result)

bonus:
	@printf "$(C_MAKEFILE) -> \033[38;5;22mbonus\033[0m\n"
	@$(MAKE) --no-print-directory DO_BONUS=1 PREFIX="\033[38;5;22;1m[bonus] \033[0m" normal

all:
	@printf "$(C_MAKEFILE) -> \033[38;5;22mnormal\033[0m\n"
	@$(MAKE) --no-print-directory PREFIX="\033[38;5;22;1m[normal] \033[0m" normal
	@printf "$(C_MAKEFILE) -> \033[38;5;22mdebug\033[0m\n"
	@$(MAKE) --no-print-directory PREFIX="\033[38;5;22;1m[debug] \033[0m" debug
	@printf "$(C_MAKEFILE) -> \033[38;5;22mrelease\033[0m\n"
	@$(MAKE) --no-print-directory PREFIX="\033[38;5;22;1m[release] \033[0m" release

$(RELEASE_DIR)/%.o $(DEBUG_DIR)/%.o $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES) | $(LOG_DIR)
	@printf "$(PREFIX)$(C_COMPILATION) -> \033[38;5;33m%-*s\033[0m : " $(C_MAXLEN) "$<"
	@$(NORMINETTE) $< 2> /dev/null | grep -E "Error|Warning" > $(LOG_DIR)/norminette.log || true
	@[ -d `dirname $@` ] || mkdir -p `dirname $@`
	@($(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@ 2> $(LOG_DIR)/error.log || true)
	@$(call print_result)

$(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR) $(LOG_DIR):
	@printf "$(PREFIX)$(C_CREATINGFOLDER) -> \033[38;5;33m%-*s\033[0m\n" $(C_MAXLEN) "$@"
	@mkdir -p $@

clean:
	@printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(OBJ_DIR)\033[0m\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(DEBUG_DIR)\033[0m\n"
	@rm -rf $(DEBUG_DIR)
	@printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(RELEASE_DIR)\033[0m\n"
	@rm -rf $(RELEASE_DIR)
	@#[ -d `dirname $(OBJ_DIR)` ] && rmdir -p `dirname $(OBJ_DIR)` || true
	@printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(LOG_DIR)\033[0m\n"
	@rm -rf $(LOG_DIR)

fclean: clean
	@printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(NAME)\033[0m\n"
	@rm -f $(NAME)
	@printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(DNAME)\033[0m\n"
	@rm -f $(DNAME)
	@printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(RNAME)\033[0m\n"
	@rm -f $(RNAME)

re: fclean all

.PHONY: all clean fclean re debug release bonus
