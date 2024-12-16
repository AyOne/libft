# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbetting <gbetting@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 11:29:19 by gbetting          #+#    #+#              #
#    Updated: 2024/12/16 22:24:05 by gbetting         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# Universal Makefile by AyOne ( gbetting )                                     #
# Version 3.1.4                                                                #
# **************************************************************************** #

NAME = libft.a
BONUS_NAME = 

# .c files
SRC_DLST =	dlst/ft_dlstadd_at.c dlst/ft_dlstadd_back.c dlst/ft_dlstadd_front.c	\
			dlst/ft_dlstclear.c	dlst/ft_dlstfind.c dlst/ft_dlstget.c			\
			dlst/ft_dlstiter.c dlst/ft_dlstmap.c dlst/ft_dlstnew.c				\
			dlst/ft_dlstpop.c dlst/ft_dlstto_array.c
SRC_GNL =	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRC_MATH =	math/ft_abs.c math/ft_minmax.c
SRC_MEM =	mem/ft_bzero.c mem/ft_calloc.c mem/ft_memchr.c mem/ft_memcmp.c		\
			mem/ft_memcpy.c mem/ft_memdup.c mem/ft_memmove.c mem/ft_memset.c
SRC_PRINTF =printf/ft_buffer.c printf/ft_format.c printf/ft_printf.c			\
			printf/specifiers/ft_c.c printf/specifiers/ft_i.c					\
			printf/specifiers/ft_p.c printf/specifiers/ft_percent.c				\
			printf/specifiers/ft_s.c printf/specifiers/ft_specifiers.c			\
			printf/specifiers/ft_u.c printf/specifiers/ft_x.c					\
			printf/specifiers/ft_n.c printf/ft_color.c printf/ft_exec.c
SRC_STR =	str/ft_atoi.c str/ft_isalnum.c str/ft_isalpha.c str/ft_isascii.c	\
			str/ft_isdigit.c str/ft_isprint.c str/ft_itoa.c str/ft_split.c		\
			str/ft_strchr.c str/ft_strdup.c str/ft_striteri.c					\
			str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c					\
			str/ft_strlen.c	str/ft_strmapi.c str/ft_strncmp.c					\
			str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c					\
			str/ft_substr.c str/ft_tolower.c str/ft_toupper.c str/ft_itoa_nm.c
SRC_UTILS =	utils/ft_deepfree.c utils/ft_nbrbase.c utils/ft_nbrlen.c			\
			utils/ft_qsort_cmp.c utils/ft_qsort.c utils/ft_rng.c				\
			utils/ft_ternary.c

SRC =		$(sort $(SRC_GNL) $(SRC_LST) $(SRC_MATH) $(SRC_MEM) $(SRC_PRINTF)	\
			$(SRC_STR) $(SRC_UTILS) $(SRC_DLST))
BONUS_SRC =	

# .h files
HEADERS = libft.h get_next_line.h ft_printf.h
ifdef BONUS_NAME
	BONUS_HEADERS = 
endif

EXTRA_FLAGS =
ifdef BONUS_NAME
	BONUS_EXTRA_FLAGS =
endif

# define if project is a .a library
IS_LIB = 1

# define if project need to compile and link libft
INCLUDE_FT = 
# define if project need to compile and link libmlx ( not implemented )
INCLUDE_MLX =

##################################
##### DO NOT EDIT BELOW THIS #####
##################################

# disable norminette when SKIP_NORME is set to any value
ifndef SKIP_NORME
	NORMINETTE=norminette
else
	NORMINETTE=this_program_does_not_exist
endif

# binaries
RNAME = $(basename $(NAME))_release$(suffix $(NAME))
DNAME = $(basename $(NAME))_debug$(suffix $(NAME))
ifdef $(BONUS_NAME)
	BONUS_RNAME = $(basename $(BONUS_NAME))_release$(suffix $(BONUS_NAME))
	BONUS_DNAME = $(basename $(BONUS_NAME))_debug$(suffix $(BONUS_NAME))
endif

# directories
SRC_DIR = srcs
HEADERS_DIR = includes
BUILD_DIR = build
MAIN_DIR = $(BUILD_DIR)/main
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release
LOG_DIR = $(BUILD_DIR)/log

# sub libraries
SUBLIBS =
ifdef INCLUDE_FT
	SUBLIBS += libft/libft.a
	SUBLIBS_DEBUG += libft/libft_debug.a
	SUBLIBS_RELEASE += libft/libft_release.a
endif
ifdef INCLUDE_MLX
	SUBLIBS += libmlx/libmlx.a
endif
SUBLIBS_INC_DIR = $(foreach lib, $(SUBLIBS), $(dir $(lib))includes)
SUBLIBS_FLAGS = $(foreach lib, $(SUBLIBS), -L$(dir $(lib)) $(addprefix -l,$(patsubst lib%.a,%,$(notdir $(lib)))))
SUBLIBS_DEBUG_FLAGS = $(foreach lib, $(SUBLIBS_DEBUG), -L$(dir $(lib)) $(addprefix -l,$(patsubst lib%.a,%,$(notdir $(lib)))))
SUBLIBS_RELEASE_FLAGS = $(foreach lib, $(SUBLIBS_RELEASE), -L$(dir $(lib)) $(addprefix -l,$(patsubst lib%.a,%,$(notdir $(lib)))))

# path construction
SRC_FILES := $(sort $(addprefix $(SRC_DIR)/, $(SRC)))
HEADERS_FILES = $(sort $(addprefix $(HEADERS_DIR)/, $(HEADERS)))
OBJ_FILES = $(addprefix $(MAIN_DIR)/, $(SRC:.c=.o))
DEBUG_OBJ_FILES = $(addprefix $(DEBUG_DIR)/, $(SRC:.c=.o))
RELEASE_OBJ_FILES = $(addprefix $(RELEASE_DIR)/, $(SRC:.c=.o))
ifdef BONUS_NAME
	BONUS_FILES := $(sort $(addprefix $(SRC_DIR)/, $(BONUS_SRC)))
	BONUS_OBJ_FILES = $(addprefix $(MAIN_DIR)/, $(BONUS_SRC:.c=.o))
	BONUS_HEADERS_FILES = $(sort $(addprefix $(HEADERS_DIR)/, $(BONUS_HEADERS)))
	BONUS_DEBUG_OBJ_FILES = $(addprefix $(DEBUG_DIR)/, $(BONUS_SRC:.c=.o))
	BONUS_RELEASE_OBJ_FILES = $(addprefix $(RELEASE_DIR)/, $(BONUS_SRC:.c=.o))
endif

# colors constants
C_MAKEFILE=\033[38;5;16;48;5;51;1mMakefile\033[0m
C_CREATINGFOLDER=\033[38;5;16;48;5;51;1mCreating folder\033[0m
C_COMPILATION=\033[38;5;16;48;5;51;1mCompiling\033[0m
C_DELETING=\033[38;5;16;48;5;196;1mDeleting\033[0m
C_FILE=\033[38;5;33m%s\033[0m
C_FILE_SPACE=\033[38;5;33m%-*s\033[0m
C_BIN=\033[38;5;165m%-*s\033[0m
C_SELF=\033[38;5;22m%s\033[0m
C_SELF_BOLD=\033[38;5;22;1m%s\033[0m
C_COMPILATION_OK=\033[38;5;16;48;5;46;1mCompilation\033[0m
C_COMPILATION_ERROR=\033[38;5;16;48;5;196;1mCompilation\033[0m
C_NORME_ERROR=\033[38;5;16;48;5;196;1mNorme\033[0m
C_NORME_OK=\033[38;5;16;48;5;46;1mNorme\033[0m
C_NORME_SKIP=\033[38;5;16;48;5;240;1mNorme\033[0m
C_MAXLEN := $(shell echo "$(SRC_FILES)" | tr " " "\n" | awk 'length > max_length { max_length = length; longest_line = $$0 } END { print longest_line }' | wc -c)

# Add these with other color constants
C_TITLE=\033[1;4;33m%s\033[0m
C_RULE=\033[1;32m%-12s\033[0m
C_DESC=\033[38;5;248m%s\033[0m

# compilation flags
CC = clang
AR = ar
ARFLAGS = -rcs
DEFAULT_CFLAGS = -Wall -Wextra -Werror -fPIE
MEGA_FLAGS =	-Wshadow -Wconversion -Wsign-conversion -Wfloat-equal			\
				-Wcast-align -Wpointer-arith -Wmissing-prototypes				\
				-Wstrict-prototypes -Wold-style-definition						\
				-Wmissing-declarations -Wredundant-decls -Winline				\
				-Wundef -Wnull-dereference -Wdouble-promotion -Wformat=2
ifdef PAIN
	DEFAULT_CFLAGS += $(MEGA_FLAGS)
endif
DEBUG_FLAGS = -g3
RELEASE_FLAGS = -O3 -fno-builtin

# macros

define print_result
	if [ $(SKIP_NORME) ]; then \
		[ -s $(LOG_DIR)/error.log ] && printf "$(PREFIX)$(C_COMPILATION) -> $(C_FILE_SPACE) : $(C_COMPILATION_ERROR) $(C_NORME_SKIP)\n" $(C_MAXLEN) "$(1)" && cat $(LOG_DIR)/error.log && exit 1 || \
		printf "$(PREFIX)$(C_COMPILATION) -> $(C_FILE_SPACE) : $(C_COMPILATION_OK) $(C_NORME_SKIP)\n" $(C_MAXLEN) "$(1)"; \
	else \
		[ -s $(LOG_DIR)/error.log ] && printf "$(PREFIX)$(C_COMPILATION) -> $(C_FILE_SPACE) : $(C_COMPILATION_ERROR) $(C_NORME_OK)\n" $(C_MAXLEN) "$(1)" && cat $(LOG_DIR)/error.log && exit 1 || \
		[ -s $(LOG_DIR)/norminette.log ] && printf "$(PREFIX)$(C_COMPILATION) -> $(C_FILE_SPACE) : $(C_COMPILATION_OK) $(C_NORME_ERROR)\n" $(C_MAXLEN) "$(1)" && cat $(LOG_DIR)/norminette.log && exit 1 || \
		printf "$(PREFIX)$(C_COMPILATION) -> $(C_FILE_SPACE) : $(C_COMPILATION_OK) $(C_NORME_OK)\n" $(C_MAXLEN) "$(1)"; \
	fi;
endef

define print_result_bin
	if [ $(SKIP_NORME) ]; then \
		[ -s $(LOG_DIR)/error.log ] && printf "$(PREFIX)$(C_COMPILATION) -> $(C_BIN) : $(C_COMPILATION_ERROR) $(C_NORME_SKIP)\n" $(C_MAXLEN) "$(1)" && cat $(LOG_DIR)/error.log && false || \
		printf "$(PREFIX)$(C_COMPILATION) -> $(C_BIN) : $(C_COMPILATION_OK) $(C_NORME_SKIP)\n" $(C_MAXLEN) "$(1)"; \
	else \
		[ -s $(LOG_DIR)/error.log ] && printf "$(PREFIX)$(C_COMPILATION) -> $(C_BIN) : $(C_COMPILATION_ERROR) $(C_NORME_OK)\n" $(C_MAXLEN) "$(1)" && cat $(LOG_DIR)/error.log && false || \
		[ -s $(LOG_DIR)/norminette.log ] && printf "$(PREFIX)$(C_COMPILATION) -> $(C_BIN) : $(C_COMPILATION_OK) $(C_NORME_ERROR)\n" $(C_MAXLEN) "$(1)" && cat $(LOG_DIR)/norminette.log && false || \
		printf "$(PREFIX)$(C_COMPILATION) -> $(C_BIN) : $(C_COMPILATION_OK) $(C_NORME_OK)\n" $(C_MAXLEN) "$(1)"; \
	fi;
endef

define call_self
	if [ $(2) ]; then PREFIX_TEXT=$(2); else PREFIX_TEXT=$(1); fi; \
	printf "$(PREFIX)$(C_MAKEFILE) -> $(C_SELF)\n" "$$PREFIX_TEXT"; \
	$(MAKE) --no-print-directory PREFIX=`printf "$(C_SELF_BOLD)" "$$PREFIX_TEXT"` $(1) $(3);
endef

define mkdir
	if [ ! -d $(1) ]; then printf "$(PREFIX)$(C_CREATINGFOLDER) -> $(C_FILE)\n" $(1); mkdir -p $(1) 2> /dev/null || true; fi
endef

define rmdir
	if [ -d $(1) ]; then printf "$(PREFIX)$(C_DELETING) -> $(C_FILE)\n" $(1); rm -rf $(1); fi
endef

define rm
	if [ $(1) ] && [ -f $(1) ]; then printf "$(PREFIX)$(C_DELETING) -> $(C_FILE)\n" $(1); rm -f $(1); fi
endef

define make_bin
	if [ $(IS_LIB) ]; then \
		$(AR) $(ARFLAGS) $@ $^ 2> $(LOG_DIR)/error.log || true; \
	elif [ $(1) = "debug" ]; then \
		$(CC) $(CFLAGS) $(addprefix -I,$(HEADERS_DIR) $(SUBLIBS_INC_DIR)) -o $@ $^ $(SUBLIBS_DEBUG_FLAGS) 2> $(LOG_DIR)/error.log || true; \
	elif [ $(1) = "release" ]; then \
		$(CC) $(CFLAGS) $(addprefix -I,$(HEADERS_DIR) $(SUBLIBS_INC_DIR)) -o $@ $^ $(SUBLIBS_RELEASE_FLAGS) 2> $(LOG_DIR)/error.log || true; \
	else \
		$(CC) $(CFLAGS) $(addprefix -I,$(HEADERS_DIR) $(SUBLIBS_INC_DIR)) -o $@ $^ $(SUBLIBS_FLAGS) 2> $(LOG_DIR)/error.log || true; \
	fi
endef

define norminette
	$(NORMINETTE) $(1) 2> /dev/null | grep -E "Error|Warning" > $(LOG_DIR)/norminette.log || true
endef

define call_libft
	if [ $(INCLUDE_FT) ]; then if [ ! -f libft/Makefile ]; then git submodule update --init --recursive; fi; printf "$(PREFIX)$(C_MAKEFILE) -> $(C_SELF)\n" "libft"; $(MAKE) --no-print-directory -C libft SKIP_NORME=1 PREFIX="`printf "$(C_SELF_BOLD)" "[libft] "`" $(1); fi;
endef

define call_libs
	$(call call_libft, $(1))
endef

##################################
############## RULES #############
##################################

main: $(NAME)

bonus: $(BONUS_NAME)

debug: $(DNAME) $(BONUS_DNAME)

release: $(RNAME) $(BONUS_RNAME)

all: main bonus

--clean:
	$(call rmdir,$(BUILD_DIR))

clean: --clean
	$(call call_libs, clean)

fclean: --clean
	$(call call_libs, fclean)
	$(call rm, $(NAME))
	$(call rm, $(DNAME))
	$(call rm, $(RNAME))
ifdef BONUS_NAME
	$(call rm, $(BONUS_NAME))
	$(call rm, $(BONUS_DNAME))
	$(call rm, $(BONUS_RNAME))
endif

re: fclean all

help:
	@printf "$(C_TITLE)\n" "Available rules:"
	@printf "  $(C_RULE)$(C_DESC)\n" "make main" "	Build the main target"
	@printf "  $(C_RULE)$(C_DESC)\n" "make bonus" "	Build the bonus target"
	@printf "  $(C_RULE)$(C_DESC)\n" "make debug" "	Build both main and bonus target with debug flags"
	@printf "  $(C_RULE)$(C_DESC)\n" "make release" "	Build both main and bonus target with release flags"
	@printf "  $(C_RULE)$(C_DESC)\n" "make all" "	Build both main and bonus targets"
	@printf "  $(C_RULE)$(C_DESC)\n" "make clean" "	Remove build directories"
	@printf "  $(C_RULE)$(C_DESC)\n" "make fclean" "	Remove build directories and binaries"
	@printf "  $(C_RULE)$(C_DESC)\n" "make re" "	Rebuild the project from scratch"
	@printf "  $(C_RULE)$(C_DESC)\n" "make help" "	Display this help message"

.PHONY: all clean --clean fclean re main bonus debug release help
.SECONDARY: $(SUBLIBS)
.SILENT:

$(NAME): CFLAGS = $(DEFAULT_CFLAGS) $(EXTRA_FLAGS)
$(NAME): $(OBJ_FILES)
	$(call norminette,$(HEADERS_FILES))
	$(call make_bin, main)
	$(call print_result_bin,$@)
$(DNAME): CFLAGS = $(DEFAULT_CFLAGS) $(EXTRA_FLAGS) $(DEBUG_FLAGS)
$(DNAME): $(DEBUG_OBJ_FILES)
	$(call norminette,$(HEADERS_FILES))
	$(call make_bin, debug)
	$(call print_result_bin,$@)
$(RNAME): CFLAGS = $(DEFAULT_CFLAGS) $(EXTRA_FLAGS) $(RELEASE_FLAGS)
$(RNAME): $(RELEASE_OBJ_FILES)
	$(call norminette,$(HEADERS_FILES))
	$(call make_bin,release)
	$(call print_result_bin,$@)
ifdef BONUS_NAME
$(BONUS_NAME): CFLAGS = $(DEFAULT_CFLAGS) $(BONUS_EXTRA_FLAGS)
$(BONUS_NAME): $(BONUS_OBJ_FILES)
	$(call norminette,$(BONUS_HEADERS_FILES))
	$(call make_bin,main)
	$(call print_result_bin,$@)
$(BONUS_DNAME): CFLAGS = $(DEFAULT_CFLAGS) $(BONUS_EXTRA_FLAGS) $(DEBUG_FLAGS)
$(BONUS_DNAME): $(BONUS_DEBUG_OBJ_FILES)
	$(call norminette,$(BONUS_HEADERS_FILES))
	$(call make_bin,debug)
	$(call print_result_bin,$@)
$(BONUS_RNAME): CFLAGS = $(DEFAULT_CFLAGS) $(BONUS_EXTRA_FLAGS) $(RELEASE_FLAGS)
$(BONUS_RNAME): $(BONUS_RELEASE_OBJ_FILES)
	$(call norminette,$(BONUS_HEADERS_FILES))
	$(call make_bin, release)
	$(call print_result_bin,$@)
endif

$(MAIN_DIR)/%.o: $(SRC_DIR)/%.c $(SUBLIBS) $(HEADERS_FILES) Makefile
	$(call mkdir,$(LOG_DIR))
	$(call mkdir,$(dir $@))
	$(call norminette,$<)
	$(CC) $(CFLAGS) $(addprefix -I,$(HEADERS_DIR) $(SUBLIBS_INC_DIR)) -c $< -o $@ 2> $(LOG_DIR)/error.log || true
	$(call print_result,$<)
$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c $(SUBLIBS_DEBUG) $(HEADERS_FILES) Makefile
	$(call mkdir,$(LOG_DIR))
	$(call mkdir,$(dir $@))
	$(call norminette,$<)
	$(CC) $(CFLAGS) $(addprefix -I,$(HEADERS_DIR) $(SUBLIBS_INC_DIR)) -c $< -o $@ 2> $(LOG_DIR)/error.log || true
	$(call print_result,$<)
$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.c $(SUBLIBS_RELEASE) $(HEADERS_FILES) Makefile
	$(call mkdir,$(LOG_DIR))
	$(call mkdir,$(dir $@))
	$(call norminette,$<)
	$(CC) $(CFLAGS) $(addprefix -I,$(HEADERS_DIR) $(SUBLIBS_INC_DIR)) -c $< -o $@ 2> $(LOG_DIR)/error.log || true
	$(call print_result,$<)

%_debug.a:
	$(call call_libs,debug)
%_release.a:
	$(call call_libs,release)
%.a:
	$(call call_libs,)