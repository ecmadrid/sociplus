//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan S�nchez Rangel
// file name            : sociplusdatatablemodel.cpp
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


#include "sociplusdatatablemodel.h"

namespace SociPlus
{
    SociPlusDataTableModel::SociPlusDataTableModel(int numCols) : SociPlusTableModel(numCols)
    {
        //ctor
        AddRow();
        AddRow();
    }

    SociPlusDataTableModel::~SociPlusDataTableModel()
    {
        //dtor
    }

    bool SociPlusDataTableModel::RemoveRowAt(int pos)
    {
        return SociPlusModel::RemoveRowAt(pos + 2);
    }

    SociPlusModelRow *SociPlusDataTableModel::GetRowAt(int pos)
    {
        return SociPlusModel::GetRowAt(pos + 2);
    }

    int SociPlusDataTableModel::GetRowCount()
    {
        return SociPlusModel::GetRowCount() - 2;
    }

    bool SociPlusDataTableModel::AddModel(SociPlusModel* model, int row, int col)
    {
        return SociPlusModel::AddModel(model, row + 2, col);
    }

    SociPlusModelRow *SociPlusDataTableModel::GetHeader()
    {
        return m_rows.at(0);
    }

    SociPlusModelRow *SociPlusDataTableModel::GetTypes()
    {
        return m_rows.at(1);
    }
}
