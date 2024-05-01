import 'dart:convert';

ReqColors reqColorsFromJson(String str) => ReqColors.fromJson(json.decode(str));

String reqColorsToJson(ReqColors data) => json.encode(data.toJson());

class ReqColors {
  String colorsName;

  ReqColors({
    required this.colorsName,
  });

  factory ReqColors.fromJson(Map<String, dynamic> json) =>
      ReqColors(
        colorsName: json["colorsName"],
      );

  Map<String, dynamic> toJson() =>
      {
        "colorsName": colorsName,
      };
}
