// To parse this JSON data, do
//
//     final resAddUser = resAddUserFromJson(jsonString);

import 'dart:convert';

ResAddUser resAddUserFromJson(String str) => ResAddUser.fromJson(json.decode(str));

String resAddUserToJson(ResAddUser data) => json.encode(data.toJson());

class ResAddUser {
  bool status;
  String message;
  String token;

  ResAddUser({
    required this.status,
    required this.message,
    required this.token,
  });

  factory ResAddUser.fromJson(Map<String, dynamic> json) => ResAddUser(
    status: json["status"],
    message: json["message"],
    token: json["token"],
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "message": message,
    "token": token,
  };
}
//
// class User {
//   String id;
//   String firstName;
//   String lastName;
//   String userName;
//   List<String> profilePic;
//   String mono;
//   String address;
//   String lattitude;
//   String longtitude;
//   String countryName;
//   DateTime createdAt;
//   DateTime updatedAt;
//
//   User({
//     required this.id,
//     required this.firstName,
//     required this.lastName,
//     required this.userName,
//     required this.profilePic,
//     required this.mono,
//     required this.address,
//     required this.lattitude,
//     required this.longtitude,
//     required this.countryName,
//     required this.createdAt,
//     required this.updatedAt,
//   });
//
//   factory User.fromJson(Map<String, dynamic> json) => User(
//         id: json["_id"],
//         firstName: json["firstName"],
//         lastName: json["lastName"],
//         userName: json["userName"],
//         profilePic: List<String>.from(json["profilePic"].map((x) => x)),
//         mono: json["mono"],
//         address: json["address"],
//         lattitude: json["lattitude"],
//         longtitude: json["longtitude"],
//         countryName: json["countryName"],
//         createdAt: DateTime.parse(json["createdAt"]),
//         updatedAt: DateTime.parse(json["updatedAt"]),
//       );
//
//   Map<String, dynamic> toJson() => {
//         "_id": id,
//         "firstName": firstName,
//         "lastName": lastName,
//         "userName": userName,
//         "profilePic": List<dynamic>.from(profilePic.map((x) => x)),
//         "mono": mono,
//         "address": address,
//         "lattitude": lattitude,
//         "longtitude": longtitude,
//         "countryName": countryName,
//         "createdAt": createdAt.toIso8601String(),
//         "updatedAt": updatedAt.toIso8601String(),
//       };
// }
