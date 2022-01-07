import 'dart:ffi';
import 'dart:io';
import 'package:ffi/ffi.dart';

typedef TemperatureFunction = Double Function();
typedef TemperatureFunctionDart = double Function();
typedef ForecastFunction = Pointer<Utf8> Function();
typedef ForecastFunctionDart = Pointer<Utf8> Function();

class ThreeDayForecast extends Struct {
  // 1
  @Double()
  external double get today;
  external set today(double value);

  @Double()
  external double get tomorrow;
  external set tomorrow(double value);

  @Double()
  external double get day_after;
  external set day_after(double value);

  // 2
  @override
  String toString() {
    return 'Today : ${today.toStringAsFixed(1)}\n'
        'Tomorrow : ${tomorrow.toStringAsFixed(1)}\n'
        'Day After : ${day_after.toStringAsFixed(1)}';
  }
}

// 3
typedef ThreeDayForecastFunction = ThreeDayForecast Function(Uint8 useCelsius);
typedef ThreeDayForecastFunctionDart = ThreeDayForecast Function(
    int useCelsius);

/*
1. The Double() annotation indicates the native type of each field to Dart FFI.
2. You return the forecast listed to one decimal point.
3. The typedef indicates the method will have a return type of this class and expects a single int (Dart) / Uint8 C argument. There’s no matching FFI Boolean type, so you use an unsigned 8-bit integer instead.
 */


class FFIBridge {
  TemperatureFunctionDart _getTemperature;
  ForecastFunctionDart _getForecast;
  ThreeDayForecastFunctionDart _getThreeDayForecast;

  FFIBridge() {
    // 1
    final dl = Platform.isAndroid
        ? DynamicLibrary.open('libweather.so')
        : DynamicLibrary.process();

    _getTemperature = dl
    // 2
        .lookupFunction<
    // 3
        TemperatureFunction,
    // 4
        TemperatureFunctionDart>('get_temperature');

    _getForecast = dl
        .lookupFunction<ForecastFunction, ForecastFunctionDart>('get_forecast');

    _getThreeDayForecast = dl.lookupFunction<ThreeDayForecastFunction,
        ThreeDayForecastFunctionDart>('get_three_day_forecast');
  }

  // 5
  double getTemperature() => _getTemperature();

  String getForecast() {
    final ptr = _getForecast();
    final forecast = ptr.toDartString();
    calloc.free(ptr);
    return forecast;
  }

  ThreeDayForecast getThreeDayForecast(bool useCelsius) {
    return _getThreeDayForecast(useCelsius ? 1 : 0);
  }
}

/*
1. For Android, you call DynamicLibrary to find and open the shared library libweather.so. You don’t need to do this in iOS since all linked symbols map when an app runs.
2. Then you locate the correct function by specifying its native type signature and name. You use this information to bind to a Dart function with a specific type signature.
3. TemperatureFunction defines a native function that accepts no arguments and returns a native C double.
4. The lookup function is bound to the equivalent Dart function that returns a Dart double.
5. Assign getTemperature() the returned value from the returned double.
 */