import 'dart:convert';

ResShowroom resShowroomFromJson(String str) =>
    ResShowroom.fromJson(json.decode(str));

String resShowroomToJson(ResShowroom data) => json.encode(data.toJson());

class ResShowroom {
  bool status;
  String message;
  Showroom showroom;

  ResShowroom({
    required this.status,
    required this.message,
    required this.showroom,
  });

  factory ResShowroom.fromJson(Map<String, dynamic> json) =>
      ResShowroom(
        status: json["status"],
        message: json["message"],
        showroom: Showroom.fromJson(json["showroom"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "showroom": showroom.toJson(),
      };
}

class Showroom {
  String id;
  String showroomId;
  String showroomName;
  String mobileNumber;
  String address;
  String city;
  String area;
  String password;
  DateTime createdAt;
  DateTime updatedAt;

  Showroom({
    required this.id,
    required this.showroomId,
    required this.showroomName,
    required this.mobileNumber,
    required this.address,
    required this.city,
    required this.area,
    required this.password,
    required this.createdAt,
    required this.updatedAt,
  });

  factory Showroom.fromJson(Map<String, dynamic> json) =>
      Showroom(
        id: json["_id"],
        showroomId: json["showroomId"],
        showroomName: json["showroomName"],
        mobileNumber: json["mobileNumber"],
        address: json["address"],
        city: json["city"],
        area: json["area"],
        password: json["password"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "showroomId": showroomId,
        "showroomName": showroomName,
        "mobileNumber": mobileNumber,
        "address": address,
        "city": city,
        "area": area,
        "password": password,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
