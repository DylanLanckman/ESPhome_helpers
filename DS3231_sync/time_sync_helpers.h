
// custom_components/ESPhome_helpers/time_sync_helpers.h
#include "esphome.h"
#include <Wire.h>
#include "RTClib.h"

void set_ds3231_time(esphome::i2c::I2CComponent *i2c_bus, uint8_t address, esphome::time::RealTimeClock &time) {
  // Initialize the RTC_DS3231 object
  RTC_DS3231 rtc;

  // Begin the I2C communication
  Wire.begin(i2c_bus->get_sda_pin(), i2c_bus->get_scl_pin());

  // Check if the RTC is connected and running
  if (!rtc.begin()) {
    ESP_LOGE("DS3231", "RTC not found");
    return;
  }

  // Set the time and date on the DS3231 RTC
  rtc.adjust(DateTime(time.year, time.month, time.day_of_month, time.hour, time.minute, time.second));
}
