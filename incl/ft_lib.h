#ifndef FT_LIB_H
# define FT_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mysql/mysql.h>

# define HOST "mysqlserver.cxowujov80g4.sa-east-1.rds.amazonaws.com"
# define USER "admin"
# define PASS "12345678"
# define PORT 3306
# define SOCKET NULL
# define FLAG 0

# define CREATEDB "CREATE DATABASE "
# define DROPDB "DROP DATABASE "
# define CREATTABLE "CREATE TABLE "
# define DROPTABLE "DROP TABLE IF EXISTS "
# define INSERTINTO "INSERT INTO "
# define SELECTFROM "SELECT * FROM "
# define UPDATETABLE "UPDATE "
# define DELETEINFO "DELETE FROM "

void	*ft_create_db(MYSQL *con, char *db_name);
void	ft_finish_with_error(MYSQL *con);
void	*ft_delete_db(MYSQL *con, char *db_name);
void	*ft_create_table(MYSQL *con, char *db_name, char *table_name);
void	*ft_insert_into(MYSQL *con, char *db_name, char *table_name, char *id, char *name_collum, char *value_collum);
void	*ft_read_info(MYSQL *con, char *db_name, char *table_name);
void	*ft_update_table(MYSQL *con, char *db_name, char *table_name, char *id, char *name_collum, char *value_collum);
void	*ft_delete_line(MYSQL *con, char *db_name, char *table_name, char *id);

char	*ft_strjoin(char const *s1, char const *s2);

#endif