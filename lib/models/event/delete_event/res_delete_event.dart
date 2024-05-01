// To parse this JSON data, do
//
//     final resDeleteEvent = resDeleteEventFromJson(jsonString);

import 'dart:convert';

ResDeleteEvent resDeleteEventFromJson(String str) =>
    ResDeleteEvent.fromJson(json.decode(str));

String resDeleteEventToJson(ResDeleteEvent data) => json.encode(data.toJson());

class ResDeleteEvent {
  bool status;
  String message;

  ResDeleteEvent({
    required this.status,
    required this.message,
  });

  factory ResDeleteEvent.fromJson(Map<String, dynamic> json) =>
      ResDeleteEvent(
        status: json["status"],
        message: json["message"],
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
      };
}
