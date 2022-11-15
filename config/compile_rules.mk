# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 01:41:53 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/16 01:55:37 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(OBJ_DIR)/$(MAN_DIR)/%.o : $(SRC_DIR)/$(MAN_DIR)/%.c $(INC_DIR)/$(MAN_DIR)/%.h
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(MAN_DIR)
	$(CC) -c $(CFLAGS) $< -I$(INC_DIR)/$(MAN_DIR) -I$(LIBFT_INC_DIR) -o $@

$(OBJ_DIR)/$(BON_DIR)/%.o : $(SRC_DIR)/$(BON_DIR)/%.c $(INC_DIR)/$(BON_DIR)/%.h
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/$(BON_DIR)
	$(CC) -c $(CFLAGS) $< -I$(INC_DIR)/$(BON_DIR) -I$(LIBFT_INC_DIR) -o $@