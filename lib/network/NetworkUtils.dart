import 'dart:convert';
import 'dart:io';

import 'package:http/http.dart';
import 'package:http/http.dart' as http;

import '../main.dart';
import '../utils/Constants.dart';
import '../utils/Extensions/common.dart';
import '../utils/Extensions/network_utils.dart';
import '../utils/Extensions/shared_pref.dart';


Map<String, String> buildHeaderTokens() {
  Map<String, String> header = {
    HttpHeaders.contentTypeHeader: 'application/json',
    HttpHeaders.cacheControlHeader: 'no-cache',
    HttpHeaders.acceptHeader: 'application/json',
    'Access-Control-Allow-Headers': '*',
    'Access-Control-Allow-Origin': '*',
  };

  if (appStore.isLoggedIn) {
    header.putIfAbsent(
        HttpHeaders.authorizationHeader, () => 'Bearer ${getStringAsync(
        'TOKEN')}');
  }
  log(jsonEncode(header));
  return header;
}

Uri buildBaseUrl(String endPoint) {
  Uri url = Uri.parse(endPoint);
  if (!endPoint.startsWith('http')) url = Uri.parse('$mBaseUrl$endPoint');

  log('URL: ${url.toString()}');

  return url;
}

Future<Response> buildHttpResponse(String endPoint,
    {HttpMethod method = HttpMethod.GET, Map? request, String? req}) async {
  if (await isNetworkAvailable()) {
    var headers = {'token': getStringAsync('TOKEN')};
    Uri url = buildBaseUrl(endPoint);

    try {
      Response response;

      if (method == HttpMethod.POST) {
        log('Request: $request');

        response =
        await http.post(url, body: req ?? request, headers: headers)
            .timeout(Duration(seconds: 20), onTimeout: () => throw 'Timeout');
      } else if (method == HttpMethod.DELETE) {
        response = await delete(url, headers: headers).timeout(
            Duration(seconds: 20), onTimeout: () => throw 'Timeout');
      } else if (method == HttpMethod.PUT) {
        response =
        await put(url, body: req ?? jsonEncode(request), headers: headers)
            .timeout(Duration(seconds: 20), onTimeout: () => throw 'Timeout');
      } else {
        response = await get(url, headers: headers).timeout(
            Duration(seconds: 20), onTimeout: () => throw 'Timeout');
      }

      log('Response ($method): ${url.toString()} ${response
          .statusCode} ${response.body}');

      return response;
    } catch (e) {
      throw "Something went to wrong";
    }
  } else {
    throw "Please check your internet";
  }
}

//region Common

Future handleResponse(Response response, [bool? avoidTokenError]) async {
  print("data value handle res---->>${response.body.toString()}");
  if (!await isNetworkAvailable()) {
    throw "Please check your internet";
  }

  if (response.statusCode == 200) {
    return jsonDecode(response.body);
  } else {
    print("data statu value  ---->>>${response.statusCode}");
    try {
      var body = jsonDecode(response.body);
      throw parseHtmlString(body['message']);
    } on Exception catch (e) {
      log(e);
      throw "Something went to wrong";
    }
  }
}

enum HttpMethod { GET, POST, DELETE, PUT }

class TokenException implements Exception {
  final String message;

  const TokenException([this.message = ""]);

  String toString() => "FormatException: $message";
}
