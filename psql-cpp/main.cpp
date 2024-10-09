
#include <iostream>
#include "libpq-fe.h"
int main(int ac, char **av) {
    int status = 0;
    PGconn *conn;
    PGresult   *res;

    std::cout << "bonjour" << std::endl;
    conn = PQconnectdb("dbname = follow_prices");

    std::cout << "status de connexion : " << PQstatus(conn) << std::endl;

    res = PQexec(conn, "BEGIN");
    if (PQresultStatus(res) != PGRES_COMMAND_OK)
    {
        std::cout << "begin command failed"<<std::endl;
        PQclear(res);
        PQfinish(conn);
        return -1;
    }
    PQclear(res);

    int nFields = 0;
    res = PQexec(conn, "select * from brand;");
    nFields = PQnfields(res);
    for (int i = 0; i < nFields; i++)
        printf("%-15s", PQfname(res, i));
    printf("\n\n");

    /* next, print out the rows */
    for (int i = 0; i < PQntuples(res); i++)
    {
        for (int j = 0; j < nFields; j++)
            printf("%-15s", PQgetvalue(res, i, j));
        printf("\n");
    }

    PQclear(res);
    std::cout << "fin" << std::endl;
  
    return 0;
}
