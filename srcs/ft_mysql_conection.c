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
	printf("Database created successfully\n");
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
	printf("Database successfully deleted\n");
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
	printf("Table created successfully\n");
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
	printf("Successfully inserted\n");
	return (EXIT_SUCCESS);
}

void	*ft_read_info(MYSQL *con, char *db_name, char *table_name)
{
	char		*query;
	MYSQL_RES	*result;
	int			num_fields;
	MYSQL_ROW	row;

	if (mysql_real_connect(con, HOST, USER, PASS,
			db_name, PORT, NULL, 0) == NULL)
	{
		ft_finish_with_error(con);
	}
	query = ft_strjoin(SELECTFROM, table_name);
	if (mysql_query(con, query))
	{
		ft_finish_with_error(con);
	}
	result = mysql_store_result(con);
	if (result == NULL)
	{
		ft_finish_with_error(con);
	}
	num_fields = mysql_num_fields(result);
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s", row[i] ? row[i] : "NULL");
		}
		printf("\n");
	}
	mysql_free_result(result);
	return (EXIT_SUCCESS);
}
