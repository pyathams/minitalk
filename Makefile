SERVER = server 
CLIENT = client

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRCS_SERVER = server.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: ${SERVER} ${CLIENT}

${SERVER} : ${OBJS_SERVER}
	${CC} ${CFLAGS} -o ${SERVER} ${OBJS_SERVER}

${CLIENT}: ${OBJS_CLIENT}
	${CC} ${CFLAGS} -o ${CLIENT} ${OBJS_CLIENT}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS_SERVER} ${OBJS_CLIENT}

fclean: clean
	${RM} ${SERVER} ${CLIENT}

re: fclean all


