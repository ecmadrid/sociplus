//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan Sánchez Rangel
// file name            : sociplus_c.cpp
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

#include "sociplus_c.h"
#include "sociplusconnection.h"
#include "sociplusquery.h"

namespace SociPlus
{
    /* SociPlusConnection */

    SociPlusConnection *SociPlusConnection_new(const char* driver, const char* connectionString)
    {
        return new SociPlusConnection(driver, connectionString);
    }

    void SociPlusConnection_delete(SociPlusConnection *instance)
    {
        delete instance;
        instance = 0;
    }

    void SociPlusConnection_Open(SociPlusConnection *instance)
    {
        return instance->Open();
    }
    void SociPlusConnection_Close(SociPlusConnection *instance)
    {
        return instance->Close();
    }

    void SociPlusConnection_Begin(SociPlusConnection *instance)
    {
        return instance->Begin();
    }

    void SociPlusConnection_Commit(SociPlusConnection *instance)
    {
        return instance->Commit();
    }

    void SociPlusConnection_Rollback(SociPlusConnection *instance)
    {
        return instance->Rollback();
    }

    const char *SociPlusConnection_GetDriver(SociPlusConnection *instance)
    {
        return instance->GetDriver().c_str();
    }

    const char *SociPlusConnection_GetConnectionString(SociPlusConnection *instance)
    {
        return instance->GetConnectionString().c_str();
    }

    /* SociPlusModelCell */

    SociPlusModelCell *SociPlusModelCell_new(SociPlusModelRow *parent)
    {
        return new SociPlusModelCell(parent);
    }

    void SociPlusModelCell_delete(SociPlusModelCell *instance)
    {
        delete instance;
        instance = 0;
    }

    int SociPlusModelCell_AddModel(SociPlusModelCell *instance, SociPlusModel *model)
    {
        return instance->AddModel(model);
    }

    SociPlusModel *SociPlusModelCell_GetModelAt(SociPlusModelCell *instance, int pos)
    {
        return instance->GetModelAt(pos);
    }

    SociPlusModel *SociPlusModelCell_DetachModelAt(SociPlusModelCell *instance, int pos)
    {
        return instance->DetachModelAt(pos);
    }

    int SociPlusModelCell_GetModelCount(SociPlusModelCell *instance)
    {
        return instance->GetModelCount();
    }

    void SociPlusModelCell_SetData(SociPlusModelCell *instance, const char* data)
    {
        return instance->SetData(data);
    }

    const char* SociPlusModelCell_GetData(SociPlusModelCell *instance)
    {
        return instance->GetData().c_str();
    }

    int SociPlusModelCell_FindModelPos(SociPlusModelCell *instance, SociPlusModel *model)
    {
        return instance->FindModelPos(model);
    }

    void SociPlusModelCell_Clear(SociPlusModelCell *instance)
    {
        return instance->Clear();
    }

    /* SociPlusModelRow */

    SociPlusModelRow *SociPlusModelRow_new(SociPlusModel *parent)
    {
        return new SociPlusModelRow(parent);
    }

    void SociPlusModelRow_delete(SociPlusModelRow *instance)
    {
        delete instance;
        instance = 0;
    }

    int SociPlusModelRow_AddModel(SociPlusModelRow *instance, SociPlusModel *model, int col)
    {
        return instance->AddModel(model, col);
    }

    SociPlusModelCell *SociPlusModelRow_AddCell(SociPlusModelRow *instance)
    {
        return instance->AddCell();
    }

    SociPlusModelCell *SociPlusModelRow_GetCellAt(SociPlusModelRow *instance, int pos)
    {
        return instance->GetCellAt(pos);
    }

    int SociPlusModelRow_GetCellCount(SociPlusModelRow *instance)
    {
        return instance->GetCellCount();
    }

    void SociPlusModelRow_SetParent(SociPlusModelRow *instance, SociPlusModel *parent)
    {
        return instance->SetParent(parent);
    }

    int SociPlusModelRow_Move(SociPlusModelRow *instance, SociPlusModel *model)
    {
        return instance->Move(model);
    }

    void SociPlusModelRow_Clear(SociPlusModelRow *instance)
    {
        return instance->Clear();
    }

    /* SociPlusModel */

    SociPlusModel *SociPlusModel_new(SociPlusModelCell *parent = 0)
    {
        return new SociPlusModel(parent);
    }

    void SociPlusModel_delete(SociPlusModel* instance)
    {
        delete instance;
        instance = 0;
    }

    SociPlusModelRow *SociPlusModel_AddRow(SociPlusModel* instance)
    {
        return instance->AddRow();
    }

    int SociPlusModel_AddRowFromRow(SociPlusModel* instance, SociPlusModelRow *row)
    {
        return instance->AddRow(row);
    }

    int SociPlusModel_RemoveRowAt(SociPlusModel* instance, int pos)
    {
        return instance->RemoveRowAt(pos);
    }

    SociPlusModelRow *SociPlusModel_DetachRowAt(SociPlusModel* instance, int pos)
    {
        return instance->DetachRowAt(pos);
    }

    SociPlusModelRow *SociPlusModel_GetRowAt(SociPlusModel* instance, int pos)
    {
        return instance->GetRowAt(pos);
    }

    int SociPlusModel_GetRowCount(SociPlusModel* instance)
    {
        return instance->GetRowCount();
    }

    int SociPlusModel_AddModel(SociPlusModel* instance, SociPlusModel *model, int row, int col)
    {
        return instance->AddModel(model, row, col);
    }

    int SociPlusModel_FindRowPos(SociPlusModel* instance, SociPlusModelRow *row)
    {
        return instance->FindRowPos(row);
    }

    int SociPlusModel_Move(SociPlusModel* instance, SociPlusModelCell *cell)
    {
        return instance->Move(cell);
    }

    SociPlusModelCell *SociPlusModel_GetParent(SociPlusModel* instance)
    {
        return instance->GetParent();
    }

    void SociPlusModel_SetParent(SociPlusModel* instance, SociPlusModelCell *cell)
    {
        return instance->SetParent(cell);
    }

    void SociPlusModel_Clear(SociPlusModel* instance)
    {
        return instance->Clear();
    }

    /* SociPlusTableModel */

    SociPlusTableModel *SociPlusTableModel_new(int numCols)
    {
        return new SociPlusTableModel(numCols);
    }

    void SociPlusTableModel_delete(SociPlusTableModel *instance)
    {
        delete instance;
        instance = 0;
    }

    SociPlusModelRow *SociPlusTableModel_AddRow(SociPlusTableModel *instance)
    {
        return instance->AddRow();
    }

    /* SociPlusDataTableModel */

    SociPlusDataTableModel *SociPlusDataTableModel_new(int numRows)
    {
        return new SociPlusDataTableModel(numRows);
    }

    void SociPlusDataTableModel_delete(SociPlusDataTableModel *instance)
    {
        delete instance;
        instance = 0;
    }

    int SociPlusDataTableModel_RemoveRowAt(SociPlusDataTableModel *instance, int pos)
    {
        return instance->RemoveRowAt(pos);
    }

    SociPlusModelRow *SociPlusDataTableModel_GetRowAt(SociPlusDataTableModel *instance, int pos)
    {
        return instance->GetRowAt(pos);
    }

    int SociPlusDataTableModel_GetRowCount(SociPlusDataTableModel *instance)
    {
        return instance->GetRowCount();
    }

    int SociPlusDataTableModel_AddModel(SociPlusDataTableModel *instance, SociPlusModel *model, int row, int col)
    {
        return instance->AddModel(model, row, col);
    }

    SociPlusModelRow *SociPlusDataTableModel_GetHeader(SociPlusDataTableModel *instance)
    {
        return instance->GetHeader();
    }

    SociPlusModelRow *SociPlusDataTableModel_GetTypes(SociPlusDataTableModel *instance)
    {
        return instance->GetTypes();
    }

    /* SociPlusQuery */

    SociPlusQuery *SociPlusQuery_new(SociPlusConnection *connection)
    {
        return new SociPlusQuery(connection);
    }

    void SociPlusQuery_delete(SociPlusQuery *instance)
    {
        delete instance;
        instance = 0;
    }

    int SociPlusQuery_Execute(SociPlusQuery* instance, const char* query)
    {
        return instance->Execute(que);
    }

    SociPlusDataTableModel *SociPlusQuery_ExecuteToModel(SociPlusQuery *instance, const char* query)
    {
        return instance->ExecuteToModel(query);
    }
}
