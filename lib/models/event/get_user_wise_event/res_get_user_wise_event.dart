// To parse this JSON data, do
//
//     final resGetUserWiseEvents = resGetUserWiseEventsFromJson(jsonString);

import 'dart:convert';

ResGetUserWiseEvents resGetUserWiseEventsFromJson(String str) =>
    ResGetUserWiseEvents.fromJson(json.decode(str));

String resGetUserWiseEventsToJson(ResGetUserWiseEvents data) =>
    json.encode(data.toJson());

class ResGetUserWiseEvents {
  bool status;
  String message;
  List<UserEvent> events;

  ResGetUserWiseEvents({
    required this.status,
    required this.message,
    required this.events,
  });

  factory ResGetUserWiseEvents.fromJson(Map<String, dynamic> json) =>
      ResGetUserWiseEvents(
        status: json["status"],
        message: json["message"],
        events: List<UserEvent>.from(
            json["events"].map((x) => UserEvent.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "events": List<dynamic>.from(events.map((x) => x.toJson())),
      };
}

class UserEvent {
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

  UserEvent({
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

  factory UserEvent.fromJson(Map<String, dynamic> json) =>
      UserEvent(
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

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "title": title,
        "location": location,
        "lattitude": lattitude,
        "longtitude": longtitude,
        "eventDate": "${eventDate.year.toString().padLeft(4, '0')}-${eventDate
            .month.toString().padLeft(2, '0')}-${eventDate.day.toString()
            .padLeft(2, '0')}",
        "time": time,
        "description": description,
        "mono": mono,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
