// To parse this JSON data, do
//
//     final reqUpdateEvent = reqUpdateEventFromJson(jsonString);

import 'dart:convert';

ReqUpdateEvent reqUpdateEventFromJson(String str) =>
    ReqUpdateEvent.fromJson(json.decode(str));

String reqUpdateEventToJson(ReqUpdateEvent data) => json.encode(data.toJson());

class ReqUpdateEvent {
  String eventId;
  String title;
  String location;
  String lattitude;
  String longtitude;
  String eventDate;
  String time;
  String description;
  String mono;

  ReqUpdateEvent({
    required this.eventId,
    required this.title,
    required this.location,
    required this.lattitude,
    required this.longtitude,
    required this.eventDate,
    required this.time,
    required this.description,
    required this.mono,
  });

  factory ReqUpdateEvent.fromJson(Map<String, dynamic> json) => ReqUpdateEvent(
        eventId: json["eventId"],
        title: json["title"],
        location: json["location"],
        lattitude: json["lattitude"],
        longtitude: json["longtitude"],
        eventDate: json["eventDate"],
        time: json["time"],
        description: json["description"],
        mono: json["mono"],
      );

  Map<String, dynamic> toJson() => {
        "eventId": eventId,
        "title": title,
        "location": location,
        "lattitude": lattitude,
        "longtitude": longtitude,
        "eventDate": eventDate,
        "time": time,
        "description": description,
        "mono": mono,
      };
}
