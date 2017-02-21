
#include <stdlib.h>
#include <string.h>

/* Scheduler include files. */
#include "../FreeRTOS/FreeRTOS.h"
#include "../FreeRTOS/task.h"

/* Demo file headers. */
#include "togglepins.h"

static void vLEDBlink_task(void * pvParameters) {
	uint16_t * parameters = (uint16_t *) pvParameters;
	uint16_t pin = parameters[0];
	uint16_t delay_ms = parameters[1];
	
	TickType_t xNextWakeTime = xTaskGetTickCount();
	const int delayTime = delay_ms / portTICK_PERIOD_MS;
	
	for(;;) {
		vPortBPinsToggle(pin);
		vTaskDelayUntil(&xNextWakeTime, delayTime);
	}
}

int main( void )
{
	/* Setup the LED's for output. */
	vPortBPinsInitialize();
	
	uint16_t config_1[] = {5, 250};
	uint16_t config_2[] = {4, 500};
	
	xTaskCreate(vLEDBlink_task, "LED Blink", configMINIMAL_STACK_SIZE, (void *) config_1, 1, NULL);
	xTaskCreate(vLEDBlink_task, "LED Other Blink", configMINIMAL_STACK_SIZE, (void *) config_2, 1, NULL);

	vTaskStartScheduler();
	
	for(;;);

	return 0;
}

