/*
    LFMM, file: error_lfmm.c
    Copyright (C) 2012 Eric Frichot

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <R.h>

#include "error_lfmm.h"
#include "print_lfmm.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_error_lfmm(char *msg, char *file, int n)
{

        Rprintf("\n");
        if (!strcmp(msg, "cmd")) {
                Rprintf("ERROR: no value for %s.\n\n", file);
                print_help_lfmm();
        } else if (!strcmp(msg, "option")) {
                Rprintf("ERROR: the following option is mandatory: %s.\n\n",
                       file);
                print_help_lfmm();
        } else if (!strcmp(msg, "missing")) {
                Rprintf
                    ("ERROR: one of the following options is missing or not positive:"
                     " -K / -b / -i / -p / -d.\n\n");
                print_help_lfmm();
        } else if (!strcmp(msg, "basic")) {
                Rprintf("ERROR: the command is not written correctly.\n\n");
                print_help_lfmm();
        } else if (!strcmp(msg, "specific")) {
                Rprintf("ERROR: %s.\n\n", file);
                print_help_lfmm();
        } else {
                Rprintf("ERROR: Internal error.\n");
        }

        Rprintf("\n");
        error(NULL);
}
