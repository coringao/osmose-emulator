/*
 * Copyright holder 2001-2011 Vedder Bruno.
 * Work continued by 2016-2017 Carlos Donizete Froes [a.k.a coringao]
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

#ifndef WAVE_WRITER_H
#define WAVE_WRITER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include "AnsiColorTerminal.h"

#define WAVE_BUFFER_SIZE	5*22050	// 5 second buffer.

using namespace std;

typedef struct
{
    char           chunkID[4];
    int           chunkSize;
    short          wFormatTag;
    unsigned short wChannels;
    unsigned int  dwSamplesPerSec;
    unsigned int  dwAvgBytesPerSec;
    unsigned short wBlockAlign;
    unsigned short wBitsPerSample;
} FormatChunk;

typedef struct
{
    char           chunkID[4];
    int           chunkSize;
    short         *waveformData;
} DataChunk;

class WaveWriter
{

    public:
	
        WaveWriter(const char *filename);	// Constructor.
        ~WaveWriter();			// Destructor.
		
        void writeData(short d);
        void close();
		bool isOk() {return !skip_save;}
		
    private:
	
        unsigned int index;
        FormatChunk format;
        DataChunk   data;
        unsigned int length;
        ofstream waveFile;
        bool skip_save;
};

#endif
