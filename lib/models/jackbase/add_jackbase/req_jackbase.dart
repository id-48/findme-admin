import 'dart:convert';

ReqJackbase reqJackbaseFromJson(String str) =>
    ReqJackbase.fromJson(json.decode(str));

String reqJackbaseToJson(ReqJackbase data) => json.encode(data.toJson());

class ReqJackbase {
  String jackBase;

  ReqJackbase({
    required this.jackBase,
  });

  factory ReqJackbase.fromJson(Map<String, dynamic> json) =>
      ReqJackbase(
        jackBase: json["jackBase"],
      );

  Map<String, dynamic> toJson() =>
      {
        "jackBase": jackBase,
      };
}
