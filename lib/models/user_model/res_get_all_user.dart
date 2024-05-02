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
  List<AllUser> user;

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
        user: List<AllUser>.from(json["User"].map((x) => AllUser.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalUser": totalUser,
        "User": List<dynamic>.from(user.map((x) => x.toJson())),
      };
}


class AllUser {
  String id;
  String name;
  List<String> profilePic;
  String bio;
  String mono;
  String countryCode;
  List<String> lastVisitedPlace;
  String lattitude;
  String longtitude;
  DateTime lastActivate;
  String gender;
  List<String> languages;
  String fcmToken;
  DateTime createdAt;
  DateTime updatedAt;

  AllUser({
    required this.id,
    required this.name,
    required this.profilePic,
    required this.bio,
    required this.mono,
    required this.countryCode,
    required this.lastVisitedPlace,
    required this.lattitude,
    required this.longtitude,
    required this.lastActivate,
    required this.gender,
    required this.languages,
    required this.fcmToken,
    required this.createdAt,
    required this.updatedAt,
  });

  factory AllUser.fromJson(Map<String, dynamic> json) => AllUser(
    id: json["_id"],
    name: json["name"],
    profilePic: List<String>.from(json["profilePic"].map((x) => x)),
    bio: json["bio"],
    mono: json["mono"],
    countryCode: json["countryCode"],
    lastVisitedPlace: List<String>.from(json["lastVisitedPlace"].map((x) => x)),
    lattitude: json["lattitude"],
    longtitude: json["longtitude"],
    lastActivate: DateTime.parse(json["lastActivate"]),
    gender: json["gender"],
    languages: List<String>.from(json["languages"].map((x) => x)),
    fcmToken: json["fcmToken"],
    createdAt: DateTime.parse(json["createdAt"]),
    updatedAt: DateTime.parse(json["updatedAt"]),
  );

  Map<String, dynamic> toJson() => {
    "_id": id,
    "name": name,
    "profilePic": List<dynamic>.from(profilePic.map((x) => x)),
    "bio": bio,
    "mono": mono,
    "countryCode": countryCode,
    "lastVisitedPlace": List<dynamic>.from(lastVisitedPlace.map((x) => x)),
    "lattitude": lattitude,
    "longtitude": longtitude,
    "lastActivate": lastActivate.toIso8601String(),
    "gender": gender,
    "languages": List<dynamic>.from(languages.map((x) => x)),
    "fcmToken": fcmToken,
    "createdAt": createdAt.toIso8601String(),
    "updatedAt": updatedAt.toIso8601String(),
  };
}
