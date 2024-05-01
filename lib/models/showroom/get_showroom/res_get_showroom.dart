import 'dart:convert';

ResGetShowroom resGetShowroomFromJson(String str) =>
    ResGetShowroom.fromJson(json.decode(str));

String resGetShowroomToJson(ResGetShowroom data) => json.encode(data.toJson());

class ResGetShowroom {
  bool status;
  String message;
  int totalShowroom;
  List<Showroom> showroom;

  ResGetShowroom({
    required this.status,
    required this.message,
    required this.totalShowroom,
    required this.showroom,
  });

  factory ResGetShowroom.fromJson(Map<String, dynamic> json) =>
      ResGetShowroom(
        status: json["status"],
        message: json["message"],
        totalShowroom: json["totalShowroom"],
        showroom: List<Showroom>.from(
            json["showroom"].map((x) => Showroom.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalShowroom": totalShowroom,
        "showroom": List<dynamic>.from(showroom.map((x) => x.toJson())),
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
