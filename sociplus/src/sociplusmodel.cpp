//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan Sánchez Rangel
// file name            : sociplusmodel.cpp
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

#include "sociplusmodel.h"
#include "sociplusmodelcell.h"

namespace SociPlus
{
    SociPlusModel::SociPlusModel(SociPlusModelCell *parent)
    {
        //ctor
        m_parent = parent;
    }

    SociPlusModel::~SociPlusModel()
    {
        //dtor
        Clear();
    }

    void SociPlusModel::Clear()
    {
        while (!m_rows.empty())
        {
            SociPlusModelRow *lastRow = m_rows.back();

            if (lastRow != 0)
            {
                delete lastRow;
            }

            lastRow = 0;
            m_rows.pop_back();
        }
    }

    SociPlusModelRow *SociPlusModel::AddRow()
    {
        SociPlusModelRow *newRow = new SociPlusModelRow(this);
        m_rows.push_back(newRow);
        return newRow;
    }

    bool SociPlusModel::AddRow(SociPlusModelRow* row)
    {
        row->SetParent(this);
        m_rows.push_back(row);
        return true;
    }


    bool SociPlusModel::RemoveRowAt(int pos)
    {
        SociPlusModelRow *rowPos = m_rows.at(pos);
        delete rowPos;
        rowPos = 0;

        /*
        for (size_t x = pos + 1; x < m_rows.size(); x++)
        {
            m_rows[x - 1]  = m_rows[x];
        }

        SociPlusModelRow *lastRow = m_rows.back();
        delete lastRow;
        lastRow = 0;
        m_rows.pop_back();
        */

        m_rows.erase(m_rows.begin() + pos);

        return true;
    }

    SociPlusModelRow *SociPlusModel::DetachRowAt(int pos)
    {
        SociPlusModelRow *row = m_rows.at(pos);
        m_rows.erase(m_rows.begin() + pos);
        row->SetParent(0);

        return row;
    }

    int SociPlusModel::GetRowCount()
    {
        return m_rows.size();
    }


    SociPlusModelRow *SociPlusModel::GetRowAt(int pos)
    {
        return m_rows.at(pos);
    }

    bool SociPlusModel::AddModel(SociPlusModel *model, int row, int col)
    {
        SociPlusModelRow *rowPos = m_rows.at(row);
        SociPlusModelCell *rowCell = rowPos->GetCellAt(col);
        rowCell->AddModel(model);
        return true;
    }

    SociPlusModelCell *SociPlusModel::GetParent()
    {
        return m_parent;
    }

    void SociPlusModel::SetParent(SociPlusModelCell *cell)
    {
        m_parent = cell;
    }

    int SociPlusModel::FindRowPos(SociPlusModelRow* row)
    {
        for(size_t x = 0; x < m_rows.size(); x++)
        {
            if (row == m_rows.at(x))
            {
                return x;
            }
        }

        return -1;
    }

    bool SociPlusModel::Move(SociPlusModelCell* cell)
    {
        if (m_parent != 0)
        {
            int pos = m_parent->FindModelPos(this);

            if (pos == -1)
            {
                return false;
            }

            m_parent->DetachModelAt(pos);
        }
        else
        {
            cell->AddModel(this);
        }

        return true;
    }
}
