NAME		=	zia

PATH_SRC	=	../src
PATH_INTERFACE	=	../api

SRCS		=	$(PATH_SRC)/main.cpp			\
#			$(PATH_SRC)/Client.cpp			\
#			$(PATH_SRC)/Config.cpp			\
#			$(PATH_SRC)/Consumer.cpp		\
#			$(PATH_SRC)/FileInfo.cpp		\
#			$(PATH_SRC)/FluxClient.cpp		\
#			$(PATH_SRC)/HttpParser.cpp		\
#			$(PATH_SRC)/Logger.cpp			\
#			$(PATH_SRC)/Request.cpp			\
#			$(PATH_SRC)/Response.cpp		\
#			$(PATH_SRC)/ServerSocket.cpp		\
#			$(PATH_SRC)/Socket.cpp			\
#			$(PATH_SRC)/Thread.cpp			\
#			$(PATH_SRC)/URIParser.cpp		\
#			$(PATH_SRC)/XmlParser.cpp

OBJS		=	$(SRCS:.cpp=.o)

INCLUDES_XML	=	`xml2-config --cflags`
LIBRARY_XML	=	`xml2-config --libs`

INCLUDES	+=	-I$(PATH_SRC) -I$(PATH_INTERFACE) $(INCLUDES_XML)
LIBRARIES	+=	-lpthread $(LIBRARY_XML)

CXX		=	g++
RM		=	rm -f

DEBUG_42	=	-g

WARNINGS	+=	-W -Wall -Werror

CFLAGS		+=	$(WARNINGS) $(INCLUDES) $(DEBUG_$(DEBUG))
LDFLAGS		+=	$(LIBRARIES)

.SUFFIXES	:	.cpp.o

$(NAME)		:	$(OBJS)
			$(CXX) -o $@ $(OBJS) $(LDFLAGS)

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
