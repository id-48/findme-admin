import 'dart:convert';

ReqUpdateProduct reqUpdateProductFromJson(String str) =>
    ReqUpdateProduct.fromJson(json.decode(str));

String reqUpdateProductToJson(ReqUpdateProduct data) =>
    json.encode(data.toJson());

class ReqUpdateProduct {
  String productId;
  String productName;
  String imageNumber;
  String image;
  List<String> colors;
  List<String> designing;
  List<String> footrest;
  List<String> jackBase;

  ReqUpdateProduct({
    required this.productId,
    required this.imageNumber,
    required this.productName,
    required this.image,
    required this.colors,
    required this.designing,
    required this.footrest,
    required this.jackBase,
  });

  factory ReqUpdateProduct.fromJson(Map<String, dynamic> json) =>
      ReqUpdateProduct(
        productId: json["productId"],
        imageNumber: json["imageNumber"],
        productName: json["productName"],
        image: json["image"],
        colors: List<String>.from(json["colors"].map((x) => x)),
        designing: List<String>.from(json["designing"].map((x) => x)),
        footrest: List<String>.from(json["footrest"].map((x) => x)),
        jackBase: List<String>.from(json["jackBase"].map((x) => x)),
      );

  Map<String, dynamic> toJson() =>
      {
        "productId": productId,
        "imageNumber": imageNumber,
        "productName": productName,
        "image": image,
        "colors": List<dynamic>.from(colors.map((x) => x)),
        "designing": List<dynamic>.from(designing.map((x) => x)),
        "footrest": List<dynamic>.from(footrest.map((x) => x)),
        "jackBase": List<dynamic>.from(jackBase.map((x) => x)),
      };
}
