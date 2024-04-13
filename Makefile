NAME = libft.a
DNAME = d_libft.a
RNAME = r_libft.a
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
		ft_putnbr_fd.c
BONUS = ft_lstnew_bonus.c			\
		ft_lstadd_front_bonus.c		\
		ft_lstsize_bonus.c			\
		ft_lstlast_bonus.c			\
		ft_lstadd_back_bonus.c		\
		ft_lstdelone_bonus.c		\
		ft_lstclear_bonus.c			\
		ft_lstiter_bonus.c			\
		ft_lstmap_bonus.c
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
BONUS_FILES = $(addprefix $(SRC_DIR)/, $(BONUS))
HEADERS = $(NAME:.a=.h) $(NAME:.a=_bonus.h) 
HEADERS_DIR = .
HEADERS_FILES = $(addprefix $(HEADERS_DIR)/, $(HEADERS))
SRC_DIR = .
OBJ_DIR = build/normal
DEBUG_DIR = build/debug
RELEASE_DIR = build/release
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(BONUS_FILES))
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(SRC_FILES))
DEBUG_BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(BONUS_FILES))
RELEASE_OBJ = $(patsubst $(SRC_DIR)/%.c,$(RELEASE_DIR)/%.o,$(SRC_FILES))
RELEASE_BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c,$(RELEASE_DIR)/%.o,$(BONUS_FILES))
CC = clang
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcsu
DEBUGFLAGS = -g3 -fsanitize=address
RELEASEFLAGS = -O3


normal: $(OBJ_DIR) $(OBJ) #$(NAME)

bonus: $(OBJ_DIR) $(OBJ) $(BONUS_OBJ) #$(NAME)

all:
	@$(MAKE) --no-print-directory -j bonus
	@$(MAKE) --no-print-directory -j debug
	@$(MAKE) --no-print-directory -j release

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(DEBUG_DIR) $(DEBUG_BONUS_OBJ) #$(DNAME)

release: CFLAGS += $(RELEASEFLAGS)
release: $(RELEASE_DIR) $(RELEASE_BONUS_OBJ) #$(RNAME)



so: $(OBJ)
	$(CC) -nostartfiles -fPIC $(CFLAGS) $^
	$(CC) -nostartfiles -shared -o libft.so $^

# $(NAME): $(OBJ)
# 	ar rcs $@ $^
# #	$(CC) $(CFLAGS) -o $@ $^

# $(DNAME): $(DEBUG_OBJ)
# 	ar rcs $@ $^
# #	$(CC) $(CFLAGS) -o $@ $^

# $(RNAME): $(RELEASE_OBJ)
# 	norminette $(HEADERS_FILES)
# 	ar rcs $@ $^
#	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c -o $@ $<
	$(AR) $(ARFLAGS) $(NAME) $@

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@
	$(AR) $(ARFLAGS) $(DNAME) $@

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	norminette $<
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@
	$(AR) $(ARFLAGS) $(RNAME) $@

$(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR)
	if [ -d `dirname $(OBJ_DIR)` ]; then \
		rmdir -p `dirname $(OBJ_DIR)`; \
	fi

fclean: clean
	rm -f $(NAME) $(DNAME) $(RNAME) libft.so

re: fclean all

.PHONY: all clean fclean re debug release bonus so
