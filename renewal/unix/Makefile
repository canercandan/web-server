#
# Zia HTTP Server
# makefile
#

PATH_BIN	=	.
PATH_SRC	=	../src
PATH_INCLUDE	=	.
PATH_LIBRARY	=	.
PATH_API	=	../api

NAME		=	$(PATH_BIN)/zia

SRCS		=	$(PATH_SRC)/main.cpp		\
			$(PATH_SRC)/Client.cpp		\
			$(PATH_SRC)/Config.cpp		\
			$(PATH_SRC)/ConnectionInfos.cpp	\
			$(PATH_SRC)/Consumer.cpp	\
			$(PATH_SRC)/FileInfo.cpp	\
			$(PATH_SRC)/FluxClient.cpp	\
			$(PATH_SRC)/FluxString.cpp	\
			$(PATH_SRC)/HookManager.cpp	\
			$(PATH_SRC)/HttpParser.cpp	\
			$(PATH_SRC)/Logger.cpp		\
			$(PATH_SRC)/Message.cpp		\
			$(PATH_SRC)/Request.cpp		\
			$(PATH_SRC)/Response.cpp	\
			$(PATH_SRC)/Server.cpp		\
			$(PATH_SRC)/ServerSocket.cpp	\
			$(PATH_SRC)/ServerState.cpp	\
			$(PATH_SRC)/Signal.cpp		\
			$(PATH_SRC)/Socket.cpp		\
			$(PATH_SRC)/Thread.cpp		\
			$(PATH_SRC)/Tools.cpp		\
			$(PATH_SRC)/URIParser.cpp	\
			$(PATH_SRC)/XmlParser.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
RM		=	rm -f

INCLUDES	+=	-I$(PATH_INCLUDE) -I$(PATH_API) `xml2-config --cflags`
LIBRARIES	+=	-L$(PATH_LIBRARY) `xml2-config --libs` -lpthread

DEBUG_42	=	-g -DDEBUG
COMPAT		+=	-D__BSD_VISIBLE
WARNINGS	+=	-W -Wall -Werror

CFLAGS		+=	$(INCLUDES) $(DEBUG_$(DEBUG)) $(COMPAT) $(WARNINGS)
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
