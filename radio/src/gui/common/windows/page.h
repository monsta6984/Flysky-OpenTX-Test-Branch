/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _PAGE_H_
#define _PAGE_H_

#include "window.h"

class Page;

class PageHeader: public Window {
  public:
    PageHeader(Page * parent);

    virtual void paint(BitmapBuffer * dc) override
    {
      dc->drawSolidFilledRect(TOPBAR_BUTTON_WIDTH, 0, LCD_W - TOPBAR_BUTTON_WIDTH, TOPBAR_BUTTON_WIDTH, HEADER_BGCOLOR);
    }

  protected:
    IconButton back;
};

class Page: public Window {
  public:
    Page():
      Window(&mainWindow, {0, 0, LCD_W, LCD_H}),
      header(this),
      body(this, { 0, MENU_BODY_TOP, LCD_W, MENU_BODY_HEIGHT })
    {
    }

    virtual bool onTouchStart(coord_t x, coord_t y) {
      Window::onTouchStart(x, y);
      return true;
    }

    virtual bool onTouchEnd(coord_t x, coord_t y) {
      Window::onTouchEnd(x, y);
      return true;
    }

    virtual bool onTouchSlide(coord_t x, coord_t y, coord_t startX, coord_t startY, coord_t slideX, coord_t slideY) {
      Window::onTouchSlide(x, y, startX, startY, slideX, slideY);
      return true;
    }

    virtual void paint(BitmapBuffer * dc) override
    {
      dc->clear(TEXT_BGCOLOR);
    }

  protected:
    PageHeader header;
    Window body;
};

#endif // _PAGE_H_
