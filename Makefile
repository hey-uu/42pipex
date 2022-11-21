# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 17:02:57 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/22 00:08:33 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

include config/variables_definition.mk

$(NAME) : $(OBJ) $(INC)
	make -C $(LIB_DIR) gnl
	$(CC) $(CFLAGS) $(OBJ) $(LIB) -o $@ 

.PHONY : all bonus
all : $(NAME)

bonus : 
	make WITH_BONUS=1 all

include config/compile_rules.mk

.PHONY : clean fclean re
clean :
	make -C $(LIB_DIR) fclean
	$(RM) $(RMFLAGS) $(OBJ_DIR)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re :
	make fclean
	make all