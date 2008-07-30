##
## Makefile for Zia in /home/armand_m/zia/proto/unix
## 
## Made by morgan armand
## Login   <armand_m@epitech.net>
## 
## Started on  Tue Jul 29 11:41:07 2008 morgan armand
## Last update Wed Jul 30 17:15:20 2008 morgan armand
##

NAME	=	zia

##
# Sources
##

SRC	=	../src/main.cpp			\
		../src/Logger.cpp		\
		../src/Socket.cpp		\
		../src/ServerSocket.cpp		\
		../src/HttpRequest.cpp		\
		../src/HttpProducer.cpp		\
		../src/HttpParser.cpp

OBJ	=	$(SRC:.cpp=.o)

##
# Tools
##

CXX	=	g++
RM	=	rm

CFLAGS	=	-Wall -Werror
LIBS	=	-lpthread

##
# Rules
##

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) *.o $(LIBS) #$(OBJ)

all:		$(NAME)

clean:
		-$(RM) -f *.o #$(OBJ)
		-$(RM) -f *~

fclean:		clean
		-$(RM) -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
