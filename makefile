# PROG DEFINITION

NAME		= philo

SRC			= philo.c parse.c utils.c exit.c threads_utils.c utils_time.c

SRC_PATH	= $(addprefix src/, $(SRC))
OBJS		= ${SRC_PATH:.c=.o}
HEADER		= -Iheader
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
RM			= rm -rf

# COLOUR DEFINITION #
RED     := \033[0;31m
BLUE    := \033[0;34m
GREEN   := \033[1;32m
WHITE   := \033[0;37m
RESET   := \033[0m

# DEBUG DEFINITION

ifdef DEBUG
    CFLAGS += -g3 -fsanitize=address
else
    CFLAGS += -O3
endif

# BUILDS

.c.o:		%.o : %.c
					@${CC} ${CFLAGS} ${HEADER} -c $< -o $(<:.c=.o)

all:		${NAME}

${NAME}:	${OBJS}
					@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
					@echo "${GREEN}<---> Philosophers Compiled! ⌐(ಠ۾ಠ)¬ <--->${RESET}"

clean:
					@${RM} ${OBJS}

fclean:		clean
					@${RM} ${NAME}
					@echo "$(GREEN)<==========> ALL REMOVED <==========>${RESET}"

re:			fclean all

.PHONY: clean all fclean re