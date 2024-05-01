import 'dart:convert';

import 'package:flutter/material.dart';

ResGetProduct resGetProductFromJson(String str) =>
    ResGetProduct.fromJson(json.decode(str));

String resGetProductToJson(ResGetProduct data) => json.encode(data.toJson());

class ResGetProduct {
  bool status;
  String message;
  int totalProduct;
  List<ProductData> product;

  ResGetProduct({
    required this.status,
    required this.message,
    required this.totalProduct,
    required this.product,
  });

  factory ResGetProduct.fromJson(Map<String, dynamic> json) =>
      ResGetProduct(
        status: json["status"],
        message: json["message"],
        totalProduct: json["totalProduct"],
        product:
        List<ProductData>.from(
            json["product"].map((x) => ProductData.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalProduct": totalProduct,
        "product": List<dynamic>.from(product.map((x) => x.toJson())),
      };
}

class ProductData {
  String id;
  String image;
  String imageNumber;
  String? productName;
  List<String> colors;
  String? colorSelect;
  List<String> designing;
  String? designSelect;
  List<String> jackBase;
  String? jackAndBaseSelect;
  List<String> footrest;
  String? footrestSelect;
  DateTime? createdAt;
  DateTime? updatedAt;
  TextEditingController? other1Con;
  TextEditingController? other2Con;
  TextEditingController? qtyCon;
  TextEditingController? priceCon;
  String? totalPrice;

  ProductData({required this.id,
    required this.image,
    required this.imageNumber,
    this.productName,
    required this.colors,
    this.colorSelect,
    required this.designing,
    this.designSelect,
    required this.jackBase,
    this.jackAndBaseSelect,
    required this.footrest,
    this.footrestSelect,
    this.createdAt,
    this.updatedAt,
    this.other1Con,
    this.other2Con,
    this.qtyCon,
    this.priceCon,
    this.totalPrice});

  factory ProductData.fromJson(Map<String, dynamic> json) =>
      ProductData(
        id: json["_id"],
        image: json["image"],
        imageNumber: json["imageNumber"],
        productName: json["productName"],
        colors: List<String>.from(json["colors"].map((x) => x)),
        colorSelect: json["colors"][0],
        designing: List<String>.from(json["designing"].map((x) => x)),
        designSelect: json["designing"][0],
        jackBase: List<String>.from(json["jackBase"].map((x) => x)),
        jackAndBaseSelect: json["jackBase"][0],
        footrest: List<String>.from(json["footrest"].map((x) => x)),
        footrestSelect: json["footrest"][0],
        createdAt: json["createdAt"] == null
            ? null
            : DateTime.parse(json["createdAt"]),
        updatedAt: json["updatedAt"] == null
            ? null
            : DateTime.parse(json["updatedAt"]),
        totalPrice: "0",
        // qtyCon: TextEditingController(text: "1"),
        // priceCon: TextEditingController(text: "0"),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "image": image,
        "imageNumber": imageNumber,
        "productName": productName,
        "colors": List<dynamic>.from(colors.map((x) => x)),
        "colorSelect": colors[0],
        "designing": List<dynamic>.from(designing.map((x) => x)),
        "designSelect": designing[0],

        "jackBase": List<dynamic>.from(jackBase.map((x) => x)),
        "jackAndBaseSelect": jackBase[0],

        "footrest": List<dynamic>.from(footrest.map((x) => x)),
        "footrestSelect": footrest[0],

        "createdAt": createdAt?.toIso8601String(),
        "updatedAt": updatedAt?.toIso8601String(),
        "totalPrice": "0",
        // "qtyCon": TextEditingController(text: "1"),
        // "priceCon": TextEditingController(text: "0"),
      };
}
