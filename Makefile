SRC_DIR=./
OBJ_DIR=./
SRCS=$(shell find ${SRC_DIR} -name "*.c")
OBJS=${patsubst ${SRC_DIR}/%,${OBJ_DIR}/%,${SRCS:.c=.o}}
CFLAGS=-Wall -Wextra -Werror -I.
CC=cc
AR=ar
AR_OPTS=-rc
RM=rm
RM_OPTS=-rf
MKDIR=mkdir -p
LIB_NAME=libftprintf.a

.PHONY: all lib so re clean fclean dclean

all: lib

bonus: all

lib: ${OBJS}
	${AR} ${AR_OPTS} ${LIB_NAME} ${OBJS}

${OBJS}: ${SRCS}
	${CC} ${CFLAGS} -c -o $@ ${patsubst ${OBJ_DIR}/%,${SRC_DIR}/%,${@:.o=.c}}

so: $(OBJS)
	${CC} -shared -o ${LIB_NAME:.a=.so} ${OBJS}

re: fclean lib

clean:
	${RM} ${RM_OPTS} ${OBJS}

fclean: clean
	${RM} ${RM_OPTS} ${LIB_NAME}

dclean: fclean
	${RM} ${RM_OPTS} ${OBJ_DIR}
