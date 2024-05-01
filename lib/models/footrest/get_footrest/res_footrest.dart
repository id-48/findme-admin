import 'dart:convert';

ResFootrest resFootrestFromJson(String str) =>
    ResFootrest.fromJson(json.decode(str));

String resFootrestToJson(ResFootrest data) => json.encode(data.toJson());

class ResFootrest {
  bool status;
  String message;
  int totalFootRest;
  List<FootRest> footRest;

  ResFootrest({
    required this.status,
    required this.message,
    required this.totalFootRest,
    required this.footRest,
  });

  factory ResFootrest.fromJson(Map<String, dynamic> json) =>
      ResFootrest(
        status: json["status"],
        message: json["message"],
        totalFootRest: json["totalFootRest"],
        footRest: List<FootRest>.from(
            json["footRest"].map((x) => FootRest.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalFootRest": totalFootRest,
        "footRest": List<dynamic>.from(footRest.map((x) => x.toJson())),
      };
}

class FootRest {
  String id;
  String footRest;
  DateTime createdAt;
  DateTime updatedAt;

  FootRest({
    required this.id,
    required this.footRest,
    required this.createdAt,
    required this.updatedAt,
  });

  factory FootRest.fromJson(Map<String, dynamic> json) =>
      FootRest(
        id: json["_id"],
        footRest: json["footRest"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "footRest": footRest,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
