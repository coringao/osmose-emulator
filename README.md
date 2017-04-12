           _______                  _______
          |       |.-----.--------.|       |.-----.-----.
          |   -   ||__ --|        ||   -   ||__ --|  -__|
          |_______||_____|__|__|__||_______||_____|_____|
           _______                  __         __
          |    ___|.--------.--.--.|  |.---.-.|  |_.-----.----.
          |    ___||        |  |  ||  ||  _  ||   _|  _  |   _|
          |_______||__|__|__|_____||__||___._||____|_____|__|
        Public release, re-written and contributor by Carlos Donizete Froes.
        Holder by copyright Bruno Vedder.

### Osmose Emulator means

In brief it's an Sega Master System/Game Gear emulator encapsulated into C++ classes.

*What's new:*
-----------
Osmose Emulator owns a clean graphical user interface based on QT version 5.x,
GUI lib powerful enough to refresh display at 60hz.

	- Switch sound system to use ALSA
	- GUI development using QT.
	- Rendering/Key mapping adapted to QTopenGL.
	- Configuration system rewritten.

*Dependencies for Debian/Ubuntu Linux:*
---------------------------------------

    # apt install libasound2-dev libqt5opengl5-dev qt5-qmake qtbase5-dev qtchooser zlib1g-dev

*Compilation:*
--------------
To build osmose emulator, do from the source directory.

*Starting compilation:*

    $ qmake
  
    $ make

*Removing compilation:*

    $ make clean

    $ make distclean

*Vertical synchronisation:*
---------------------------
Osmose Emulator uses double buffering to avoid tearing image on the screen, but this does 
not guaranty that the rendering will be synchronized with the screen rendering.

Keep in mind that Osmose Emulator uses openGL for rendering and filtering.

Synchronisation is a matter of choice : High frames per second or Synchronisation.

On Ubuntu, the closed source driver provide an option in the tab performance: 'Sync to VBlank'.

When selected the rendering is stable, without flickering.

The CPU usage is a bit higher.

Without this option, the Osmose Emulator rendering is sometime teared but uses lower CPU.

I suppose that this option is available on all the drivers. Make your choice!

*Sound:*
--------
Osmose Emulator uses ALSA for the sound system.

It has been reported that concurrent application using the sound channel can inhibit osmose sound rendering.

So, avoid watching videos while playing with osmose !


*Features:*
-----------
- [1]SMS: Good compatibility. At this stage, the emulator can run 96% of commercial games and public demos, except games that relies on codemaster mapper, which work  but does not have proper video mode emulated.
- [1]Game Gear: Good compatibility. At this stage, the emulator can run 98% of game gear ROMS.
- SN76489 Sound is supported.
- Support for ".sms"  and ".gg" format.
- Video filters: bilinear or nearest neighbour (default)
- Pad(keyboard or joystick mapped) emulation.
- PAL/NTSC Timing.
- Japanese/Export console.
- In game Screenshots, GFX rip, sound shot.
- Configurable keyboard configuration.
- Joystick support, congigurable button assignement.
- Drag and drop your ROMS into the emulator window to run games.
    
[1] - Due to the huge number of game gear/master system (around 1300) roms, games have not been deeply tested.

-----

Need more information or contact with authors:

- © 2001-2011 Copyright holder Bruno Vedder <bruno@asterope.fr>
- © 2016-2017 Contributor Carlos Donizete Froes [a.k.a coringao] <coringao@riseup.net>

* This file was officially downloaded from : http://bcz.asterope.fr
* Continuation of the project from: https://github.com/coringao/osmose-emulator
