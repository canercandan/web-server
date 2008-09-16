##
## Makefile for MyModule in /home/candan_c/cu/rendu/zia/renewal/modules/MyModule
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Thu Sep 11 15:38:38 2008 caner candan
## Last update Mon Sep 15 20:56:57 2008 morgan armand
##

NAME		=	../mod_ssl.so

PATH_SRCS	=	.
PATH_INTERFACE	=	../../api

SRCS		=	$(PATH_SRCS)/Ssl.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXX		=	g++
RM		=	rm -f

WARNING		+=	-W -Wall -Werror

INCLUDES	+=	-I$(PATH_SRCS) -I$(PATH_INTERFACE)
LIBRARIES	+=	-lssl

CFLAGS		+=	$(WARNING) $(INCLUDES)

.SUFFIXES	:	.cpp.o

$(NAME)		:	$(OBJS)
			$(CXX) -o $@ -shared $(OBJS) $(LIBRARIES)

all		:	$(NAME)

clean		:
			$(RM) *~ *.o

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re

.cpp.o		:
			$(CXX) $(CFLAGS) -c $< -o $@
