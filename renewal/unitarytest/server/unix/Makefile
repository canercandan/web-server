PATH_BIN	=	.
PATH_SRC	=	../src
PATH_INCLUDE	=	.
PATH_LIBRARY	=	.
PATH_ZIA_SRC	=	../../../src
PATH_ZIA_API	=	../../../api

NAME		=	$(PATH_BIN)/unitary_server

SRCS		=	$(PATH_SRC)/main.cpp			\
			$(PATH_SRC)/ConfigParameter.cpp		\
			$(PATH_SRC)/XmlParserGetter.cpp		\
			$(PATH_SRC)/FileInfoTestFile.cpp	\
			$(PATH_SRC)/FileInfoTestDirectory.cpp	\
			$(PATH_SRC)/FluxStringTest.cpp		\
			$(PATH_ZIA_SRC)/Client.cpp		\
			$(PATH_ZIA_SRC)/Config.cpp		\
			$(PATH_ZIA_SRC)/ConnectionInfos.cpp	\
			$(PATH_ZIA_SRC)/Consumer.cpp		\
			$(PATH_ZIA_SRC)/FileInfo.cpp		\
			$(PATH_ZIA_SRC)/FluxClient.cpp		\
			$(PATH_ZIA_SRC)/FluxString.cpp		\
			$(PATH_ZIA_SRC)/HookManager.cpp		\
			$(PATH_ZIA_SRC)/HttpParser.cpp		\
			$(PATH_ZIA_SRC)/Logger.cpp		\
			$(PATH_ZIA_SRC)/Message.cpp		\
			$(PATH_ZIA_SRC)/Request.cpp		\
			$(PATH_ZIA_SRC)/Response.cpp		\
			$(PATH_ZIA_SRC)/Server.cpp		\
			$(PATH_ZIA_SRC)/ServerSocket.cpp	\
			$(PATH_ZIA_SRC)/ServerState.cpp		\
			$(PATH_ZIA_SRC)/Signal.cpp		\
			$(PATH_ZIA_SRC)/Socket.cpp		\
			$(PATH_ZIA_SRC)/Thread.cpp		\
			$(PATH_ZIA_SRC)/Tools.cpp		\
			$(PATH_ZIA_SRC)/URIParser.cpp		\
			$(PATH_ZIA_SRC)/XmlParser.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
RM		=	rm -f

CPPUNIT_INCLUDE	=	`cppunit-config --cflags`
CPPUNIT_LIBRARY	=	`cppunit-config --libs`

INCLUDES	+=	-I$(PATH_INCLUDE) $(CPPUNIT_INCLUDE) -I$(PATH_ZIA_SRC)	\
			-I$(PATH_ZIA_API) `xml2-config --cflags`
LIBRARIES	+=	-L$(PATH_LIBRARY) $(CPPUNIT_LIBRARY) `xml2-config --libs` -lpthread

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
