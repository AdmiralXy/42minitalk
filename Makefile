CC = gcc
INC = .
INCLUDES = push_swap.h
CFLAGS = -Wall -Wextra -Werror

CLIENT_NAME = client
SERVER_NAME = server
SRCS =

OBJS = $(SRCS:%.c=%.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -Ilibft

$(CLIENT_NAME): $(OBJS)
	@make -C libft
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -I$(INC) libft/libft.a

$(SERVER_NAME): $(OBJS)
	@make -C libft
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) -I$(INC) libft/libft.a

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	@make -C libft clean
	$(RM) $(OBJS)

fclean: clean
	@make -C libft fclean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: clean all

norme:
	norminette libft/*.c libft/*.h
	norminette $(SRCS) $(INCLUDES)
