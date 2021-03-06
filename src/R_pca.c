/*
   pca, file: main.c
   Copyright (C) 2013 François Mathieu, Eric Frichot

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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "pca/pca.h"

#include "R_pca.h"

void R_pca(char **R_input_file, char **R_output_eva_file,
        char **R_output_eve_file, char **R_output_sdev_file,
        char **R_output_x_file, int *n, int *L, int *K, int *c, int *s)
{
        pca(*R_input_file,
            *R_output_eva_file,
            *R_output_eve_file,
            *R_output_sdev_file, *R_output_x_file, n, L, K, *c, *s);
}
