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

#ifndef UPLOADMEDIADIALOG_H
#define UPLOADMEDIADIALOG_H

#include <kdialog.h>
#include "choqok_export.h"

namespace Choqok {

namespace UI {

class CHOQOK_EXPORT UploadMediaDialog : public KDialog
{
Q_OBJECT
public:
    explicit UploadMediaDialog(QWidget* parent = 0, const QString &url = QString());
    ~UploadMediaDialog();

protected:
    virtual void slotButtonClicked(int button);
    void load();
    bool showed;

protected Q_SLOTS:
    void currentPluginChanged( int index );
    void slotAboutClicked();
    void slotConfigureClicked();
    void slotMediumUploadFailed(const KUrl& localUrl, const QString& errorMessage);
    void slotMediumUploaded(const KUrl& localUrl, const QString& remoteUrl);
    void slotMediumChanged(const QString &url);

private:
    class Private;
    Private * const d;
    QSize winSize;
};

}

}

#endif // UPLOADMEDIADIALOG_H
