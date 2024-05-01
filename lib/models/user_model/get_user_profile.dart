// To parse this JSON data, do
//
//     final resUserProfile = resUserProfileFromJson(jsonString);

import 'dart:convert';

ResUserProfile resUserProfileFromJson(String str) =>
    ResUserProfile.fromJson(json.decode(str));

String resUserProfileToJson(ResUserProfile data) => json.encode(data.toJson());

class ResUserProfile {
  bool status;
  String message;
  User? user;

  ResUserProfile({
    required this.status,
    required this.message,
    required this.user,
  });

  factory ResUserProfile.fromJson(Map<String, dynamic> json) =>
      ResUserProfile(
        status: json["status"],
        message: json["message"],
        user: json["User"] == null ? null : User.fromJson(json["User"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "User": user?.toJson(),
      };
}

class User {
  String id;
  String firstName;
  String lastName;
  String userName;
  List<String> profilePic;
  String mono;
  String countryCode;
  String address;
  String lattitude;
  String longtitude;
  String countryName;
  String fcmToken;
  DateTime createdAt;
  DateTime updatedAt;

  User({
    required this.id,
    required this.firstName,
    required this.lastName,
    required this.userName,
    required this.profilePic,
    required this.mono,
    required this.countryCode,
    required this.address,
    required this.lattitude,
    required this.longtitude,
    required this.countryName,
    required this.fcmToken,
    required this.createdAt,
    required this.updatedAt,
  });

  factory User.fromJson(Map<String, dynamic> json) =>
      User(
        id: json["_id"],
        firstName: json["firstName"],
        lastName: json["lastName"],
        userName: json["userName"],
        profilePic: List<String>.from(json["profilePic"].map((x) => x)),
        mono: json["mono"],
        countryCode: json["countryCode"],
        address: json["address"],
        lattitude: json["lattitude"],
        longtitude: json["longtitude"],
        countryName: json["countryName"],
        fcmToken: json["fcmToken"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "firstName": firstName,
        "lastName": lastName,
        "userName": userName,
        "profilePic": List<dynamic>.from(profilePic.map((x) => x)),
        "mono": mono,
        "countryCode": countryCode,
        "address": address,
        "lattitude": lattitude,
        "longtitude": longtitude,
        "countryName": countryName,
        "fcmToken": fcmToken,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}