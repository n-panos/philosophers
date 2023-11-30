# PROG DEFINITION

NAME		= philo
CC			= gcc
RM			= rm -rf

DEBUG		= -ggdb -g3
SANITIZE	= -fsanitize=address
BUILD_PATH	= build
MKDIR		= mkdir $(BUILD_PATH)
MOVE		= mv $(OBJS) $(BUILD_PATH)

SRC			= exit.c init.c parse.c philo.c routine.c threads.c utils_time.c utils.c
SRC_PATH	= $(addprefix src/, $(SRC))

HEADER		= -Iheader
CFLAGS		= -Werror -Wall -Wextra

OBJS		= $(SRC_PATH:.c=.o)
MOVE_OBJS	= $(SRC:.c=.o)
MOVE_OBJS_P	= $(addprefix build/, $(MOVE_OBJS))

# COLOUR DEFINITION #
RED     := \033[0;31m
BLUE    := \033[0;34m
GREEN   := \033[1;32m
WHITE   := \033[0;37m
RESET   := \033[0m

# BUILDS

all:		$(NAME)

.c.o:	%.o : %.c
	$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		$(MKDIR)
		$(MOVE)
		$(CC) $(CFLAGS) $(MOVE_OBJS_P) -o $@
		@echo "$(GREEN)<---> Philosophers Compiled! ⌐(ಠ۾ಠ)¬ <--->$(RESET)"

debug:	CFLAGS	+= $(DEBUG) $(SANITIZE)
debug:	re

clean:
		$(RM) $(OBJS)
		$(RM) $(BUILD_PATH)

fclean:	clean
	$(RM) $(NAME)
	@echo "$(GREEN)<==========> ALL REMOVED <==========>$(RESET)"

re:		fclean all

.PHONY: clean all fclean re