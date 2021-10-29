#include "../incl/ft_lib.h"

void	*ft_update_table(MYSQL *con, char *db_name, char *table_name, char *id, char *name_collum, char *value_collum)
{
	char	*query;

	if (mysql_real_connect(con, HOST, USER, PASS,
			db_name, PORT, SOCKET, FLAG) == NULL)
	{
		ft_finish_with_error(con);
	}
	query = ft_strjoin(UPDATETABLE, table_name);
	query = ft_strjoin(query, " SET ");
	query = ft_strjoin(query, "nome = '");
	query = ft_strjoin(query, name_collum);
	query = ft_strjoin(query, "', ");
	query = ft_strjoin(query, "preco = '");
	query = ft_strjoin(query, value_collum);
	query = ft_strjoin(query, "' WHERE id = ");
	query = ft_strjoin(query, id);
	if (mysql_query(con, query))
	{
		ft_finish_with_error(con);
	}
	printf("Successfully updated\n");
	return (EXIT_SUCCESS);
}

void	*ft_delete_line(MYSQL *con, char *db_name, char *table_name, char *id)
{
	char	*query;

	if (mysql_real_connect(con, HOST, USER, PASS,
			db_name, PORT, SOCKET, FLAG) == NULL)
	{
		ft_finish_with_error(con);
	}
	query = ft_strjoin(DELETEINFO, table_name);
	query = ft_strjoin(query, " WHERE id = ");
	query = ft_strjoin(query, id);
	if (mysql_query(con, query))
	{
		ft_finish_with_error(con);
	}
	printf("Successfully deleted line\n");
	return (EXIT_SUCCESS);
}
