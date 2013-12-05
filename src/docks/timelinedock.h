/*
 * Copyright (c) 2013 Meltytech, LLC
 * Author: Dan Dennedy <dan@dennedy.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TIMELINEDOCK_H
#define TIMELINEDOCK_H

#include <QDockWidget>
#include "models/multitrackmodel.h"
#include "mltcontroller.h"

namespace Ui {
class TimelineDock;
}

class TimelineDock : public QDockWidget
{
    Q_OBJECT
    Q_PROPERTY(int position READ position WRITE setPosition NOTIFY positionChanged);

public:
    explicit TimelineDock(QWidget *parent = 0);
    ~TimelineDock();

    MultitrackModel& model() { return m_model; }
    int position() const { return m_position; }
    void setPosition(int position);
    Q_INVOKABLE QString timecode(int frames);

signals:
    void producerOpened();
    void positionChanged();
    void seeked(int);

public slots:
    void onProducerOpened(void);
    void onShowFrame(Mlt::QFrame frame);
    void onSeeked(int position);

private:
    Ui::TimelineDock *ui;
    MultitrackModel m_model;
    int m_position;
};

#endif // TIMELINEDOCK_H