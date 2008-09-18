#
# Mime Type Zia module
#

PATH_BIN	=	../..
PATH_SRC	=	../src
PATH_INCLUDE	=	.
PATH_LIBRARY	=	.
PATH_API	=	../../../api

NAME		=	$(PATH_BIN)/mod_mime.so

SRCS		=	$(PATH_SRC)/Mime.cpp			\
			$(PATH_SRC)/../../../src/FluxString.cpp	\
			$(PATH_SRC)/../../../src/Consumer.cpp	\
			$(PATH_SRC)/../../../src/URIParser.cpp	\
			$(PATH_SRC)/../../../src/XmlParser.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
RM		=	rm -f

INCLUDES	+=	-I$(PATH_INCLUDE) -I$(PATH_API) -I../../../src `xml2-config --cflags`
LIBRARIES	+=	-L$(PATH_LIBRARY) `xml2-config --libs`

DEBUG_42	=	-g -DDEBUG
COMPAT		+=	-D__BSD_VISIBLE
WARNINGS	+=	-W -Wall -Werror

CFLAGS		+=	$(INCLUDES) $(DEBUG_$(DEBUG)) $(COMPAT) $(WARNINGS)
LDFLAGS		+=	$(LIBRARIES)

.SUFFIXES	:	.cpp.o

$(NAME)		:	$(OBJS)
			$(CXX) -o $@ -shared $(OBJS) $(LDFLAGS)

all		:	$(NAME)

clean		:
			-$(RM) $(PATH_SRC)/*~
			-$(RM) $(PATH_SRC)/*.o
			-$(RM) *.core

fclean		:	clean
			-$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

.cpp.o		:
			$(CXX) $(CFLAGS) -c $< -o $@
