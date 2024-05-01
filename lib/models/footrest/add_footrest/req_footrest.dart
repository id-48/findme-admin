import 'dart:convert';

ReqFootrest reqFootrestFromJson(String str) =>
    ReqFootrest.fromJson(json.decode(str));

String reqFootrestToJson(ReqFootrest data) => json.encode(data.toJson());

class ReqFootrest {
  String footRest;

  ReqFootrest({
    required this.footRest,
  });

  factory ReqFootrest.fromJson(Map<String, dynamic> json) =>
      ReqFootrest(
        footRest: json["footRest"],
      );

  Map<String, dynamic> toJson() =>
      {
        "footRest": footRest,
      };
}
