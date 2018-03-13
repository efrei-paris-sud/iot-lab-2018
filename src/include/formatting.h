/*
 * IoT-Labs-2018 
 * Copyright (C) 2018 Massinissa Hamidi 
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <errno.h>
#include "cJSON.h"

#include "transmission.h"

int8_t json_of_reading(cJSON *json, const struct a_reading *reading);
int8_t json_of_readings(cJSON *json, const struct a_reading **readings);
int8_t string_of_json(char *buff, cJSON *json);
int8_t reading_formatting(char *representation, const struct a_reading *reading);

