# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 09:03:49 by gbetting          #+#    #+#              #
#    Updated: 2024/09/07 04:38:34 by gbetting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
DNAME = $(NAME:.a=_debug.a)
RNAME = $(NAME:.a=_release.a)

SRC_DLST = dlst/ft_dlstadd_back.c dlst/ft_dlstadd_front.c					\
			dlst/ft_dlstclear.c	dlst/ft_dlstfind.c dlst/ft_dlstget.c		\
			dlst/ft_dlstiter.c dlst/ft_dlstmap.c dlst/ft_dlstnew.c			\
			dlst/ft_dlstpop.c dlst/ft_dlstto_array.c
SRC_GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_LST = lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c		\
			lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c			\
			lst/ft_lstmap.c lst/ft_lstnew.c lst/ft_lstsize.c
SRC_MATH = math/ft_abs.c math/ft_minmax.c
SRC_MEM = mem/ft_bzero.c mem/ft_calloc.c mem/ft_memchr.c mem/ft_memcmp.c	\
			mem/ft_memcpy.c mem/ft_memdup.c mem/ft_memmove.c mem/ft_memset.c
SRC_PRINTF = printf/ft_buffer.c printf/ft_format.c printf/ft_printf.c		\
			printf/specifiers/ft_c.c printf/specifiers/ft_i.c				\
			printf/specifiers/ft_p.c printf/specifiers/ft_percent.c			\
			printf/specifiers/ft_s.c printf/specifiers/ft_specifiers.c		\
			printf/specifiers/ft_u.c printf/specifiers/ft_x.c				\
			printf/specifiers/ft_n.c
SRC_STR = str/ft_atoi.c str/ft_isalnum.c str/ft_isalpha.c str/ft_isascii.c	\
			str/ft_isdigit.c str/ft_isprint.c str/ft_itoa.c str/ft_split.c	\
			str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c				\
			str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c				\
			str/ft_strlen.c	str/ft_strmapi.c str/ft_strncmp.c				\
			str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c				\
			str/ft_substr.c str/ft_tolower.c str/ft_toupper.c
SRC_UTILS = utils/ft_nbrbase.c utils/ft_nbrlen.c utils/ft_qsort_cmp.c		\
			utils/ft_qsort.c utils/ft_ternary.c

SRC = $(SRC_GNL) $(SRC_LST) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF)			\
		$(SRC_STR) $(SRC_UTILS) $(SRC_DLST)
		
BONUS =

HEADERS = libft.h get_next_line.h ft_printf.h

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
