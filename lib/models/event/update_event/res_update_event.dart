// To parse this JSON data, do
//
//     final resUpdateEvent = resUpdateEventFromJson(jsonString);

import 'dart:convert';

ResUpdateEvent resUpdateEventFromJson(String str) => ResUpdateEvent.fromJson(json.decode(str));

String resUpdateEventToJson(ResUpdateEvent data) => json.encode(data.toJson());

class ResUpdateEvent {
  bool status;
  String message;

  ResUpdateEvent({
    required this.status,
    required this.message,
  });

  factory ResUpdateEvent.fromJson(Map<String, dynamic> json) => ResUpdateEvent(
    status: json["status"],
    message: json["message"],
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "message": message,
  };
}
