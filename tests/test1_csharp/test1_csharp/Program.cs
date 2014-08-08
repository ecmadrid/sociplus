using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace test1_csharp
{
    class Program
    {
        [DllImport("libsociplus.dll", EntryPoint = "SociPlusConnection_New")]
        static extern IntPtr SociPlusConnection_New(string driver, string connectionString);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusConnection_Open")]
        static extern void SociPlusConnection_Open(IntPtr instance);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusConnection_Close")]
        static extern void SociPlusConnection_Close(IntPtr instance);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusConnection_Delete")]
        static extern void SociPlusConnection_Delete(IntPtr instance);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusConnection_Begin")]
        static extern void SociPlusConnection_Begin(IntPtr instance);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusConnection_Commit")]
        static extern void SociPlusConnection_Commit(IntPtr instance);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusQuery_New")]
        static extern IntPtr SociPlusQuery_New(IntPtr connection);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusQuery_Delete")]
        static extern void SociPlusQuery_Delete(IntPtr instance);

        [DllImport("libsociplus.dll", EntryPoint = "SociPlusQuery_Execute")]
        static extern void SociPlusQuery_Execute(IntPtr instance, string query);
        
        static void Main(string[] args)
        {
            IntPtr connection = SociPlusConnection_New("sqlite3", "test.s3db");
            SociPlusConnection_Open(connection);

            IntPtr query = SociPlusQuery_New(connection);

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
        }
    }
}
