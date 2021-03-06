//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan S�nchez Rangel
// file name            : sociplus_co.h
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
//    Copyright (c) 2014 Juan S�nchez Rangel
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

#ifndef SOCIPLUS_CO_H_INCLUDED
#define SOCIPLUS_CO_H_INCLUDED

/********************************
   SociPlus wrapper for C
*********************************/

struct SociPlusConnection;
typedef struct SociPlusConnection SociPlusConnection;

struct SociPlusModelCell;
typedef struct SociPlusModelCell SociPlusModelCell;

struct SociPlusModelRow;
typedef struct SociPlusModelRow SociPlusModelRow;

struct SociPlusModel;
typedef struct SociPlusModel SociPlusModel;

struct SociPlusTableModel;
typedef struct SociPlusTableModel SociPlusTableModel;

struct SociPlusDataTableModel;
typedef struct SociPlusDataTableModel SociPlusDataTableModel;

struct SociPlusQuery;
typedef struct SociPlusQuery SociPlusQuery;

/* SociPlusConnection */

SociPlusConnection *SociPlusConnection_New(const char* driver, const char* connectionString);
void SociPlusConnection_Delete(SociPlusConnection *instance);
void SociPlusConnection_Open(SociPlusConnection *instance);
void SociPlusConnection_Close(SociPlusConnection *instance);
void SociPlusConnection_Begin(SociPlusConnection *instance);
void SociPlusConnection_Commit(SociPlusConnection *instance);
void SociPlusConnection_Rollback(SociPlusConnection *instance);
const char *SociPlusConnection_GetDriver(SociPlusConnection *instance);
const char *SociPlusConnection_GetConnectionString(SociPlusConnection *instance);

/* SociPlusModelCell */

SociPlusModelCell *SociPlusModelCell_New(SociPlusModelRow *parent);
void SociPlusModelCell_Delete(SociPlusModelCell *instance);
int SociPlusModelCell_AddModel(SociPlusModelCell *instance, SociPlusModel *model);
SociPlusModel *SociPlusModelCell_GetModelAt(SociPlusModelCell *instance, int pos);
SociPlusModel *SociPlusModelCell_DetachModelAt(SociPlusModelCell *instance, int pos);
int SociPlusModelCell_GetModelCount(SociPlusModelCell *instance);
void SociPlusModelCell_SetData(SociPlusModelCell *instance, const char* data);
const char* SociPlusModelCell_GetData(SociPlusModelCell *instance);
int SociPlusModelCell_FindModelPos(SociPlusModelCell *instance, SociPlusModel *model);
const char* SociPlusModelCell_GetOrigData(SociPlusModelCell *instance);
void SociPlusModelCell_RestoreOrigData(SociPlusModelCell *instance);
int SociPlusModelCell_DataChanged(SociPlusModelCell *instance);
void SociPlusModelCell_Clear(SociPlusModelCell *instance);


/* SociPlusModelRow */

SociPlusModelRow *SociPlusModelRow_New(SociPlusModel *parent);
void SociPlusModelRow_Delete(SociPlusModelRow *instance);
int SociPlusModelRow_AddModel(SociPlusModelRow *instance, SociPlusModel *model, int col);
SociPlusModelCell *SociPlusModelRow_AddCell(SociPlusModelRow *instance);
SociPlusModelCell *SociPlusModelRow_GetCellAt(SociPlusModelRow *instance, int pos);
int SociPlusModelRow_GetCellCount(SociPlusModelRow *instance);
void SociPlusModelRow_SetParent(SociPlusModelRow *instance, SociPlusModel *parent);
int SociPlusModelRow_Move(SociPlusModelRow *instance, SociPlusModel *model);
void SociPlusModelRow_SetState(SociPlusModelRow *instance, const char* value);
const char* SociPlusModelRow_GetState(SociPlusModelRow *instance);
void SociPlusModelRow_Clear(SociPlusModelRow *instance);

/* SociPlusModel */

SociPlusModel *SociPlusModel_New(SociPlusModelCell *parent);
void SociPlusModel_Delete(SociPlusModel* instance);
SociPlusModelRow *SociPlusModel_AddRow(SociPlusModel* instance);
int SociPlusModel_AddRowFromRow(SociPlusModel* instance, SociPlusModelRow *row);
int SociPlusModel_RemoveRowAt(SociPlusModel* instance, int pos);
SociPlusModelRow *SociPlusModel_DetachRowAt(SociPlusModel* instance, int pos);
SociPlusModelRow *SociPlusModel_GetRowAt(SociPlusModel* instance, int pos);
int SociPlusModel_GetRowCount(SociPlusModel* instance);
int SociPlusModel_AddModel(SociPlusModel* instance, SociPlusModel *model, int row, int col);
int SociPlusModel_FindRowPos(SociPlusModel* instance, SociPlusModelRow *row);
int SociPlusModel_Move(SociPlusModel* instance, SociPlusModelCell *cell);
SociPlusModelCell *SociPlusModel_GetParent(SociPlusModel* instance);
void SociPlusModel_SetParent(SociPlusModel* instance, SociPlusModelCell *cell);
void SociPlusModel_Clear(SociPlusModel* instance);

/* SociPlusTableModel */

SociPlusTableModel *SociPlusTableModel_New(int numCols);
void SociPlusTableModel_Delete(SociPlusTableModel *instance);
SociPlusModelRow *SociPlusTableModel_AddRow(SociPlusTableModel *instance);

/* SociPlusDataTableModel */

SociPlusDataTableModel *SociPlusDataTableModel_New(int numRows);
void SociPlusDataTableModel_Delete(SociPlusDataTableModel *instance);
int SociPlusDataTableModel_RemoveRowAt(SociPlusDataTableModel *instance, int pos);
SociPlusModelRow *SociPlusDataTableModel_GetRowAt(SociPlusDataTableModel *instance, int pos);
int SociPlusDataTableModel_GetRowCount(SociPlusDataTableModel *instance);
int SociPlusDataTableModel_AddModel(SociPlusDataTableModel *instance, SociPlusModel *model, int row, int col);
SociPlusModelRow *SociPlusDataTableModel_GetHeader(SociPlusDataTableModel *instance);
SociPlusModelRow *SociPlusDataTableModel_GetTypes(SociPlusDataTableModel *instance);

/* SociPlusQuery */

SociPlusQuery *SociPlusQuery_New(SociPlusConnection *connection);
void SociPlusQuery_Delete(SociPlusQuery *instance);
int SociPlusQuery_Execute(SociPlusQuery *instance, const char* query);
SociPlusDataTableModel *SociPlusQuery_ExecuteToModel(SociPlusQuery *instance, const char* query);

/********************************
   End of SociPlus wrapper for C
*********************************/

#endif // SOCIPLUS_CO_H_INCLUDED
