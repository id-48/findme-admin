// To parse this JSON data, do
//
//     final resGetAllPlace = resGetAllPlaceFromJson(jsonString);

import 'dart:convert';

ResGetAllPlace resGetAllPlaceFromJson(String str) =>
    ResGetAllPlace.fromJson(json.decode(str));

String resGetAllPlaceToJson(ResGetAllPlace data) => json.encode(data.toJson());

class ResGetAllPlace {
  bool status;
  String message;
  int totalPlace;
  List<Place> place;

  ResGetAllPlace({
    required this.status,
    required this.message,
    required this.totalPlace,
    required this.place,
  });

  factory ResGetAllPlace.fromJson(Map<String, dynamic> json) =>
      ResGetAllPlace(
        status: json["status"],
        message: json["message"],
        totalPlace: json["totalPlace"],
        place: List<Place>.from(json["place"].map((x) => Place.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalPlace": totalPlace,
        "place": List<dynamic>.from(place.map((x) => x.toJson())),
      };
}

class Place {
  String id;
  String placeName;
  String category;
  String location;
  String lattitued;
  String longtitude;
  String locatedWithin;
  String placeDescription;
  String mono;
  DateTime createdAt;
  DateTime updatedAt;

  Place({
    required this.id,
    required this.placeName,
    required this.category,
    required this.location,
    required this.lattitued,
    required this.longtitude,
    required this.locatedWithin,
    required this.placeDescription,
    required this.mono,
    required this.createdAt,
    required this.updatedAt,
  });

  factory Place.fromJson(Map<String, dynamic> json) =>
      Place(
        id: json["_id"],
        placeName: json["placeName"],
        category: json["category"],
        location: json["location"],
        lattitued: json["lattitued"],
        longtitude: json["longtitude"],
        locatedWithin: json["locatedWithin"],
        placeDescription: json["placeDescription"],
        mono: json["mono"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "placeName": placeName,
        "category": category,
        "location": location,
        "lattitued": lattitued,
        "longtitude": longtitude,
        "locatedWithin": locatedWithin,
        "placeDescription": placeDescription,
        "mono": mono,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
