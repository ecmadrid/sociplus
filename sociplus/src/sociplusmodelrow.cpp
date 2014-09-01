//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan Sánchez Rangel
// file name            : sociplusmodelrow.cpp
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

#include "sociplusmodelrow.h"
#include "sociplusmodelcell.h"
#include "sociplusmodel.h"

namespace SociPlus
{
    SociPlusModelRow::SociPlusModelRow(SociPlusModel *parent)
    {
        //ctor
        m_parent = parent;
    }

    SociPlusModelRow::~SociPlusModelRow()
    {
        //dtor
        Clear();
    }

    void SociPlusModelRow::Clear()
    {
        while (!m_cells.empty())
        {
            SociPlusModelCell *lastCell = m_cells.back();
            delete lastCell;
            lastCell = 0;
            m_cells.pop_back();
        }
    }

    int SociPlusModelRow::GetCellCount()
    {
        return m_cells.size();
    }


    bool SociPlusModelRow::AddModel(SociPlusModel *model, int col)
    {
        SociPlusModelCell *cell = GetCellAt(col);
        cell->AddModel(model);
        return true;
    }

    SociPlusModelCell *SociPlusModelRow::AddCell()
    {
        SociPlusModelCell *newCell = new SociPlusModelCell(this);
        m_cells.push_back(newCell);
        return newCell;
    }

    SociPlusModelCell *SociPlusModelRow::GetCellAt(int pos)
    {
        return m_cells.at(pos);
    }
    void SociPlusModelRow::SetParent(SociPlusModel* parent)
    {
        m_parent = parent;
    }

    bool SociPlusModelRow::Move(SociPlusModel* model)
    {
        int pos = m_parent->FindRowPos(this);

        if (pos == -1)
        {
            return false;
        }

        m_parent->DetachRowAt(pos);
        model->AddRow(this);

        return true;
    }

    void SociPlusModelRow::SetState(string value)
    {
        m_state = value;
    }

    string SociPlusModelRow::GetState()
    {
        return m_state;
    }
}
