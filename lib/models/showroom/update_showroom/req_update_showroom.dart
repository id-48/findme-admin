import 'dart:convert';

ReqUpdateShowroom reqUpdateShowroomFromJson(String str) =>
    ReqUpdateShowroom.fromJson(json.decode(str));

String reqUpdateShowroomToJson(ReqUpdateShowroom data) =>
    json.encode(data.toJson());

class ReqUpdateShowroom {
  String showroomId;
  String showroomName;
  String mobileNumber;
  String address;
  String city;
  String area;
  String password;

  ReqUpdateShowroom({
    required this.showroomId,
    required this.showroomName,
    required this.mobileNumber,
    required this.address,
    required this.city,
    required this.area,
    required this.password,
  });

  factory ReqUpdateShowroom.fromJson(Map<String, dynamic> json) =>
      ReqUpdateShowroom(
        showroomId: json["showroomId"],
        showroomName: json["showroomName"],
        mobileNumber: json["mobileNumber"],
        address: json["address"],
        city: json["city"],
        area: json["area"],
        password: json["password"],
      );

  Map<String, dynamic> toJson() => {
        "showroomId": showroomId,
        "showroomName": showroomName,
        "mobileNumber": mobileNumber,
        "address": address,
        "city": city,
        "area": area,
        "password": password,
      };
}
