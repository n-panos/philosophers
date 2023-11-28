# PROG DEFINITION

NAME		= philo
CC			= gcc
RM			= rm -rf

DEBUG		= -ggdb -g3
SANITIZE	= -fsanitize=address

SRC			= philo.c init_philos.c parse.c exit.c threads.c utils_time.c utils.c
SRC_PATH	= $(addprefix src/, $(SRC))

HEADER		= -Iheader
CFLAGS		= -Werror -Wall -Wextra

OBJS		= $(SRC_PATH:.c=.o)

# COLOUR DEFINITION #
RED     := \033[0;31m
BLUE    := \033[0;34m
GREEN   := \033[1;32m
WHITE   := \033[0;37m
RESET   := \033[0m

# BUILDS

all:		$(NAME)

.c.o:	%.o : %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
		@$(CC) $(CFLAGS) $^ -o $@
		@echo "$(GREEN)<---> Philosophers Compiled! ⌐(ಠ۾ಠ)¬ <--->$(RESET)"

debug:	CFLAGS	+= $(DEBUG) $(SANITIZE)
debug:	re

clean:
		@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)
	@echo "$(GREEN)<==========> ALL REMOVED <==========>$(RESET)"

re:		fclean all

.PHONY: clean all fclean re