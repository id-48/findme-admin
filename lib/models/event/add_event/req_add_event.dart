// To parse this JSON data, do
//
//     final ReqAddEvent = ReqAddEventFromJson(jsonString);

import 'dart:convert';

ReqAddEvent reqAddEventFromJson(String str) => ReqAddEvent.fromJson(json.decode(str));

String reqAddEventToJson(ReqAddEvent data) => json.encode(data.toJson());

class ReqAddEvent {
  String title;
  String location;
  String lattitude;
  String longtitude;
  String eventDate;
  String time;
  String description;
  String mono;

  ReqAddEvent({
    required this.title,
    required this.location,
    required this.lattitude,
    required this.longtitude,
    required this.eventDate,
    required this.time,
    required this.description,
    required this.mono,
  });

  factory ReqAddEvent.fromJson(Map<String, dynamic> json) => ReqAddEvent(
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
