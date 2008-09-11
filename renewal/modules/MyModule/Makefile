##
## Makefile for MyModule in /home/candan_c/cu/rendu/zia/renewal/modules/MyModule
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Thu Sep 11 15:38:38 2008 caner candan
## Last update Thu Sep 11 15:38:38 2008 caner candan
##

NAME		=	../mod_mymodule.so

PATH_SRCS	=	.
PATH_INTERFACE	=	../../api

SRCS		=	$(PATH_SRCS)/MyModule.cpp

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
