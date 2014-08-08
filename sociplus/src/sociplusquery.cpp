//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan Sánchez Rangel
// file name            : sociplusquery.cpp
//
// -------------------------------------------------------------------------
//
//    SOCIPLUS
//
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the MIT License.
//
//    -------------------------------------------------------------------------
//
//    The MIT License (MIT)
//
//    Copyright (c) 2014 Juan Sánchez Rangel
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy
//    of this software and associated documentation files (the "Software"), to deal
//    in the Software without restriction, including without limitation the rights
//    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//    copies of the Software, and to permit persons to whom the Software is
//    furnished to do so, subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//    SOFTWARE.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#include "sociplusquery.h"
#include "soci.h"

#include "sociplusquery.h"

namespace SociPlus
{
    SociPlusQuery::SociPlusQuery(SociPlusConnection *connection)
    {
        //ctor
        m_connection = connection;
    }

    SociPlusQuery::~SociPlusQuery()
    {
        //dtor
    }

    bool SociPlusQuery::Execute(string query)
    {
        try
        {
            session& sql = m_connection->GetSession();
            sql.once << query;
        }
        catch(...)
        {
            return false;
        }

        return true;
    }

    SociPlusDataTableModel *SociPlusQuery::ExecuteToModel(string query)
    {
        session& sql = m_connection->GetSession();
        SociPlusDataTableModel *model = 0;

        try
        {
            rowset<row> rs = (sql.prepare << query);
            bool firstRow = true;
            bool hasRows = false;
            int numCols = 0;
            for (rowset<row>::const_iterator it = rs.begin(); it != rs.end(); ++it)
            {
                hasRows = true;
                row const& row = *it;

                if (firstRow)
                {
                    firstRow = false;
                    numCols = row.size();
                    model = new SociPlusDataTableModel(numCols);

                    for(std::size_t i = 0; i != row.size(); ++i)
                    {
                        const column_properties & props = row.get_properties(i);

                        try
                        {
                            model->GetHeader()->GetCellAt(i)->SetData(props.get_name());

                            switch(props.get_data_type())
                            {
                            case dt_string:
                                model->GetTypes()->GetCellAt(i)->SetData(TYPE_STRING);
                                break;
                            case dt_double:
                                model->GetTypes()->GetCellAt(i)->SetData(TYPE_DOUBLE);
                                break;
                            case dt_integer:
                                model->GetTypes()->GetCellAt(i)->SetData(TYPE_INTEGER);
                                break;
                            case dt_long_long:
                                model->GetTypes()->GetCellAt(i)->SetData(TYPE_LONG_LONG);
                                break;
                            case dt_unsigned_long_long:
                                model->GetTypes()->GetCellAt(i)->SetData(TYPE_UNSIGNED_LONG_LONG);
                                break;
                            case dt_date:
                                model->GetTypes()->GetCellAt(i)->SetData(TYPE_DATE);
                                break;
                            }
                        }
                        catch(...)
                        {
                            model->GetTypes()->GetCellAt(i)->SetData(TYPE_UNKNOWN);
                        }
                    }
                }

                SociPlusModelRow *newRow = model->AddRow();


                for(std::size_t i = 0; i != row.size(); ++i)
                {
                    const column_properties & props = row.get_properties(i);

                    ostringstream doc;

                    try
                    {
                        switch(props.get_data_type())
                        {
                        case dt_string:
                            doc << row.get<std::string>(i);
                            break;
                        case dt_double:
                            doc << row.get<double>(i);
                            break;
                        case dt_integer:
                            doc << row.get<int>(i);
                            break;
                        case dt_long_long:
                            doc << row.get<long long>(i);
                            break;
                        case dt_unsigned_long_long:
                            doc << row.get<unsigned long long>(i);
                            break;
                        case dt_date:
                            std::tm when = row.get<std::tm>(i);
                            doc << asctime(&when);
                            break;
                        }
                    }
                    catch(exception& ex)
                    {
                        doc << "";
                    }

                    string valor = doc.str();

                    newRow->GetCellAt(i)->SetData(valor);
                }
            }

            if (!hasRows)
            {
                row r;
                sql << query, into(r);

                numCols = r.size();
                model = new SociPlusDataTableModel(numCols);

                for(std::size_t i = 0; i != r.size(); ++i)
                {
                    const column_properties & props = r.get_properties(i);

                    try
                    {
                        model->GetHeader()->GetCellAt(i)->SetData(props.get_name());

                        switch(props.get_data_type())
                        {
                        case dt_string:
                            model->GetTypes()->GetCellAt(i)->SetData(TYPE_STRING);
                            break;
                        case dt_double:
                            model->GetTypes()->GetCellAt(i)->SetData(TYPE_DOUBLE);
                            break;
                        case dt_integer:
                            model->GetTypes()->GetCellAt(i)->SetData(TYPE_INTEGER);
                            break;
                        case dt_long_long:
                            model->GetTypes()->GetCellAt(i)->SetData(TYPE_LONG_LONG);
                            break;
                        case dt_unsigned_long_long:
                            model->GetTypes()->GetCellAt(i)->SetData(TYPE_UNSIGNED_LONG_LONG);
                            break;
                        case dt_date:
                            model->GetTypes()->GetCellAt(i)->SetData(TYPE_DATE);
                            break;
                        }
                    }
                    catch(...)
                    {
                        model->GetTypes()->GetCellAt(i)->SetData(TYPE_UNKNOWN);
                    }
                }
            }
        }
        catch (exception &ex)
        {
            cout << ex.what() << endl;
            if (model)
            {
                delete model;
                model = 0;
            }
        }

        return model;
    }
}
