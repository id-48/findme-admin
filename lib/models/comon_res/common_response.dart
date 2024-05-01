import 'dart:convert';

CommonResponse commonResponseFromJson(String str) =>
    CommonResponse.fromJson(json.decode(str));

String commonResponseToJson(CommonResponse data) => json.encode(data.toJson());

class CommonResponse {
  bool status;
  String message;

  CommonResponse({
    required this.status,
    required this.message,
  });

  factory CommonResponse.fromJson(Map<String, dynamic> json) =>
      CommonResponse(
        status: json["status"],
        message: json["message"],
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
      };
}
