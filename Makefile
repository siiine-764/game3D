NAME	:= Game3D
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include 
LIBS	:= $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
SRCS	:= main.c\
			./libft/ft_isalpha.c\
			./libft/ft_isdigit.c\
			./libft/ft_isalnum.c\
			./libft/ft_isascii.c\
			./libft/ft_isprint.c\
			./libft/ft_strlen.c\
			./libft/ft_memset.c\
			./libft/ft_bzero.c\
			./libft/ft_memcpy.c\
			./libft/ft_atoi.c\
			./libft/ft_strlcpy.c\
			./libft/ft_memcmp.c\
			./libft/ft_strnstr.c\
			./libft/ft_toupper.c\
			./libft/ft_tolower.c\
			./libft/ft_strchr.c\
			./libft/ft_strncmp.c\
			./libft/ft_memchr.c\
			./libft/ft_memmove.c\
			./libft/ft_putnbr_fd.c\
			./libft/ft_strlcat.c\
			./libft/ft_strrchr.c\
			./libft/ft_strdup.c\
			./libft/ft_strmapi.c\
			./libft/ft_strjoin.c\
			./libft/ft_striteri.c\
			./libft/ft_substr.c\
			./libft/ft_strtrim.c\
			./libft/ft_split.c\
			./libft/ft_itoa.c\
			./libft/ft_putchar_fd.c\
			./libft/ft_putstr_fd.c\
			./libft/ft_putendl_fd.c\
			./libft/ft_lstadd_front_bonus.c\
			./libft/ft_lstnew_bonus.c\
			./libft/ft_lstsize_bonus.c\
			./libft/ft_lstlast_bonus.c\
			./libft/ft_lstadd_back_bonus.c\
			./libft/ft_lstdelone_bonus.c\
			./libft/ft_lstclear_bonus.c\
			./libft/ft_lstiter_bonus.c\
			./get_next_line/get_next_line.c\
			./get_next_line/get_next_line_utils.c\
			./raycasting/ray_casting.c\
			./raycasting/movement.c\
			./raycasting/draw_game.c\
			./raycasting/player.c\
			./raycasting/ft_init.c\
			./parsing/parse_color.c\
			./parsing/parse_map.c\
			./parsing/parse_texture.c\
			./parsing/parse_utils.c\
			./parsing/parse_utils1.c\
			./parsing/parse_utils2.c\
			./parsing/map_reader.c\

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -fsanitize=address -g

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re