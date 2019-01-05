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

#include <QApplication>
#include <QTextStream>
#include "OsmoseGUI.h"

// GNOME3 on Debian has XDG_SESSION_TYPE, which Qt warns about at startup:
//
//      Warning: Ignoring XDG_SESSION_TYPE=wayland on Gnome.
//      Use QT_QPA_PLATFORM=wayland to run on Wayland anyway.
//
// In this case, the warning is muted. This hack will be retained here until a
// future version of Qt provides Qt Wayland widgets that are usable
// in the gnome shell. Cf. https://bugreports.qt.io/browse/QTBUG-68619
    
int main(int argc, char *argv[])
{
    if (qgetenv("XDG_SESSION_TYPE") == QByteArrayLiteral("wayland")) {
        qunsetenv("XDG_SESSION_TYPE");
        qEnvironmentVariable("QT_QPA_PLATFORM", "wayland");
    }
    QApplication app(argc, argv);
    OsmoseGUI window;
    window.resize(512, 384 + MENU_HEIGHT);
    window.show();
    for (int i=1; i < argc; i++) {
		if(QString(argv[i]) == "-f" || QString(argv[i]) == "--fullscreen") {
			window.toggleFullscreen();
		} else {
            QString rom_file = argv[i];
            window.loadTheROM(rom_file);
        }
    }
    return app.exec();
}
