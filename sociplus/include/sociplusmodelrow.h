//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan Sánchez Rangel
// file name            : sociplusmodelrow.h
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

#ifndef SOCIPLUSMODELROW_H
#define SOCIPLUSMODELROW_H

#include <string>
#include <vector>

using namespace std;

namespace SociPlus
{

/* Row state definitions */

#define STATE_UNKNOWN "unknown"
#define STATE_SELECTED "selected"
#define STATE_INSERTED "inserted"
#define STATE_UPDATED "updated"
#define STATE_DELETED "deleted"

/* End of row state definitions */

class SociPlusModel;
class SociPlusModelCell;

class SociPlusModelRow
{
public:
    SociPlusModelRow(SociPlusModel *parent);
    virtual ~SociPlusModelRow();

    bool AddModel(SociPlusModel *model, int col);
    SociPlusModelCell *AddCell();
    SociPlusModelCell *GetCellAt(int pos);
    int GetCellCount();
    void SetParent(SociPlusModel *parent);
    bool Move(SociPlusModel *model);
    void SetState(string value);
    string GetState();

    void Clear();
protected:
    SociPlusModel *m_parent;
    string m_state;
    vector<SociPlusModelCell *>m_cells;
private:
};
};


#endif // SOCIPLUSMODELROW_H
