NAME		=	mod_perl.so

SRCS		=	Perl.cpp
OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
RM		=	rm -f

WARNING		+=	-W -Wall -Werror

INCLUDES_XML	=	`xml2-config --cflags`
LIBRARY_XML	=	`xml2-config --libs`

INCLUDES	+=	-I. -I../../src $(INCLUDES_XML)

CFLAGS		+=	$(WARNING) $(INCLUDES)

$(NAME)		:	$(OBJS)
			$(CXX) -o $@ -shared $(OBJS)

all		:	$(NAME)

clean		:
			$(RM) *~ *.o

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
