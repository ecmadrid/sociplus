//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2014 by Juan Sánchez Rangel
// file name            : sociplusmodelcell.cpp
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

#include "sociplusmodelcell.h"
#include "sociplusmodel.h"

namespace SociPlus
{
    SociPlusModelCell::SociPlusModelCell(SociPlusModelRow *parent)
    {
        //ctor
        m_parent = parent;
        m_data = "";
        m_origData = "";
        m_firstData = true;
    }

    SociPlusModelCell::~SociPlusModelCell()
    {
        //dtor
        Clear();
    }

    bool SociPlusModelCell::AddModel(SociPlusModel *model)
    {
        m_models.push_back(model);
        model->SetParent(this);
        return true;
    }

    void SociPlusModelCell::SetData(string data)
    {
        m_data = data;
        if (m_firstData == true)
        {
            m_origData = m_data;
            m_firstData = false;
        }
    }

    string SociPlusModelCell::GetData()
    {
        return m_data;
    }

    string SociPlusModelCell::GetOrigData()
    {
        return m_origData;
    }

    void SociPlusModelCell::RestoreOrigData()
    {
        m_data = m_origData;
    }

    bool SociPlusModelCell::DataChanged()
    {
        if (m_data != m_origData)
            return true;

        return false;
    }

    SociPlusModel *SociPlusModelCell::GetModelAt(int pos)
    {
        return m_models.at(pos);
    }

    SociPlusModel *SociPlusModelCell::DetachModelAt(int pos)
    {
        SociPlusModel *model = m_models.at(pos);
        m_models.erase(m_models.begin() + pos);
        model->SetParent(0);

        return model;
    }

    int SociPlusModelCell::GetModelCount()
    {
        return m_models.size();
    }

    void SociPlusModelCell::Clear()
    {
        while (!m_models.empty())
        {
            SociPlusModel *lastModel = m_models.back();

            if (lastModel != 0)
            {
                delete lastModel;
            }

            lastModel = 0;
            m_models.pop_back();
        }
    }

    int SociPlusModelCell::FindModelPos(SociPlusModel* model)
    {
        for (size_t x = 0; x < m_models.size(); x++)
        {
            if (model == m_models.at(x))
            {
                return x;
            }
        }

        return -1;
    }
}
