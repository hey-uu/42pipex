# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 01:41:53 by hyeyukim          #+#    #+#              #
#    Updated: 2022/11/14 01:52:44 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

$(OBJCS_DIR)/$(MAN_DIR)/%.o : $(MAN_DIR)/%.c
	mkdir -p $(OBJCS_DIR)
	mkdir -p $(OBJCS_DIR)/$(MAN_DIR)
	$(CC) -c $(CFLAGS) $^ -I$(INC_DIR) -I$(LIBFT_INC_DIR) -o $@

$(OBJCS_DIR)/$(BON_DIR)/%.o : $(BON_DIR)/%.c
	mkdir -p $(OBJCS_DIR)
	mkdir -p $(OBJCS_DIR)/$(BON_DIR)
	$(CC) -c $(CFLAGS) $^ -I$(INC_DIR) -I$(LIBFT_INC_DIR) -o $@