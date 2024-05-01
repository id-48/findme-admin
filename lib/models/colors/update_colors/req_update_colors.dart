import 'dart:convert';

ReqUpdateColors reqUpdateColorsFromJson(String str) =>
    ReqUpdateColors.fromJson(json.decode(str));

String reqUpdateColorsToJson(ReqUpdateColors data) =>
    json.encode(data.toJson());

class ReqUpdateColors {
  String colorsId;
  String colorsName;

  ReqUpdateColors({
    required this.colorsId,
    required this.colorsName,
  });

  factory ReqUpdateColors.fromJson(Map<String, dynamic> json) =>
      ReqUpdateColors(
        colorsId: json["colorsId"],
        colorsName: json["colorsName"],
      );

  Map<String, dynamic> toJson() =>
      {
        "colorsId": colorsId,
        "colorsName": colorsName,
      };
}
