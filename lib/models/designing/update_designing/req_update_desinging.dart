import 'dart:convert';

ReqUpdateDesigning reqUpdateDesigningFromJson(String str) =>
    ReqUpdateDesigning.fromJson(json.decode(str));

String reqUpdateDesigningToJson(ReqUpdateDesigning data) =>
    json.encode(data.toJson());

class ReqUpdateDesigning {
  String designingId;
  String designing;

  ReqUpdateDesigning({
    required this.designingId,
    required this.designing,
  });

  factory ReqUpdateDesigning.fromJson(Map<String, dynamic> json) =>
      ReqUpdateDesigning(
        designingId: json["designingId"],
        designing: json["designing"],
      );

  Map<String, dynamic> toJson() => {
        "designingId": designingId,
        "designing": designing,
      };
}
