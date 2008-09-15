NAME		=	../../mod_autoindex.so

PATH_SRCS	=	../src
PATH_INTERFACE	=	../../../interface

SRCS		=	$(PATH_SRCS)/AutoIndex.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
RM		=	rm -f

WARNING		+=	-W -Wall -Werror

INCLUDES	+=	-I$(PATH_SRCS) -I$(PATH_INTERFACE)

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
