##
## Makefile for Zia in /home/armand_m/zia/proto/unix
## 
## Made by morgan armand
## Login   <armand_m@epitech.net>
## 
## Started on  Tue Jul 29 11:41:07 2008 morgan armand
## Last update Wed Aug 13 20:54:22 2008 caner candan
##

NAME		=	zia

PATH_SRC	=	../src

SRCS		=	$(PATH_SRC)/main.cpp			\
			$(PATH_SRC)/ABNFParser.cpp		\
			$(PATH_SRC)/Client.cpp			\
			$(PATH_SRC)/HttpConsumer.cpp		\
			$(PATH_SRC)/HttpProducer.cpp		\
			$(PATH_SRC)/HttpRequest.cpp		\
			$(PATH_SRC)/HttpResponse.cpp		\
			$(PATH_SRC)/HttpParser.cpp		\
			$(PATH_SRC)/InfoFile.cpp		\
			$(PATH_SRC)/Logger.cpp			\
			$(PATH_SRC)/ParserXml.cpp		\
			$(PATH_SRC)/ServerSocket.cpp		\
			$(PATH_SRC)/Socket.cpp			\
			$(PATH_SRC)/Thread.cpp			\
			$(PATH_SRC)/URIParser.cpp		\
			$(PATH_SRC)/ZiaConfiguration.cpp

OBJS		=	$(SRCS:.cpp=.o)

INCLUDES_XML	=	`xml2-config --cflags`
LIBRARY_XML	=	`xml2-config --libs`

INCLUDES	+=	-I$(PATH_SRC) $(INCLUDES_XML)
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
