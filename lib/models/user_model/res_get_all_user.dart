// To parse this JSON data, do
//
//     final ResGetAllUser = ResGetAllUserFromJson(jsonString);

import 'dart:convert';

import 'get_user_profile.dart';

ResGetAllUser resGetAllUserFromJson(String str) =>
    ResGetAllUser.fromJson(json.decode(str));

String resGetAllUserToJson(ResGetAllUser data) => json.encode(data.toJson());

class ResGetAllUser {
  bool status;
  String message;
  int totalUser;
  List<User> user;

  ResGetAllUser({
    required this.status,
    required this.message,
    required this.totalUser,
    required this.user,
  });

  factory ResGetAllUser.fromJson(Map<String, dynamic> json) =>
      ResGetAllUser(
        status: json["status"],
        message: json["message"],
        totalUser: json["totalUser"],
        user: List<User>.from(json["User"].map((x) => User.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalUser": totalUser,
        "User": List<dynamic>.from(user.map((x) => x.toJson())),
      };
}

