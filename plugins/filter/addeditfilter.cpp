/*
    This file is part of Choqok, the KDE micro-blogging client

    Copyright (C) 2010-2011 Mehrdad Momeny <mehrdad.momeny@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.


    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, see http://www.gnu.org/licenses/

*/

#include "addeditfilter.h"
#include "filter.h"
#include "filtersettings.h"
#include <QTimer>
#include <kdebug.h>

AddEditFilter::AddEditFilter(QWidget* parent, Filter *filter)
    : KDialog(parent), currentFilter(filter)
{
    QWidget *wd = new QWidget(this);
    ui.setupUi(wd);
    setMainWidget(wd);

    setupFilterFields();
    setupFilterTypes();

    setWindowTitle(i18n("Define new filter rules"));

    if(filter){
        kDebug()<<filter->filterField();
        //Editing
        ui.filterField->setCurrentIndex(ui.filterField->findData(filter->filterField()));
        ui.filterType->setCurrentIndex(ui.filterType->findData(filter->filterType()));
        ui.filterText->setText(filter->filterText());
        ui.dontHideReplies->setChecked(filter->dontHideReplies());
        setWindowTitle(i18n("Modify filter rules"));
    }
    ui.filterText->setFocus();
}

AddEditFilter::~AddEditFilter()
{

}

void AddEditFilter::slotButtonClicked(int button)
{
    if(button==KDialog::Ok){
        Filter::FilterField field = (Filter::FilterField) ui.filterField->itemData(ui.filterField->currentIndex()).toInt();
        Filter::FilterType type = (Filter::FilterType) ui.filterType->itemData(ui.filterType->currentIndex()).toInt();
        QString fText = ui.filterText->text();
        bool dontHideReplies = ui.dontHideReplies->isChecked();
        if(currentFilter){
            currentFilter->setFilterField(field);
            currentFilter->setFilterText(fText);
            currentFilter->setFilterType(type);
            currentFilter->setDontHideReplies(dontHideReplies);
            emit filterUpdated(currentFilter);
        } else {
            currentFilter = new Filter(fText, field, type, dontHideReplies);
            emit newFilterRegistered(currentFilter);
        }
        accept();
    } else
        KDialog::slotButtonClicked(button);
}

void AddEditFilter::setupFilterFields()
{
    QMap<Filter::FilterField, QString>::const_iterator it, endIt = FilterSettings::filterFieldsMap().constEnd();
    for(it=FilterSettings::filterFieldsMap().constBegin(); it != endIt; ++it){
        ui.filterField->addItem(it.value(), it.key());
    }
}

void AddEditFilter::setupFilterTypes()
{
    QMap<Filter::FilterType, QString>::const_iterator it, endIt = FilterSettings::filterTypesMap().constEnd();
    for(it=FilterSettings::filterTypesMap().constBegin(); it != endIt; ++it){
        ui.filterType->addItem(it.value(), it.key());
    }
}

#include "addeditfilter.moc"
