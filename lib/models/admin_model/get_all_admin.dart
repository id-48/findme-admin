// To parse this JSON data, do
//
//     final resGetAllAdmin = resGetAllAdminFromJson(jsonString);

import 'dart:convert';

ResGetAllAdmin resGetAllAdminFromJson(String str) => ResGetAllAdmin.fromJson(json.decode(str));

String resGetAllAdminToJson(ResGetAllAdmin data) => json.encode(data.toJson());

class ResGetAllAdmin {
  bool status;
  String message;
  int totalUser;
  List<Admin> user;

  ResGetAllAdmin({
    required this.status,
    required this.message,
    required this.totalUser,
    required this.user,
  });

  factory ResGetAllAdmin.fromJson(Map<String, dynamic> json) => ResGetAllAdmin(
    status: json["status"],
    message: json["message"],
    totalUser: json["totalUser"],
    user: List<Admin>.from(json["User"].map((x) => Admin.fromJson(x))),
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "message": message,
    "totalUser": totalUser,
    "User": List<dynamic>.from(user.map((x) => x.toJson())),
  };
}

class Admin {
  String id;
  String adminName;
  String email;
  String password;
  DateTime createdAt;
  DateTime updatedAt;

  Admin({
    required this.id,
    required this.adminName,
    required this.email,
    required this.password,
    required this.createdAt,
    required this.updatedAt,
  });

  factory Admin.fromJson(Map<String, dynamic> json) => Admin(
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
