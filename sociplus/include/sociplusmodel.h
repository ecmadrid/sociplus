//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan S�nchez Rangel
// file name            : sociplusmodel.h
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

#ifndef SOCIPLUSMODEL_H
#define SOCIPLUSMODEL_H

#include <iostream>
#include <vector>
#include "sociplusmodelrow.h"
#include "sociplusmodelcell.h"

using namespace std;

namespace SociPlus
{
class SociPlusModel
{
public:
    SociPlusModel(SociPlusModelCell *parent = 0);
    virtual ~SociPlusModel();

    virtual SociPlusModelRow *AddRow();
    virtual bool AddRow(SociPlusModelRow *row);
    virtual bool RemoveRowAt(int pos);
    virtual SociPlusModelRow *DetachRowAt(int pos);
    virtual SociPlusModelRow *GetRowAt(int pos);
    virtual int GetRowCount();
    virtual bool AddModel(SociPlusModel *model, int row, int col);
    virtual int FindRowPos(SociPlusModelRow *row);
    virtual bool Move(SociPlusModelCell *cell);

    virtual SociPlusModelCell *GetParent();
    virtual void SetParent(SociPlusModelCell *cell);

    virtual void Clear();
protected:
    SociPlusModelCell *m_parent;
    vector<SociPlusModelRow *>m_rows;
private:
};
};

#endif // SOCIPLUSMODEL_H
