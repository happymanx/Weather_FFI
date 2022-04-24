// Copyright (c) 2021 Razeware LLC
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
//     copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom
// the Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// Notwithstanding the foregoing, you may not use, copy, modify,
//     merge, publish, distribute, sublicense, create a derivative work,
// and/or sell copies of the Software in any work that is designed,
// intended, or marketed for pedagogical or instructional purposes
// related to programming, coding, application development, or
// information technology. Permission for such use, copying,
//     modification, merger, publication, distribution, sublicensing,
//     creation of derivative works, or sale is expressly withheld.
//
// This project and source code may use libraries or frameworks
// that are released under various Open-Source licenses. Use of
// those libraries and frameworks are governed by their own
// individual licenses.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

import 'dart:io';
import 'package:http/http.dart' as http;
import 'package:flutter/material.dart';
import 'package:path_provider/path_provider.dart';
import 'ffi_bridge.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {

  const MyApp({Key key}) : super(key:key);
  
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Happy Flutter Demo',
      theme: ThemeData(
        primarySwatch: Colors.amber,
      ),
      home: const MyHomePage(title: 'Happy Flutter Demo Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({Key key, this.title}) : super(key: key);

  final String title;

  @override
  _MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  final FFIBridge _ffiBridge = FFIBridge();

  void _show(message) {
    showDialog(
        builder: (ctx) => AlertDialog(
            content: Text(message.toString()),
            backgroundColor: Colors.lightBlueAccent,
            shape: const StadiumBorder(),
            contentTextStyle: const TextStyle(color: Colors.white),
        ),
        context: context);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: <Widget>[
            ElevatedButton(
                child: const Text('Temperature'),
                onPressed: () async {
                  _show(_ffiBridge.getTemperature());
                }),
            ElevatedButton(
                child: const Text('Today\'s forecast'),
                onPressed: () {
                  _show(_ffiBridge.getForecast());
                }),
            ElevatedButton(
                child: const Text('3-day forecast (Fahrenheit)'),
                onPressed: () {
                  _show(_ffiBridge.getThreeDayForecast(false));
                }),
            ElevatedButton(
                child: const Text('3-day forecast (Celsius)'),
                onPressed: () {
                  _show(_ffiBridge.getThreeDayForecast(true));
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightBlue),
                ),
                child: const Text('Hello World'),
                onPressed: () {
                  _ffiBridge.printHelloWorld();
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightBlue),
                ),
                child: const Text('Name'),
                onPressed: () {
                  _show(_ffiBridge.getName());
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightBlue),
                ),
                child: const Text('Print And Get'),
                onPressed: () {
                  _show(_ffiBridge.printAndGet('猜猜我是誰？'));
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.redAccent),
                ),
                child: const Text('Cpp Number'),
                onPressed: () async {
                  _show(_ffiBridge.getCppNumber());
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.redAccent),
                ),
                child: const Text('Cpp Get Sum'),
                onPressed: () async {
                  _show(_ffiBridge.getSum(7, 8));
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightGreen),
                ),
                child: const Text('EchoSCU'),
                onPressed: () async {

                  final result = _ffiBridge.echoSCU(7, './echoscu -v -aet ECHOSCU -aec ANY-SCP 192.168.0.18 5678');
                  // 192.168.0.18
                  if (result == 0) {
                    _show('Success!! ' + result.toString());
                  }
                  else {
                    _show('Fail~~ ' + result.toString());
                  }
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightGreen),
                ),
                child: const Text('FindSCU'),
                onPressed: () async {

                  final result = _ffiBridge.findSCU(7, './findscu -v -aet DebugTest -aec MGIUSDICOM -k 0x0010,0x0010="HukuiBio" 192.168.0.18 5678');
                  // 192.168.0.18
                  if (result == 0) {
                    _show('Success!!! ' + result.toString());
                  }
                  else {
                    _show('Fail~~~ ' + result.toString());
                  }
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightGreen),
                ),
                child: const Text('GetSCU'),
                onPressed: () async {

                  final result = _ffiBridge.getSCU(7, './getscu -v -aet DebugTest -aec MGIUSDICOM -pdu 32768 -k 0x0010,0x0010="HukuiBio" 192.168.0.18 5678');
                  // 192.168.0.18
                  if (result == 0) {
                    _show('Success!!!! ' + result.toString());
                  }
                  else {
                    _show('Fail~~~~ ' + result.toString());
                  }
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightGreen),
                ),
                child: const Text('Img2dcm'),
                onPressed: () async {
                  final appDocDir = await getApplicationDocumentsDirectory();
                  final appDocPath = appDocDir.path;
                  final imagePath = '$appDocPath/imagetest.jpg';
                  final dcmPath = '$appDocPath/out.dcm';

                  // 取得網路圖片並儲存到 App
                  _fileFromImageUrl();

                  final result = _ffiBridge.img2dcm(7, './img2dcm '+ imagePath + ' ' + dcmPath + ' -k PatientName=HappyDogQ! -k PatientID=2204241');
                  // ./img2dcm dog.jpg outdog.dcm -k PatientName=HappyDog -k PatientID=7777
                  if (result == 0) {
                    _show('Success!!! ' + result.toString());
                  }
                  else {
                    _show('Fail~~~ ' + result.toString());
                  }
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightGreen),
                ),
                child: const Text('Dcmdjpeg'),
                onPressed: () async {
                  final appDocDir = await getApplicationDocumentsDirectory();
                  final appDocPath = appDocDir.path;
                  final dcmPath = '$appDocPath/out.dcm';
                  final dcm2Path = '$appDocPath/out2.dcm';

                  final result = _ffiBridge.dcmdjpeg(7, './dcmdjpeg '+ dcmPath + ' ' + dcm2Path);
                  // ./dcmdjpeg outdog.dcm outdog2.dcm
                  if (result == 0) {
                    _show('Success!!! ' + result.toString());
                  }
                  else {
                    _show('Fail~~~ ' + result.toString());
                  }
                  final File dcmFile = File(dcmPath);
                  dcmFile.delete();
                }),
            ElevatedButton(
                style: ButtonStyle(
                  backgroundColor: MaterialStateProperty.all(Colors.lightGreen),
                ),
                child: const Text('StoreSCU'),
                onPressed: () async {
                  final appDocDir = await getApplicationDocumentsDirectory();
                  final appDocPath = appDocDir.path;
                  final dcm2Path = '$appDocPath/out2.dcm';

                  final result = _ffiBridge.storeSCU(7, './storescu 192.168.0.18 5678 ' + dcm2Path);
                  // ./storescu 192.168.0.18 5678 outdog2.dcm
                  if (result == 0) {
                    _show('Success!!! ' + result.toString());
                  }
                  else {
                    _show('Fail~~~ ' + result.toString());
                  }
                  final File dcmFile = File(dcm2Path);
                  dcmFile.delete();
                }),
          ],
        ),
      ),
    );
  }

  Future<File> _fileFromImageUrl() async {
    final url = Uri.parse('https://upload.wikimedia.org/wikipedia/commons/1/18/Dog_Breeds.jpg');
    // https://thumbs.dreamstime.com/b/hund-open-mouth-3635912.jpg
    final response = await http.get(url);
    final documentDirectory = await getApplicationDocumentsDirectory();
    final file = File(documentDirectory.path+'/imagetest.jpg');
    file.writeAsBytesSync(response.bodyBytes);
    return file;
  }
}
