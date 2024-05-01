import 'dart:convert';

ReqAddShowroom reqAddShowroomFromJson(String str) =>
    ReqAddShowroom.fromJson(json.decode(str));

String reqAddShowroomToJson(ReqAddShowroom data) => json.encode(data.toJson());

class ReqAddShowroom {
  String showroomName;
  String mobileNumber;
  String address;
  String city;
  String area;
  String password;

  ReqAddShowroom({
    required this.showroomName,
    required this.mobileNumber,
    required this.address,
    required this.city,
    required this.area,
    required this.password,
  });

  factory ReqAddShowroom.fromJson(Map<String, dynamic> json) =>
      ReqAddShowroom(
        showroomName: json["showroomName"],
        mobileNumber: json["mobileNumber"],
        address: json["address"],
        city: json["city"],
        area: json["area"],
        password: json["password"],
      );

  Map<String, dynamic> toJson() =>
      {
        "showroomName": showroomName,
        "mobileNumber": mobileNumber,
        "address": address,
        "city": city,
        "area": area,
        "password": password,
      };
}
