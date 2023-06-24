/*
 *  Gascop
 *
 *  Copyright (C) 2011-2014 Clive Cooper.
 *
 *  Gascop is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of the
 *  License, or (at your option) any later version.
 *
 *  Gascop is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Author: Clive Cooper,
 *
 */
#include <QApplication>
#include "mainwin.h"
#include <QtDebug>
//
int main(int argc, char ** argv)
{
  QApplication app(argc, argv);
  MainWin win;

  if(SDL_Init(SDL_INIT_AUDIO) != 0) // Initialize SDL audio
  {
    return -1;
  }

  // Enumerate the sound cards!
  const int count = SDL_GetNumAudioDevices(0);
  for (int i = 0; i < count; ++i) {
      win.mixer_device->addItem(SDL_GetAudioDeviceName(i, 0));
      //displayMessages(SDL_GetAudioDeviceName(i, 0));
  }


  win.show();
  app.connect(&app, SIGNAL(lastWindowClosed()), &app, SLOT(quit()));
  return app.exec();
}
