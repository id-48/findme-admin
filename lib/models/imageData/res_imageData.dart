import 'dart:convert';

ResImageData resImageDataFromJson(String str) =>
    ResImageData.fromJson(json.decode(str));

String resImageDataToJson(ResImageData data) => json.encode(data.toJson());

class ResImageData {
  bool status;
  String message;
  int totalImageData;
  List<ImageDatum> imageData;

  ResImageData({
    required this.status,
    required this.message,
    required this.totalImageData,
    required this.imageData,
  });

  factory ResImageData.fromJson(Map<String, dynamic> json) =>
      ResImageData(
        status: json["status"],
        message: json["message"],
        totalImageData: json["totalImageData"],
        imageData: List<ImageDatum>.from(
            json["imageData"].map((x) => ImageDatum.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalImageData": totalImageData,
        "imageData": List<dynamic>.from(imageData.map((x) => x.toJson())),
      };
}

class ImageDatum {
  String id;
  List<String> image;
  String imageNumber;
  DateTime createdAt;
  DateTime updatedAt;

  ImageDatum({
    required this.id,
    required this.image,
    required this.imageNumber,
    required this.createdAt,
    required this.updatedAt,
  });

  factory ImageDatum.fromJson(Map<String, dynamic> json) =>
      ImageDatum(
        id: json["_id"],
        image: List<String>.from(json["image"].map((x) => x)),
        imageNumber: json["imageNumber"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "image": List<dynamic>.from(image.map((x) => x)),
        "imageNumber": imageNumber,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}
