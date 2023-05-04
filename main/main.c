#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "esp_heap_caps.h"

void getMemoryView();

void app_main(void)
{
  getMemoryView();

  while (1)
  {
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void getMemoryView()
{
  printf("Memory Verification\n");

  int heap = (xPortGetFreeHeapSize()) / 1024;
  int dRam = (heap_caps_get_free_size(MALLOC_CAP_8BIT)) / 1024;
  int iRam = (heap_caps_get_free_size(MALLOC_CAP_32BIT) - heap_caps_get_free_size(MALLOC_CAP_8BIT)) / 1024;

  int freeBlock = (heap_caps_get_largest_free_block(MALLOC_CAP_8BIT)) / 1024;

  printf("Heap %d kB\n", heap);
  printf("DRam %d kB\n", dRam);
  printf("IRam %d kB\n", iRam);
  printf("Maximum free block %d kB\n ", freeBlock);
}
