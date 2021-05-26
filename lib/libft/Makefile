SRCDIR	= srcs

SRCS	= $(shell find $(SRCDIR) -name '*.c' -a -not -name '*_bonus.c')

SRCS_B	= $(shell find $(SRCDIR) -name '*_bonus.c')

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

NO_COLOR=\x1b[0m

BOLD_COLOR=\x1b[1m

OK_COLOR=\x1b[32;01m

ERROR_COLOR=\x1b[31;01m

WARN_COLOR=\x1b[33;01m

.c.o:
	@/bin/echo -n "Compiling $<"
	@gcc ${CFLAGS} -I./includes/ -c $< -o ${<:.c=.o}
	@echo " - ${BOLD_COLOR}${OK_COLOR}OK${NO_COLOR}"

$(NAME):	${OBJS}
	@echo "${WARN_COLOR}Making ${NAME}${NO_COLOR}"
	@ar rc ${NAME} ${OBJS}
	@echo "${BOLD_COLOR}${OK_COLOR}Done.${NO_COLOR}"

bonus:		fclean ${OBJS} ${OBJS_B} ${NAME}

all:		${NAME}

clean:
	${RM} ${OBJS} ${OBJS_B}

fclean:		clean
	${RM} ${NAME}

re:			fclean all
