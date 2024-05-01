import 'dart:convert';

ReqUpdateJackbase reqUpdateJackbaseFromJson(String str) =>
    ReqUpdateJackbase.fromJson(json.decode(str));

String reqUpdateJackbaseToJson(ReqUpdateJackbase data) =>
    json.encode(data.toJson());

class ReqUpdateJackbase {
  String jackBaseId;
  String jackBase;

  ReqUpdateJackbase({
    required this.jackBaseId,
    required this.jackBase,
  });

  factory ReqUpdateJackbase.fromJson(Map<String, dynamic> json) =>
      ReqUpdateJackbase(
        jackBaseId: json["jackBaseId"],
        jackBase: json["jackBase"],
      );

  Map<String, dynamic> toJson() =>
      {
        "jackBaseId": jackBaseId,
        "jackBase": jackBase,
      };
}
