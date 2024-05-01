import 'dart:convert';

ResJackbase resJackbaseFromJson(String str) =>
    ResJackbase.fromJson(json.decode(str));

String resJackbaseToJson(ResJackbase data) => json.encode(data.toJson());

class ResJackbase {
  bool status;
  String message;
  int totalJackBase;
  List<JackBase> jackBase;

  ResJackbase({
    required this.status,
    required this.message,
    required this.totalJackBase,
    required this.jackBase,
  });

  factory ResJackbase.fromJson(Map<String, dynamic> json) =>
      ResJackbase(
        status: json["status"],
        message: json["message"],
        totalJackBase: json["totalJackBase"],
        jackBase: List<JackBase>.from(
            json["jackBase"].map((x) => JackBase.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalJackBase": totalJackBase,
        "jackBase": List<dynamic>.from(jackBase.map((x) => x.toJson())),
      };
}

class JackBase {
  String id;
  String jackBase;
  DateTime createdAt;
  DateTime updatedAt;

  JackBase({
    required this.id,
    required this.jackBase,
    required this.createdAt,
    required this.updatedAt,
  });

  factory JackBase.fromJson(Map<String, dynamic> json) =>
      JackBase(
        id: json["_id"],
        jackBase: json["jackBase"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "jackBase": jackBase,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
