#include "../incl/ft_lib.h"

void	*ft_create_db(MYSQL *con, char *db_name)
{
	char	*query;

	if (mysql_real_connect(con, HOST, USER, PASS,
			NULL, PORT, SOCKET, FLAG) == NULL)
	{
		ft_finish_with_error(con);
	}
	query = ft_strjoin(CREATEDB, db_name);
	if (mysql_query(con, query))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("Criada com sucesso\n");
	return (EXIT_SUCCESS);
}

void	*ft_delete_db(MYSQL *con, char *db_name)
{
	char	*query;

	if (mysql_real_connect(con, HOST, USER, PASS,
			NULL, PORT, SOCKET, FLAG) == NULL)
	{
		ft_finish_with_error(con);
	}
	query = ft_strjoin(DROPDB, db_name);
	if (mysql_query(con, query))
	{
		fprintf(stderr, "%s\n", mysql_error(con));
		mysql_close(con);
		exit(1);
	}
	printf("Deletada com sucesso\n");
	return (EXIT_SUCCESS);
}

void	*ft_create_table(MYSQL *con, char *db_name, char *table_name)
{
	char	*check_table;
	char	*query;

	if (mysql_real_connect(con, HOST, USER, PASS,
			db_name, PORT, SOCKET, FLAG) == NULL)
	{
		ft_finish_with_error(con);
	}
	check_table = ft_strjoin(DROPTABLE, table_name);
	if (mysql_query(con, check_table))
	{
		ft_finish_with_error(con);
	}
	query = ft_strjoin(CREATTABLE, table_name);
	query = ft_strjoin(query, "(id INT PRIMARY KEY AUTO_INCREMENT, nome VARCHAR(255), preco INT)");
	if (mysql_query(con, query))
	{
		ft_finish_with_error(con);
	}
	printf("Tabela criada com sucesso\n");
	return (EXIT_SUCCESS);
}

void	*ft_insert_into(MYSQL *con, char *db_name, char *table_name, char *id, char *name_collum, char *value_collum)
{
	char	*query;

	if (mysql_real_connect(con, HOST, USER, PASS,
			db_name, PORT, SOCKET, FLAG) == NULL)
	{
		ft_finish_with_error(con);
	}
	query = ft_strjoin(INSERTINTO, table_name);
	query = ft_strjoin(query, " VALUES(");
	query = ft_strjoin(query, id);
	query = ft_strjoin(query, ",'");
	query = ft_strjoin(query, name_collum);
	query = ft_strjoin(query, "',");
	query = ft_strjoin(query, value_collum);
	query = ft_strjoin(query, ")");
	if (mysql_query(con, query))
	{
		ft_finish_with_error(con);
	}
	printf("Inserido com sucesso\n");
	return (EXIT_SUCCESS);
}
