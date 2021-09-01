CC = gcc
INC = .
INCLUDES = push_swap.h
CFLAGS = -Wall -Wextra -Werror

CLIENT_NAME = client
SERVER_NAME = server

SRCS_CLIENT = ft_client.c
SRCS_SERVER = ft_client.c

OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)
OBJS_SERVER = $(SRCS_SERVER:%.c=%.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -Ilibft

$(CLIENT_NAME): $(OBJS_CLIENT)
	@make -C libft
	$(CC) -o $(CLIENT_NAME) $(OBJS_CLIENT) $(CFLAGS) -I$(INC) libft/libft.a

$(SERVER_NAME): $(OBJS_SERVER)
	@make -C libft
	$(CC) -o $(SERVER_NAME) $(OBJS_SERVER) $(CFLAGS) -I$(INC) libft/libft.a

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	@make -C libft clean
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@make -C libft fclean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: clean all

norme:
	norminette libft/*.c libft/*.h
	norminette $(SRCS_CLIENT) $(SRCS_SERVER) $(INCLUDES)
