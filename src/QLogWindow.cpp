/*
 * Copyright holder 2001-2011 Vedder Bruno.
 * Work continued by 2016-2018 Carlos Donizete Froes [a.k.a coringao]
 *
 * This file is part of Osmose, a Sega Master System/Game Gear software
 * emulator.
 *
 * Osmose is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * Osmose is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Osmose.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Many thanks to Vedder Bruno, the original author of Osmose Emulator.
 *
 */

#include "QLogWindow.h"

// Initialise self ptr to NULL.
QLogWindow *QLogWindow::self = NULL;


QLogWindow *QLogWindow::getInstance(QWidget *parent)
{
	if (self == NULL)
	{
		self = new QLogWindow(parent);
	}
	return self;
}

void QLogWindow::appendLog(const char *str)
{
	QString msg(str);
	QString time = getTimePrefix();	
	time.append(msg);
	logQPlainTextEdit->appendPlainText(time);
}


void QLogWindow::appendLog(string &str)
{
	QString msg(str.c_str());
	QString time = getTimePrefix();	
	time.append(msg);
	logQPlainTextEdit->appendPlainText(time);
}

void QLogWindow::addSeparator()
{
	logQPlainTextEdit->appendPlainText("________________________________________________________________\n");
}


QString QLogWindow::getTimePrefix()
{
	QString ascii_time = "[";
	ascii_time.append(QTime::currentTime().toString());
	ascii_time.append("] ");
	return ascii_time;
}

void QLogWindow::clearLogs()
{
	logQPlainTextEdit->clear();
}

/**
 * Private Constructor.
 */
QLogWindow::QLogWindow(QWidget *p) : QWidget(p)
{
	setupUi((QWidget*)this);
	QObject::connect(hideButton, SIGNAL(clicked()), this, SLOT(hideWindow()));
	QObject::connect(clearLogsButton, SIGNAL(clicked()), this, SLOT(clearLogs()));
}

/**
 * Destructor.
 */
QLogWindow::~QLogWindow()
{
}


void QLogWindow::hideWindow()
{
	self->setVisible(false);
}


