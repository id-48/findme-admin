// To parse this JSON data, do
//
//     final resAddEvent = resAddEventFromJson(jsonString);

import 'dart:convert';

ResAddEvent resAddEventFromJson(String str) =>
    ResAddEvent.fromJson(json.decode(str));

String resAddEventToJson(ResAddEvent data) => json.encode(data.toJson());

class ResAddEvent {
  bool status;
  String message;

  ResAddEvent({
    required this.status,
    required this.message,
  });

  factory ResAddEvent.fromJson(Map<String, dynamic> json) =>
      ResAddEvent(
        status: json["status"],
        message: json["message"],
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
      };
}
