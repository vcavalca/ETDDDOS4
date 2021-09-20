#ifndef FT_LIB_H
# define FT_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <mysql/mysql.h>

void	*ft_connect_db(MYSQL *conn);

#endif