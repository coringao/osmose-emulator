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

#ifndef OPTIONS_H
#define OPTIONS_H

#include <iostream>
#include <iomanip>
#include "Bits.h"

#define JAPAN	0
#define EXPORT	1

#define DEFAULT_ACCELERATION 0.5

enum
{
    DEFAULT_PAD = 0,
    PADDLE      = 1,
    JOYSTICK	= 2
};

// Video Filters Enumeration.
enum
{
    NEAREST  = 0,
    BILINEAR = 1
};


enum
{
    SMS,
    GAMEGEAR
};

using namespace std;

class Options
{
    public:

        bool WorldVersion;	// 0 is Jap, 1 Export machine.
        int  MachineType;   // SMS or GameGear ?
        int inputType;		// Input device type.
        float acceleration; // Paddle acceleration.
        int mapperType;		// Use Sega/Codemaster/Korean Mapper.
        bool ntsc;			// true = ntsc false = pal/secam.
        bool irq_hack;
        int videoFilter;	//
        void reset();
};

class EmulatorOptions
{
    public:

        bool bright_palette;	// Bright palette or not ?
        bool fullscreen_flag;	// Emu must run in fullscreen.
        bool sound;			// Emu must emulate SN76489.
        bool default_config;	// Does the emulator use default conf ?
        bool display_fps;	        // FPS in Title bar option.
        char ini_file[512];         // For name of file containing conf.
        bool tracejoy;
        void reset();
};

#endif
