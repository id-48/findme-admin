// To parse this JSON data, do
//
//     final resLoginUser = resLoginUserFromJson(jsonString);

import 'dart:convert';

ResLoginUser resLoginUserFromJson(String str) => ResLoginUser.fromJson(json.decode(str));

String resLoginUserToJson(ResLoginUser data) => json.encode(data.toJson());

class ResLoginUser {
  bool status;
  String reason;
  UserData data;
  String token;

  ResLoginUser({
    required this.status,
    required this.reason,
    required this.data,
    required this.token,
  });

  factory ResLoginUser.fromJson(Map<String, dynamic> json) => ResLoginUser(
    status: json["status"],
    reason: json["reason"],
    data: UserData.fromJson(json["data"]),
    token: json["token"],
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "reason": reason,
    "data": data.toJson(),
    "token": token,
  };
}

class UserData {
  String id;
  String adminName;
  String email;
  String password;
  DateTime createdAt;
  DateTime updatedAt;

  UserData({
    required this.id,
    required this.adminName,
    required this.email,
    required this.password,
    required this.createdAt,
    required this.updatedAt,
  });

  factory UserData.fromJson(Map<String, dynamic> json) => UserData(
    id: json["_id"],
    adminName: json["adminName"],
    email: json["email"],
    password: json["password"],
    createdAt: DateTime.parse(json["createdAt"]),
    updatedAt: DateTime.parse(json["updatedAt"]),
  );

  Map<String, dynamic> toJson() => {
    "_id": id,
    "adminName": adminName,
    "email": email,
    "password": password,
    "createdAt": createdAt.toIso8601String(),
    "updatedAt": updatedAt.toIso8601String(),
  };
}
