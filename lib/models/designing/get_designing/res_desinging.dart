import 'dart:convert';

ResDesigning resDesigningFromJson(String str) =>
    ResDesigning.fromJson(json.decode(str));

String resDesigningToJson(ResDesigning data) => json.encode(data.toJson());

class ResDesigning {
  bool status;
  String message;
  int totalDesigning;
  List<Designing> designing;

  ResDesigning({
    required this.status,
    required this.message,
    required this.totalDesigning,
    required this.designing,
  });

  factory ResDesigning.fromJson(Map<String, dynamic> json) =>
      ResDesigning(
        status: json["status"],
        message: json["message"],
        totalDesigning: json["totalDesigning"],
        designing: List<Designing>.from(
            json["designing"].map((x) => Designing.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalDesigning": totalDesigning,
        "designing": List<dynamic>.from(designing.map((x) => x.toJson())),
      };
}

class Designing {
  String id;
  String designing;
  DateTime createdAt;
  DateTime updatedAt;

  Designing({
    required this.id,
    required this.designing,
    required this.createdAt,
    required this.updatedAt,
  });

  factory Designing.fromJson(Map<String, dynamic> json) =>
      Designing(
        id: json["_id"],
        designing: json["designing"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "designing": designing,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
