##
## Makefile for Zia in /home/armand_m/zia/proto/unix
## 
## Made by morgan armand
## Login   <armand_m@epitech.net>
## 
## Started on  Tue Jul 29 11:41:07 2008 morgan armand
## Last update Sat Aug  2 11:19:59 2008 majdi toumi
##

# Binary:
NAME		=	zia

# Sources:
SRC		=	../src/main.cpp			\
			../src/Logger.cpp		\
			../src/Socket.cpp		\
			../src/Thread.cpp		\
			../src/ServerSocket.cpp		\
			../src/HttpRequest.cpp		\
			../src/HttpProducer.cpp		\
			../src/HttpConsumer.cpp		\
			../src/HttpParser.cpp
#			../src/XmlDomConfig.cpp

# Objects:
OBJ		=	$(SRC:.cpp=.o)

# Includes:
INCS		=	-I../src `xml2-config --cflags`

# Libraries:
LIBS		=	-lpthread `xml2-config --libs`

# Tools:
CXX		=	g++
RM		=	rm
DEBUG		=	-g
WARNINGS	+=	-Wall
WARNINGS	+=	-Werror

CFLAGS		+=	$(WARNINGS) $(INCS)
LDFLAGS		+=	$(LIBS)

# Rules:
all		:
			make $(NAME)

$(NAME)		:	$(OBJ)
			$(CXX) -o $(NAME) *.o $(LDFLAGS)

clean		:
			-$(RM) -f *.o #$(OBJ)
			-$(RM) -f *~

fclean		:	clean
			-$(RM) -f $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
.SUFFIXES	:	.cppo