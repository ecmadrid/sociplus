#include <stdio.h>
#include <stdlib.h>

#include <sociplus_co.h>

int main()
{
    SociPlusConnection *connection = SociPlusConnection_New("sqlite3", "./test.s3db");
    SociPlusConnection_Open(connection);

    SociPlusQuery *query = SociPlusQuery_New(connection);

    SociPlusQuery_Execute(query, "DROP TABLE TEST");
    SociPlusQuery_Execute(query, "CREATE TABLE TEST (ID  INTEGER, DATA TEXT)");

    SociPlusConnection_Begin(connection);
    SociPlusQuery_Execute(query, "INSERT INTO TEST (ID, DATA) VALUES (1, 'Data1')");
    SociPlusQuery_Execute(query, "INSERT INTO TEST (ID, DATA) VALUES (2, 'Data2')");
    SociPlusQuery_Execute(query, "INSERT INTO TEST (ID, DATA) VALUES (3, 'Data3')");
    SociPlusQuery_Execute(query, "INSERT INTO TEST (ID, DATA) VALUES (4, 'Data4')");
    SociPlusConnection_Commit(connection);

    SociPlusQuery_Delete(query);

    SociPlusConnection_Close(connection);
    SociPlusConnection_Delete(connection);
    return 0;
}
