import 'dart:convert';

ReqAddProduct reqAddProductFromJson(String str) =>
    ReqAddProduct.fromJson(json.decode(str));

String reqAddProductToJson(ReqAddProduct data) => json.encode(data.toJson());

class ReqAddProduct {
  String imageNumber;
  String productName;
  String image;
  List<dynamic> colors;
  List<dynamic> designing;
  List<dynamic> footrest;
  List<dynamic> jackBase;

  ReqAddProduct({
    required this.imageNumber,
    required this.productName,
    required this.image,
    required this.colors,
    required this.designing,
    required this.footrest,
    required this.jackBase,
  });

  factory ReqAddProduct.fromJson(Map<String, dynamic> json) =>
      ReqAddProduct(
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
        "imageNumber": imageNumber,
        "productName": productName,
        "image": image,
        "colors": List<dynamic>.from(colors.map((x) => x)),
        "designing": List<dynamic>.from(designing.map((x) => x)),
        "footrest": List<dynamic>.from(footrest.map((x) => x)),
        "jackBase": List<dynamic>.from(jackBase.map((x) => x)),
      };
}
