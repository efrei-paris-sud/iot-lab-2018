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

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "bme280.h"

#define MAX_READINGS    100

extern QueueHandle_t sensor_readings_queue;

struct a_reading {
    TickType_t timestamp;
    struct bme280_data data;
};

int8_t transmission_init(void);
int8_t transmission_enqueue(struct a_reading *reading);
int8_t transmission_dequeue(struct a_reading *reading);

int8_t make_a_reading(struct a_reading *reading, struct bme280_data *data);
void print_a_reading(const struct a_reading *reading);

void perform_transmissions(void *pvParameters);
