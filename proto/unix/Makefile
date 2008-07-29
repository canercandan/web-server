##
## Makefile for Zia in /home/armand_m/zia/proto/unix
## 
## Made by morgan armand
## Login   <armand_m@epitech.net>
## 
## Started on  Tue Jul 29 11:41:07 2008 morgan armand
## Last update Tue Jul 29 11:51:17 2008 morgan armand
##

NAME	=	zia

##
# Sources
##

SRC	=	../src/main.cpp

OBJ	=	$(SRC:.cpp=.o)

##
# Tools
##

CXX	=	g++
RM	=	rm

CFLAGS	=	-Wall -Werror

##
# Rules
##

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		-$(RM) -f $(OBJ)
		-$(RM) -f *~

fclean:		clean
		-$(RM) -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
