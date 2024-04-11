NAME = libft.a
DNAME = d_libft.a
RNAME = r_libft.a
SRC = 	ft_isalpha.c		\
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
SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
HEADERS = $(NAME:.a=.h)
HEADERS_DIR = .
HEADERS_FILES = $(addprefix $(HEADERS_DIR)/, $(HEADERS))
SRC_DIR = .
OBJ_DIR = build/normal
DEBUG_DIR = build/debug
RELEASE_DIR = build/release
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))
DEBUG_OBJ = $(patsubst $(SRC_DIR)/%.c,$(DEBUG_DIR)/%.o,$(SRC_FILES))
RELEASE_OBJ = $(patsubst $(SRC_DIR)/%.c,$(RELEASE_DIR)/%.o,$(SRC_FILES))
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS = -g3 -fsanitize=address
RELEASEFLAGS = -O3

all:
	@$(MAKE) --no-print-directory -j normal
	@$(MAKE) --no-print-directory -j debug
	@$(MAKE) --no-print-directory -j release

normal: $(OBJ_DIR) $(NAME)

debug: CFLAGS += $(DEBUGFLAGS)
debug: $(DEBUG_DIR) $(DNAME)

release: CFLAGS += $(RELEASEFLAGS)
release: $(RELEASE_DIR) $(RNAME)

$(NAME): $(OBJ)
	ar rcs $@ $^
#	$(CC) $(CFLAGS) -o $@ $^

$(DNAME): $(DEBUG_OBJ)
	ar rcs $@ $^
#	$(CC) $(CFLAGS) -o $@ $^

$(RNAME): $(RELEASE_OBJ)
	norminette $(HEADERS_FILES)
	ar rcs $@ $^
#	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c -o $@ $<

$(DEBUG_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(RELEASE_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS_FILES)
	norminette $<
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(DEBUG_DIR) $(RELEASE_DIR)
	if [ -d `dirname $(OBJ_DIR)` ]; then \
		rmdir -p `dirname $(OBJ_DIR)`; \
	fi

fclean: clean
	rm -f $(NAME) $(DNAME) $(RNAME)

re: fclean all

.PHONY: all clean fclean re debug release
