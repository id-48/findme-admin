import 'dart:convert';

ReqDesigning reqDesigningFromJson(String str) =>
    ReqDesigning.fromJson(json.decode(str));

String reqDesigningToJson(ReqDesigning data) => json.encode(data.toJson());

class ReqDesigning {
  String designing;

  ReqDesigning({
    required this.designing,
  });

  factory ReqDesigning.fromJson(Map<String, dynamic> json) =>
      ReqDesigning(
        designing: json["designing"],
      );

  Map<String, dynamic> toJson() =>
      {
        "designing": designing,
      };
}
