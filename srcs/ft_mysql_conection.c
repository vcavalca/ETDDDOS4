#include "../incl/ft_lib.h"

static char		*g_host = "";
static char		*g_user = "";
static char		*g_pass = "";
unsigned int	g_port = 3306;
static char		*g_unix_socket = NULL;
unsigned int	g_flag = 0;

void	*ft_connect_db(MYSQL *conn)
{
	if (!(mysql_real_connect(conn, g_host, g_user, g_pass,
				NULL, g_port, g_unix_socket, g_flag)))
	{
		fprintf(stderr, "\nError: %s [%d]\n",
			mysql_error(conn), mysql_errno(conn));
		exit(1);
	}
	return (EXIT_SUCCESS);
}
