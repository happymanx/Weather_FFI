//
// Created by ipad1@hukuibio.com on 2022/1/6.
//
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

double get_temperature()
{
  return 77.0f;
}

char* get_forecast() {
  char* forecast = "HappyBoy";
  char* forecast_m = malloc(strlen(forecast));
  strcpy(forecast_m, forecast);
  return forecast_m;
}

struct ThreeDayForecast  {
  double today;
  double tomorrow;
  double day_after;
};

double fahrenheit_to_celsius(double temperature) {
  return (5.0f / 9.0f) * (temperature - 32);
}

// 1
struct ThreeDayForecast get_three_day_forecast(bool useCelsius) {

  // 2
  struct ThreeDayForecast forecast;
  forecast.today = 77.0f;
  forecast.tomorrow = 78.0f;
  forecast.day_after = 79.0f;

  // 3
  if(useCelsius) {
    forecast.today = fahrenheit_to_celsius(forecast.today);
    forecast.tomorrow = fahrenheit_to_celsius(forecast.tomorrow);
    forecast.day_after = fahrenheit_to_celsius(forecast.day_after);
  }
  // 4
  return forecast;
}

/*
1. Accepts a bool indicating whether to return Celsius or Fahrenheit values.
2. Instantiates a struct with some very boring and static values, representing the forecasted temperature over the next three days.
3. Converts these values to Celsius if useCelsius is true.
4. Returns the struct.
*/