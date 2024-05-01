import 'dart:convert';

ReqUpdateFootrest reqUpdateFootrestFromJson(String str) =>
    ReqUpdateFootrest.fromJson(json.decode(str));

String reqUpdateFootrestToJson(ReqUpdateFootrest data) =>
    json.encode(data.toJson());

class ReqUpdateFootrest {
  String footRestId;
  String footRest;

  ReqUpdateFootrest({
    required this.footRestId,
    required this.footRest,
  });

  factory ReqUpdateFootrest.fromJson(Map<String, dynamic> json) =>
      ReqUpdateFootrest(
        footRestId: json["footRestId"],
        footRest: json["footRest"],
      );

  Map<String, dynamic> toJson() =>
      {
        "footRestId": footRestId,
        "footRest": footRest,
      };
}
