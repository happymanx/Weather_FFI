# Weather_FFI
Just test the Flutter ffi pattern

Learn from the article:

## Calling Native Libraries in Flutter with Dart FFI
https://www.raywenderlich.com/21512310-calling-native-libraries-in-flutter-with-dart-ffi

In the process, you’ll learn:

1. About FFI and how it lets Dart code invoke code written in other languages.
2. How FFI differs from Flutter platform channels.
3. To automatically compile and link C code when building a Flutter app.
4. How a Flutter app can use FFI to call code written in C.

<img src="/Screenshots/iOS_Screenshot1.PNG" width="300" />

1. Wrote a C function.
2. Compiled this function into a shared object and linked it into your Flutter app.
3. Used FFI to locate the library and function signature.
4. Bound the native function to a Dart function.
5. Invoked the Dart function to return a double from the C function.

--

<img src="/Screenshots/iOS_Screenshot2.PNG" width="300" />

1. Obtain a native char pointer.
2. Convert the pointer to a UTF8/Dart String.
3. Free the allocated memory.
4. Pass the String back to your Flutter widget.

--

<img src="/Screenshots/iOS_Screenshot3.PNG" width="300" />

1. Accepts a bool indicating whether to return Celsius or Fahrenheit values.
2. Instantiates a struct with some very boring and static values, representing the forecasted temperature over the next three days.
3. Converts these values to Celsius if useCelsius is true.
4. Returns the struct.
