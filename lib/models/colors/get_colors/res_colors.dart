import 'dart:convert';

ResColors resColorsFromJson(String str) => ResColors.fromJson(json.decode(str));

String resColorsToJson(ResColors data) => json.encode(data.toJson());

class ResColors {
  bool status;
  String message;
  int totalColors;
  List<ColorsData> colors;

  ResColors({
    required this.status,
    required this.message,
    required this.totalColors,
    required this.colors,
  });

  factory ResColors.fromJson(Map<String, dynamic> json) =>
      ResColors(
        status: json["status"],
        message: json["message"],
        totalColors: json["totalColors"],
        colors: List<ColorsData>.from(
            json["colors"].map((x) => ColorsData.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalColors": totalColors,
        "colors": List<dynamic>.from(colors.map((x) => x.toJson())),
      };
}

class ColorsData {
  String id;
  String colorsName;
  DateTime createdAt;
  DateTime updatedAt;

  ColorsData({
    required this.id,
    required this.colorsName,
    required this.createdAt,
    required this.updatedAt,
  });

  factory ColorsData.fromJson(Map<String, dynamic> json) =>
      ColorsData(
        id: json["_id"],
        colorsName: json["colorsName"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "colorsName": colorsName,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
