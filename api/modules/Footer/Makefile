NAME		=	../mod_footer.so

PATH_SRCS	=	../../src
PATH_INTERFACE	=	../../interface

SRCS		=	Footer.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
RM		=	rm -f

WARNING		+=	-W -Wall -Werror

INCLUDES	+=	-I. -I$(PATH_SRCS) -I$(PATH_INTERFACE)

CFLAGS		+=	$(WARNING) $(INCLUDES)

.SUFFIXES	:	.cpp.o

$(NAME)		:	$(OBJS)
			$(CXX) -o $@ -shared $(OBJS)

all		:	$(NAME)

clean		:
			$(RM) *~ *.o

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

.cpp.o		:
			$(CXX) $(CFLAGS) -c $< -o $@
