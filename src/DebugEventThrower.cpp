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

#include "DebugEventThrower.h"

void DebugEventThrower::attachDebugEventListener(DebugEventListener *el)
{
    del = el;
}

void DebugEventThrower::throwDebugEvent(int type,char *source, char *msg)
{
    if (del != NULL)
    {
        del->sendDebugEvent(type, source, msg);
    }
    else
    {
        cerr << "Trying to throw DebugEvent but the Thrower is not attached to the listener !" << endl;
    }
}

