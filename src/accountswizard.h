/*
    This file is part of choqoK, the KDE Twitter client

    Copyright (C) 2008 Mehrdad Momeny <mehrdad.momeny@gmail.com>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

*/
#ifndef ACCOUNTSWIZARD_H
#define ACCOUNTSWIZARD_H

#include "ui_accounts_wizard_base.h"
#include "datacontainers.h"

#define TWITTER_API_PATH "http://twitter.com/"
#define TWITTER_SERVICE_TEXT "Twitter.com"

#define IDENTICA_API_PATH "http://identi.ca/api/"
#define IDENTICA_SERVICE_TEXT "Identi.ca"

class AccountsWizard: public KDialog
{
    Q_OBJECT
public:
    AccountsWizard ( QString alias = QString(), QWidget *parent = 0 );

signals:
    void accountAdded ( const Account &account );
    void accountEdited ( const Account &account );

protected slots:
    void slotAccepted();

private:
    void loadAccount ( const QString &alias );

    Ui::accounts_wizard_base ui;
    KConfig *accountsGrp;
//     KConfigGroup *accountsGrp;

    QString mAlias;
    bool isEdit;
};

#endif