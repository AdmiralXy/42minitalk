CC = gcc
INC = .
INCLUDES = ft_minitalk.h
CFLAGS = -Wall -Wextra -Werror

CLIENT_NAME = client
SERVER_NAME = server

SRCS_CLIENT = ft_client.c ft_utils.c ft_atoi.c
SRCS_SERVER = ft_server.c ft_utils.c ft_atoi.c

OBJS_CLIENT = $(SRCS_CLIENT:%.c=%.o)
OBJS_SERVER = $(SRCS_SERVER:%.c=%.o)

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

build: $(OBJS_CLIENT) $(OBJS_SERVER) $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(OBJS_CLIENT)
	$(CC) -o $(CLIENT_NAME) $(OBJS_CLIENT) $(CFLAGS) -I$(INC)

$(SERVER_NAME): $(OBJS_SERVER)
	$(CC) -o $(SERVER_NAME) $(OBJS_SERVER) $(CFLAGS) -I$(INC)

all: $(CLIENT_NAME) $(SERVER_NAME)

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	$(RM) $(CLIENT_NAME) $(SERVER_NAME)

re: clean all

norme:
	norminette $(SRCS_CLIENT) $(SRCS_SERVER) $(INCLUDES)

bonus: build

.PHONY: build
