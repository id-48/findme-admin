// To parse this JSON data, do
//
//     final resUserWisePlaces = resUserWisePlacesFromJson(jsonString);

import 'dart:convert';

import 'package:find_me_admin/models/places/res_get_all_place.dart';

ResUserWisePlaces resUserWisePlacesFromJson(String str) => ResUserWisePlaces.fromJson(json.decode(str));

String resUserWisePlacesToJson(ResUserWisePlaces data) => json.encode(data.toJson());

class ResUserWisePlaces {
  bool status;
  String message;
  List<Place> places;

  ResUserWisePlaces({
    required this.status,
    required this.message,
    required this.places,
  });

  factory ResUserWisePlaces.fromJson(Map<String, dynamic> json) => ResUserWisePlaces(
    status: json["status"],
    message: json["message"],
    places: List<Place>.from(json["places"].map((x) => Place.fromJson(x))),
  );

  Map<String, dynamic> toJson() => {
    "status": status,
    "message": message,
    "places": List<dynamic>.from(places.map((x) => x.toJson())),
  };
}

