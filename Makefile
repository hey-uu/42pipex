# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 17:02:57 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/16 01:52:55 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(OBJ) $(INC)
	make -C $(LIB_DIR) gnl
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@ 

.PHONY : bonus
bonus : 
	make WITH_BONUS=1 all

include config/compile_rules.mk

.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all