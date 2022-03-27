import 'dart:ffi';
import 'dart:io';
import 'package:ffi/ffi.dart';

typedef TemperatureFunction = Double Function();
typedef TemperatureFunctionDart = double Function();
typedef ForecastFunction = Pointer<Utf8> Function();
typedef ForecastFunctionDart = Pointer<Utf8> Function();

typedef HelloFunction = Void Function();
typedef HelloFunctionDart = void Function();
typedef NameFunction = Pointer<Int8> Function();
typedef NameFunctionDart = Pointer<Int8> Function();
typedef PrintAndGetFunction = Pointer<Int8> Function(Pointer<Int8>);
typedef PrintAndGetFunctionDart = Pointer<Int8> Function(Pointer<Int8>);

//
typedef CppNumberFunction = Double Function();
typedef CppNumberFunctionDart = double Function();
typedef GetSumFunction = Int32 Function(Int32, Int32);
typedef GetSumFunctionDart = int Function(int, int);


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

  HelloFunctionDart _printHelloWorld;
  NameFunctionDart _getName;
  PrintAndGetFunctionDart _printAndGet;

  CppNumberFunctionDart _getCppNumber;
  GetSumFunctionDart _getSum;

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

    final _hello_worldPtr =
    dl.lookup<NativeFunction<HelloFunction>>('hello_world');
    _printHelloWorld = _hello_worldPtr.asFunction<HelloFunctionDart>();
    // 以上可合併如此行程式碼
    // _getHelloWorld = dl.lookupFunction<HelloFunction,
    //     HelloFunctionDart>('hello_world');

    final _getNamePtr =
    dl.lookup<NativeFunction<NameFunction>>('getName');
    _getName = _getNamePtr.asFunction<NameFunctionDart>();
    print('[Dart]: 有返回值 -> '+_getName().cast<Utf8>().toDartString());

    final _cPrintAndGetPtr =
    dl.lookup<NativeFunction<PrintAndGetFunction>>('cPrintAndGet');
    _printAndGet = _cPrintAndGetPtr.asFunction<PrintAndGetFunctionDart>();
    print('[Dart]: 有返回值 -> '+_printAndGet('我就是預設文'.toNativeUtf8().cast<Int8>())
        .cast<Utf8>().toDartString());

    //
    _getCppNumber = dl.lookupFunction<TemperatureFunction,
        TemperatureFunctionDart>('get_cpp_number');
    _getSum = dl.lookupFunction<GetSumFunction,
        GetSumFunctionDart>('get_sum');
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

  // 無傳參數，無返回值
  void printHelloWorld() {
    _printHelloWorld();
  }

  // 無傳參數，有返回值
  String getName() {
    return _getName().cast<Utf8>().toDartString();
  }

  // 有傳參數，有返回值
  String printAndGet(String str) {
    return _printAndGet(str.toNativeUtf8().cast<Int8>())
        .cast<Utf8>().toDartString();
  }

  //
  double getCppNumber() => _getCppNumber();

  int getSum(int a, int b) => _getSum(a, b);
}

/*
1. For Android, you call DynamicLibrary to find and open the shared library libweather.so. You don’t need to do this in iOS since all linked symbols map when an app runs.
2. Then you locate the correct function by specifying its native type signature and name. You use this information to bind to a Dart function with a specific type signature.
3. TemperatureFunction defines a native function that accepts no arguments and returns a native C double.
4. The lookup function is bound to the equivalent Dart function that returns a Dart double.
5. Assign getTemperature() the returned value from the returned double.
 */