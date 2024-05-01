import 'dart:convert';

ResBilling resBillingFromJson(String str) =>
    ResBilling.fromJson(json.decode(str));

String resBillingToJson(ResBilling data) => json.encode(data.toJson());

class ResBilling {
  bool status;
  String message;
  int totalBilling;
  List<Billing> billing;

  ResBilling({
    required this.status,
    required this.message,
    required this.totalBilling,
    required this.billing,
  });

  factory ResBilling.fromJson(Map<String, dynamic> json) =>
      ResBilling(
        status: json["status"],
        message: json["message"],
        totalBilling: json["totalBilling"],
        billing:
        List<Billing>.from(json["billing"].map((x) => Billing.fromJson(x))),
      );

  Map<String, dynamic> toJson() =>
      {
        "status": status,
        "message": message,
        "totalBilling": totalBilling,
        "billing": List<dynamic>.from(billing.map((x) => x.toJson())),
      };
}

class Billing {
  String id;
  String billNo;
  String billingDate;
  String showroomId;
  String branchName;
  String name;
  String address;
  String deliveryDate;
  String instruction;
  String mobileNo;
  List<BillingDatum> billingData;
  int total;
  String paymentType;
  String advanceCash;
  int remaingCash;
  DateTime createdAt;
  DateTime updatedAt;

  Billing({
    required this.id,
    required this.billNo,
    required this.billingDate,
    required this.showroomId,
    required this.branchName,
    required this.name,
    required this.address,
    required this.deliveryDate,
    required this.instruction,
    required this.mobileNo,
    required this.billingData,
    required this.total,
    required this.paymentType,
    required this.advanceCash,
    required this.remaingCash,
    required this.createdAt,
    required this.updatedAt,
  });

  factory Billing.fromJson(Map<String, dynamic> json) =>
      Billing(
        id: json["_id"],
        billNo: json["billNo"],
        billingDate: json["billingDate"],
        showroomId: json["showroomId"],
        branchName: json["branchName"],
        name: json["name"],
        address: json["address"],
        deliveryDate: json["deliveryDate"],
        instruction: json["instruction"],
        mobileNo: json["mobileNo"],
        billingData: List<BillingDatum>.from(
            json["billingData"].map((x) => BillingDatum.fromJson(x))),
        total: json["total"],
        paymentType: json["paymentType"],
        advanceCash: json["advanceCash"].toString(),
        remaingCash: json["remaingCash"],
        createdAt: DateTime.parse(json["createdAt"]),
        updatedAt: DateTime.parse(json["updatedAt"]),
      );

  Map<String, dynamic> toJson() =>
      {
        "_id": id,
        "billNo": billNo,
        "billingDate": billingDate,
        "showroomId": showroomId,
        "branchName": branchName,
        "name": name,
        "address": address,
        "deliveryDate": deliveryDate,
        "instruction": instruction,
        "mobileNo": mobileNo,
        "billingData": List<dynamic>.from(billingData.map((x) => x.toJson())),
        "total": total,
        "paymentType": paymentType,
        "advanceCash": advanceCash,
        "remaingCash": remaingCash,
        "createdAt": createdAt.toIso8601String(),
        "updatedAt": updatedAt.toIso8601String(),
      };
}

class BillingDatum {
  String image;
  String modelNumber;
  List<String> colors;
  String colorSelect;
  List<String> designing;
  String designSelect;
  List<String> jackBase;
  String jackAndBaseSelect;
  List<String> footRest;
  String footrestSelect;
  String others1;
  String others2;
  int qty;
  int price;
  String id;

  BillingDatum({
    required this.image,
    required this.modelNumber,
    required this.colors,
    required this.colorSelect,
    required this.designing,
    required this.designSelect,
    required this.jackBase,
    required this.jackAndBaseSelect,
    required this.footRest,
    required this.footrestSelect,
    required this.others1,
    required this.others2,
    required this.qty,
    required this.price,
    required this.id,
  });

  factory BillingDatum.fromJson(Map<String, dynamic> json) =>
      BillingDatum(
        image: json["image"],
        modelNumber: json["modelNumber"],
        colors: List<String>.from(json["colors"].map((x) => x)),
        colorSelect: json["colorSelect"],
        designing: List<String>.from(json["designing"].map((x) => x)),
        designSelect: json["designSelect"],
        jackBase: List<String>.from(json["jackBase"].map((x) => x)),
        jackAndBaseSelect: json["jackAndBaseSelect"],
        footRest: List<String>.from(json["footRest"].map((x) => x)),
        footrestSelect: json["footrestSelect"],
        others1: json["others1"],
        others2: json["others2"],
        qty: json["qty"],
        price: json["price"],
        id: json["_id"],
      );

  Map<String, dynamic> toJson() =>
      {
        "image": image,
        "modelNumber": modelNumber,
        "colors": List<dynamic>.from(colors.map((x) => x)),
        "colorSelect": colorSelect,
        "designing": List<dynamic>.from(designing.map((x) => x)),
        "designSelect": designSelect,
        "jackBase": List<dynamic>.from(jackBase.map((x) => x)),
        "jackAndBaseSelect": jackAndBaseSelect,
        "footRest": List<dynamic>.from(footRest.map((x) => x)),
        "footrestSelect": footrestSelect,
        "others1": others1,
        "others2": others2,
        "qty": qty,
        "price": price,
        "_id": id,
      };
}
