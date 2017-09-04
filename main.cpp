/* Teensyduino Core Library
 * http://www.pjrc.com/teensy/
 * Copyright (c) 2017 PJRC.COM, LLC.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * 1. The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * 2. If the Software is incorporated into a build system that allows
 * selection among a list of target devices, then similar target
 * devices manufactured by PJRC.COM must be included in the list of
 * target devices and selectable in the same manner.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "WProgram.h"
#include "Bounce2.h"

#define UP_PIN 2
#define DN_PIN 4
#define RT_PIN 5
#define LT_PIN 3
#define LC_PIN 6
#define RC_PIN 7
#define LED_PIN 13

Bounce upBtn = Bounce(UP_PIN, 10);
Bounce dnBtn = Bounce(DN_PIN, 10);
Bounce rtBtn = Bounce(RT_PIN, 10);
Bounce ltBtn = Bounce(LT_PIN, 10);
Bounce lcBtn = Bounce(LC_PIN, 10);
Bounce rcBtn = Bounce(RC_PIN, 10);

extern "C" int main(void) {
	pinMode(UP_PIN, INPUT);
	pinMode(DN_PIN, INPUT);
	pinMode(RT_PIN, INPUT);
	pinMode(LT_PIN, INPUT);
	pinMode(LC_PIN, INPUT);
	pinMode(RC_PIN, INPUT);

	pinMode(LED_PIN, OUTPUT);

	while (1)
	{
		upBtn.update();
		dnBtn.update();
		rtBtn.update();
		ltBtn.update();
		lcBtn.update();
		rcBtn.update();

		if(upBtn.read() == LOW)
		{
			Mouse.move(1,0);
		}

		if(dnBtn.read() == LOW)
		{
			Mouse.move(-1,0);
		}

		if(rtBtn.read() == LOW)
		{
			Mouse.move(0,-1);
		}

		if(ltBtn.read() == LOW)
		{
			Mouse.move(0,1);
		}

		if(lcBtn.fallingEdge())
		{
			Mouse.press(MOUSE_LEFT);
		}
		if(lcBtn.risingEdge())
		{
			Mouse.release(MOUSE_LEFT);
		}

		if(rcBtn.fallingEdge())
		{
			Mouse.press(MOUSE_RIGHT);
		}
		if(rcBtn.risingEdge())
		{
			Mouse.release(MOUSE_RIGHT);
		}
	}
}

