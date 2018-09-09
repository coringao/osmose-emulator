###############################################################################
#  
# * This file is part of Osmose, a Sega Master System/Game Gear software
# * emulator.
# *
# * Many thanks to Vedder Bruno, the original author of Osmose Emulator.
# *
# * Copyright holder 2001-2011 Vedder Bruno.
# * Work continued by 2016-2018 Carlos Donizete Froes [a.k.a coringao]
# *
# * Osmose Emulator is free software: you can redistribute it and/or modify it
# * under the terms of the GNU General Public License as published by the
# * Free Software Foundation, either version 3 of the License,
# * or any later version.
#
###############################################################################

QT += core gui opengl widgets
TARGET = osmose-emulator
TEMPLATE = app

DEPENDPATH += src
INCLUDEPATH += src

LIBS += -lz -lasound -lGL -lGLU -lglut
FLAGS += -Wall -Wextra -Wno-unused -Wcast-qual
QMAKE_CXXFLAGS += -std=gnu++17 $$FLAGS
QMAKE_CFLAGS += -Wmissing-prototypes -Wshadow $$FLAGS

# Output directory
OBJECTS_DIR += src
MOC_DIR += src
RCC_DIR += src
UI_DIR += src

# Input directory
HEADERS += src/EmulationThread.h \
           src/Joystick.h \
           src/KeyMapper.h \
           src/OsmoseConfigurationFile.h \
           src/OsmoseEmulationThread.h \
           src/OsmoseGUI.h \
           src/Pthreadcpp.h \
           src/QGLImage.h \
           src/QLogWindow.h \
           src/QOsmoseConfiguration.h \
           src/TGAWriter.h \
           src/WhiteNoiseEmulationThread.h \
           src/BasicTypes.h \
           src/Z80.h \
           src/AnsiColorTerminal.h \
           src/Bits.h \
           src/DebugEventListener.h \
           src/DebugEventThrower.h \
           src/Definitions.h \
           src/FIFOSoundBuffer.h \
           src/IOMapper.h \
           src/IOMapper_GG.h \
           src/MemoryMapper.h \
           src/Options.h \
           src/OsmoseCore.h \
           src/RomSpecificOption.h \
           src/SaveState.h \
           src/SmsDebugger.h \
           src/SmsEnvironment.h \
           src/SN76489.h \
           src/SoundThread.h \
           src/VDP.h \
           src/VDP_GG.h \
           src/Version.h \
           src/WaveWriter.h
FORMS +=   src/Configuration.ui \
	   src/LogWindow.ui
SOURCES += src/EmulationThread.cpp \
           src/Joystick.cpp \
           src/KeyMapper.cpp \
           src/main.cpp \
           src/OsmoseConfigurationFile.cpp \
           src/OsmoseEmulationThread.cpp \
           src/OsmoseGUI.cpp \
           src/Pthreadcpp.cpp \
           src/QGLImage.cpp \
           src/QLogWindow.cpp \
           src/QOsmoseConfiguration.cpp \
           src/TGAWriter.cpp \
           src/WhiteNoiseEmulationThread.cpp \
           src/Opc_cbxx.cpp \
           src/Opc_dd.cpp \
           src/Opc_ddcb.cpp \
           src/Opc_ed.cpp \
           src/Opc_fd.cpp \
           src/Opc_fdcb.cpp \
           src/Opc_std.cpp \
           src/Z80.cpp \
           src/DebugEventThrower.cpp \
           src/FIFOSoundBuffer.cpp \
           src/IOMapper.cpp \
           src/IOMapper_GG.cpp \
           src/MemoryMapper.cpp \
           src/Options.cpp \
           src/OsmoseCore.cpp \
           src/RomSpecificOption.cpp \
           src/SmsEnvironment.cpp \
           src/SN76489.cpp \
           src/SoundThread.cpp \
           src/VDP.cpp \
           src/VDP_GG.cpp \
           src/WaveWriter.cpp
RESOURCES += src/OsmoseResources.qrc
