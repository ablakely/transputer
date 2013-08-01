/*
 * transputre.ino: Transputer Hardware Interface
 *
 * http://ephasic.org/transputer
 * Written by Aaron Blakely <aaron@ephasic.org>
 */

#include "server.h"

void setup()
{
	Server.begin();
}

void loop()
{
	Server.poll();
}
