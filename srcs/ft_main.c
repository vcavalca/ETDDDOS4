#include "../incl/ft_lib.h" 

int	main(void)
{
	MYSQL	*con;
	char	db_name[25];
	char	table_name[25];
	int		menu;
	char	name_collum[255];
	char	value_collum[255];
	char	id[255];

	printf("----- Menu -----\n");
	printf("MySQL client version: %s\n", mysql_get_client_info());
	printf("1 - Cria um novo banco de dados\n");
	printf("2 - Deleta um banco de dados\n");
	printf("3 - Cria uma tabela fixa para o banco de dados com nome e preço\n");
	printf("4 - Para entrar com valores na tabela\n");
	printf("----------------\n\n");
	con = mysql_init(NULL);
	printf("Digite a opção desejada: \n");
	scanf("%d", &menu);
	switch (menu)
	{
		case 1:
			printf("Digite um nome que deseja para o nome da database: ");
		scanf("%s", db_name);
		ft_create_db(con, db_name);
		break ;
		case 2:
			printf("Digite o nome da database que deseja deletar: ");
		scanf("%s", db_name);
		ft_delete_db(con, db_name);
		break ;
		case 3:
			printf("Digite o nome da Database desejada para criar a tabela: ");
		scanf("%s", db_name);
		printf("Digite o nome da Tabela desejada: ");
		scanf("%s", table_name);
		ft_create_table(con, db_name, table_name);
		break ;
		case 4:
			printf("Digite o nome da database desejada para inserir os valores: ");
		scanf("%s", db_name);
		printf("Digite o nome da tabela: ");
		scanf("%s", table_name);
		printf("Digite o id desejado: ");
		scanf("%s", id);
		printf("Digite o nome desejado: ");
		scanf("%s", name_collum);
		printf("Digite o preço desejado: ");
		scanf("%s", value_collum);
		ft_insert_into(con, db_name, table_name, id, name_collum, value_collum);
		default :
			break ;
	}
	mysql_close(con);
	return (0);
}
