// To parse this JSON data, do
//
//     final resCheckExistUser = resCheckExistUserFromJson(jsonString);

import 'dart:convert';

ResCheckExistUser resCheckExistUserFromJson(String str) =>
    ResCheckExistUser.fromJson(json.decode(str));

String resCheckExistUserToJson(ResCheckExistUser data) =>
    json.encode(data.toJson());

class ResCheckExistUser {
  bool status;
  String message;
  String token;

  ResCheckExistUser({
    required this.status,
    required this.message,
    required this.token,
  });

  factory ResCheckExistUser.fromJson(Map<String, dynamic> json) =>
      ResCheckExistUser(
        status: json["status"],
        message: json["message"],
        token: json["token"],
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "token": token,
      };
}
