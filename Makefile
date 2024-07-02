# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:03:49 by gbetting          #+#    #+#              #
#    Updated: 2024/07/03 00:59:23 by gbetting         ###   ########.fr        #
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


#=== Sub libraries and dependencies ===========================================#
SUBLIBS =
SUBLIBS_DIR = $(foreach lib, $(SUBLIBS), $(dir $(lib)))
SUBLIBS_INC_DIR = $(foreach lib, $(SUBLIBS), $(dir $(lib))includes)
SUBLIBS_FLAGS = $(foreach lib, $(SUBLIBS), -L$(dir $(lib)) $(addprefix -l,$(patsubst lib%.a,%,$(notdir $(SUBLIBS)))))

#=== Automatic files ==========================================================#
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
HEADERS_FILES = $(addprefix $(HEADERS_DIR)/, $(HEADERS))
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(SRC_FILES))
RELEASE_OBJ = $(patsubst $(SRC_DIR)/%.c,$(RELEASE_DIR)/%.o,$(SRC_FILES))

#=== Colors variables =========================================================#
C_MAKEFILE=\033[38;5;16;48;5;51;1mMakefile\033[0m
C_CREATINGFOLDER=\033[38;5;16;48;5;51;1mCreating folder\033[0m
C_COMPILATION=\033[38;5;16;48;5;51;1mCompiling\033[0m
C_DELETING=\033[38;5;16;48;5;196;1mDeleting\033[0m
C_COMPILATION_OK=\033[38;5;16;48;5;46;1mCompilation\033[0m
C_COMPILATION_ERROR=\033[38;5;16;48;5;196;1mCompilation\033[0m
C_NORME_ERROR=\033[38;5;16;48;5;196;1mNorme\033[0m
C_NORME_OK=\033[38;5;16;48;5;46;1mNorme\033[0m
C_MAXLEN := $(shell echo "$(SRC_FILES)" | tr " " "\n" | awk 'length > max_length { max_length = length; longest_line = $$0 } END { print longest_line }' | wc -c)

#=== Compilation variables ====================================================#
CC = clang
CFLAGS = -Wall -Wextra -Werror -fPIE
AR = ar
ARFLAGS = -rcs
DEBUGFLAGS = -g3 -fsanitize=address
RELEASEFLAGS = -O3 -fno-builtin

#=== Functions ================================================================#
define print_result
	@if [ -s $(LOG_DIR)/error.log ]; then \
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

define call_self
	@if [ $(2) ]; then \
		PREFIX_TEXT=$(2); \
	else \
		PREFIX_TEXT=$(1); \
	fi; \
	printf "$(PREFIX)$(C_MAKEFILE) -> \033[38;5;22m$$PREFIX_TEXT\033[0m\n"; \
	$(MAKE) --no-print-directory PREFIX="\033[38;5;22;1m[$$PREFIX_TEXT] \033[0m" $(1) $(3);
endef

define mkdir
	@if [ ! -d $(1) ]; then \
		printf "$(PREFIX)$(C_CREATINGFOLDER) -> \033[38;5;33m$(1)\033[0m\n"; \
		mkdir -p $(1) 2> /dev/null || true; \
	fi
endef

define rmdir
	@if [ -d $(1) ]; then \
		printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(1)\033[0m\n"; \
		rm -rf $(1); \
	fi
endef

define rm
	@if [ -f $(1) ]; then \
		printf "$(PREFIX)$(C_DELETING) -> \033[38;5;33m$(1)\033[0m\n"; \
		rm -f $(1); \
	fi
endef

define make_bin
	@printf "$(PREFIX)$(C_COMPILATION) -> \033[38;5;165m%-*s\033[0m : " $(C_MAXLEN) "$@"
@# for now I have no other way to merge the sublibs togeather with my lib. when I got a better way I'll use it.
@# Warning : Don't do this at home
	@if [ "$(SUBLIBS)" ]; then \
		$(foreach lib, $(SUBLIBS), cp $(lib) $(notdir $(lib));$(AR) -x $(notdir $(lib));rm -f $(notdir $(lib));) \
		$(AR) $(ARFLAGS) $@ $? *.o 2> $(LOG_DIR)/error.log || true; \
	else \
		$(AR) $(ARFLAGS) $@ $? 2> $(LOG_DIR)/error.log || true; \
	fi
	@rm -f ./*.o
@# end of the warning
	$(call print_result)
endef

define norminette
	@$(NORMINETTE) $(1) 2> /dev/null | grep -E "Error|Warning" > $(LOG_DIR)/norminette.log || true
endef

define call_lib
	@if [ ! -f $(1) ]; then \
		git submodule update --init --recursive; \
	fi
	@printf "$(PREFIX)$(C_MAKEFILE) -> \033[38;5;22m$(1) ($(2))\033[0m\n"
	@$(MAKE) --no-print-directory -C $(dir $(1)) SKIP_NORME=1 PREFIX="\033[38;5;22;1m[$(1)] \033[0m" $(2)
endef

define rmdir_lib
	@$(MAKE) --no-print-directory -C $(dir $(1)) PREFIX="\033[38;5;22;1m[$(1)] \033[0m" fclean
endef
#=== Main build rules =========================================================#
normal: $(NAME)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(DNAME)

release: CFLAGS += $(RELEASEFLAGS)
release: $(RNAME)

all:
	$(call call_self,normal)
	$(call call_self,debug)
	$(call call_self,release)

bonus:
	@$(call call_self,normal,bonus,DO_BONUS=1)

--clean:
	$(call rmdir,$(OBJ_DIR))
	$(call rmdir,$(DEBUG_DIR))
	$(call rmdir,$(RELEASE_DIR))
	$(call rmdir,$(LOG_DIR))

clean: --clean
	$(foreach lib, $(SUBLIBS), $(call call_lib,$(lib),clean))

fclean: --clean
	$(foreach lib, $(SUBLIBS), $(call call_lib,$(lib),fclean))
	$(call rm,$(NAME))
	$(call rm,$(DNAME))
	$(call rm,$(RNAME))

re: fclean all

.PHONY: all clean --clean fclean re debug release bonus
.SECONDARY: $(SUBLIBS)

#=== Binary compilation rule ==================================================#
$(NAME): $(OBJ)
	$(call norminette,$(HEADERS_FILES))
	$(call make_bin)

# don't call this rule directly
$(DNAME): $(DEBUG_OBJ)
	$(call norminette,$(HEADERS_FILES))
	$(call make_bin)

# don't call this rule directly
$(RNAME): $(RELEASE_OBJ)
	$(call norminette,$(HEADERS_FILES))
	$(call make_bin)

$(RELEASE_DIR)/%.o $(DEBUG_DIR)/%.o $(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES) $(SUBLIBS)
	$(call mkdir,$(LOG_DIR))
	$(call mkdir,$(dir $@))
	@printf "$(PREFIX)$(C_COMPILATION) -> \033[38;5;33m%-*s\033[0m : " $(C_MAXLEN) "$<"
	$(call norminette,$<)
	@$(CC) $(CFLAGS) $(addprefix -I,$(HEADERS_DIR) $(SUBLIBS_INC_DIR)) -c $< -o $@ 2> $(LOG_DIR)/error.log || true
	$(call print_result)

%.a:
	$(call call_lib,$@)
