// To parse this JSON data, do
//
//     final resAllEvents = resAllEventsFromJson(jsonString);

import 'dart:convert';

ResAllEvents resAllEventsFromJson(String str) => ResAllEvents.fromJson(json.decode(str));

String resAllEventsToJson(ResAllEvents data) => json.encode(data.toJson());

class ResAllEvents {
  bool status;
  String message;
  int totalEvent;
  List<Event> event;

  ResAllEvents({
    required this.status,
    required this.message,
    required this.totalEvent,
    required this.event,
  });

  factory ResAllEvents.fromJson(Map<String, dynamic> json) => ResAllEvents(
    status: json["status"],
    message: json["message"],
    totalEvent: json["totalEvent"],
    event: List<Event>.from(json["event"].map((x) => Event.fromJson(x))),
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "message": message,
    "totalEvent": totalEvent,
    "event": List<dynamic>.from(event.map((x) => x.toJson())),
  };
}

class Event {
  String id;
  String title;
  String location;
  String lattitude;
  String longtitude;
  DateTime eventDate;
  String time;
  String description;
  String mono;
  DateTime createdAt;
  DateTime updatedAt;

  Event({
    required this.id,
    required this.title,
    required this.location,
    required this.lattitude,
    required this.longtitude,
    required this.eventDate,
    required this.time,
    required this.description,
    required this.mono,
    required this.createdAt,
    required this.updatedAt,
  });

  factory Event.fromJson(Map<String, dynamic> json) => Event(
    id: json["_id"],
    title: json["title"],
    location: json["location"],
    lattitude: json["lattitude"],
    longtitude: json["longtitude"],
    eventDate: DateTime.parse(json["eventDate"]),
    time: json["time"],
    description: json["description"],
    mono: json["mono"],
    createdAt: DateTime.parse(json["createdAt"]),
    updatedAt: DateTime.parse(json["updatedAt"]),
  );

  Map<String, dynamic> toJson() => {
    "_id": id,
    "title": title,
    "location": location,
    "lattitude": lattitude,
    "longtitude": longtitude,
    "eventDate": "${eventDate.year.toString().padLeft(4, '0')}-${eventDate.month.toString().padLeft(2, '0')}-${eventDate.day.toString().padLeft(2, '0')}",
    "time": time,
    "description": description,
    "mono": mono,
    "createdAt": createdAt.toIso8601String(),
    "updatedAt": updatedAt.toIso8601String(),
  };
}
