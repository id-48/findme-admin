// To parse this JSON data, do
//
//     final resUserProfile = resUserProfileFromJson(jsonString);

import 'dart:convert';

ResUserProfile resUserProfileFromJson(String str) => ResUserProfile.fromJson(json.decode(str));

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

  factory ResUserProfile.fromJson(Map<String, dynamic> json) => ResUserProfile(
    status: json["status"],
    message: json["message"],
    user: json["User"] == null ? null : User.fromJson(json["User"]),
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "message": message,
    "User": user?.toJson(),
  };
}

class User {
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
  String age;
  String email;
  String countryName;
  String userStatus;
  DateTime createdAt;
  DateTime updatedAt;

  User({
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
    required this.age,
    required this.email,
    required this.countryName,
    required this.userStatus,
    required this.createdAt,
    required this.updatedAt,
  });

  factory User.fromJson(Map<String, dynamic> json) => User(
    id: json["_id"],
    name: json["name"],
    age: json["age"],
    email: json["email"],
    profilePic: List<String>.from(json["profilePic"].map((x) => x)),
    bio: json["bio"],
    mono: json["mono"],
    countryCode: json["countryCode"],
    lastVisitedPlace: List<String>.from(json["lastVisitedPlace"].map((x) => x)),
    lattitude: json["lattitude"],
    longtitude: json["longtitude"],
    lastActivate: json["lastActivate"] == '' ? DateTime.now() : DateTime.parse(json['lastActivate']),
    gender: json["gender"],
    languages: List<String>.from(json["languages"].map((x) => x)),
    fcmToken: json["fcmToken"],
    userStatus: json["userStatus"],
    countryName: json["countryName"],
    createdAt: DateTime.parse(json["createdAt"]),
    updatedAt: DateTime.parse(json["updatedAt"]),
  );

  Map<String, dynamic> toJson() => {
    "_id": id,
    "name": name,
    "age": age,
    "email": email,
    "profilePic": List<dynamic>.from(profilePic.map((x) => x)),
    "bio": bio,
    "mono": mono,
    "countryCode": countryCode,
    "lastVisitedPlace": List<dynamic>.from(lastVisitedPlace.map((x) => x)),
    "lattitude": lattitude,
    "longtitude": longtitude,
    "lastActivate": lastActivate?.toIso8601String(),
    "gender": gender,
    "languages": List<dynamic>.from(languages.map((x) => x)),
    "fcmToken": fcmToken,
    "countryName": countryName,
    "userStatus": userStatus,
    "createdAt": createdAt.toIso8601String(),
    "updatedAt": updatedAt.toIso8601String(),
  };
}
