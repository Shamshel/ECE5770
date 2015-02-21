//util.c

/*
 * Written by Cody Herndon in conjunction with David Petrizze for ECE 3710, Fall 2013
 */

#include "util.h"

void util_delayMS(int _ms)
{
	_ms *= 3800;  //TODO: tune this
	while(_ms --);
}
